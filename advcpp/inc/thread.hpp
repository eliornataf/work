#ifndef THREAD_HPP
#define THREAD_HPP

#include <cassert> // assert
#include <cxxabi.h> // abi::__forced_unwind
#include <condition_variable> // std::condition_variable
#include <iterator> // std::iterator
#include <mutex> // std::mutex
#include <memory> // std::shared_ptr
#include <stdexcept> // std::runtime_error
#include <pthread.h> // pthread_t

#include "atomic_flag.hpp" // Atomic Flag Header
#include "barrier.hpp" // Barrier Header
#include "runnable.hpp" // Runnable Header

namespace advcpp {

class SyncPoint {
public:
    SyncPoint() : m_isAliveThread(true) {};
    ~SyncPoint() = default;

    SyncPoint(const SyncPoint &a_other) = delete;   
    SyncPoint &operator=(const SyncPoint &a_other) = delete;   

    void On() {m_isAliveThread.Set();}
    void Off() {m_isAliveThread.Clear();}

    bool Get() const {return m_isAliveThread.Get();}

private:
    AtomicFlag m_isAliveThread;
};

template <typename Policy> 
class Thread {
public:
    Thread(std::shared_ptr<Runnable> a_runnable, const Policy &a_userPolicy);
    ~Thread();

    Thread(const Thread &a_other) = delete;
    Thread &operator=(const Thread &a_other) = delete;

    void Join();
    void Detach();
    void Cancel(const bool a_isWaitingAfterCancelNecessary = false);

    bool IsThreadAlive();

private:
    static void *ThreadFunction(void *a_arg);

    static constexpr unsigned int PTHREAD_SUCCESS = 0; 
    static constexpr unsigned int NUMBER_OF_THREADS_WHICH_WILL_PARTICIPATE_THE_BARRIER = 2; 

    pthread_t m_thread;
    Policy m_userPolicy;
    AtomicFlag m_isJoinableOrDetachableOrCancelable;
    Barrier m_barrier;
    std::shared_ptr<Runnable> m_runnable;
    std::shared_ptr<SyncPoint> m_syncPoint;
};

struct JoinPolicy {
    void OnDestruction(Thread<JoinPolicy> &a_thread) 
    {
        a_thread.Join();
    }
};

struct DetachPolicy {
    void OnDestruction(Thread<DetachPolicy> &a_thread) 
    {
        a_thread.Detach();
    }
};

struct CancelPolicy {
    void OnDestruction(Thread<CancelPolicy> &a_thread) 
    {
        a_thread.Cancel();
    }
};

#include "inl/thread.hxx" // Thread Inline

} // advcpp


#endif // THREAD_HPP
