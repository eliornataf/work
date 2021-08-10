#ifndef THREAD_GROUP_HPP
#define THREAD_GROUP_HPP

#include <algorithm> // std::for_each
#include <cassert> // assert
#include <exception> // std::exception
#include <iterator> // std::iterator
#include <list> // std::list
#include <memory> // std::shared_ptr
#include <stdexcept> // std::runtime_error
#include <string> // std::to_string
#include <pthread.h> // pthread_t

#include "runnable.hpp" // Runnable Header
#include "thread.hpp" // Thread Header

namespace advcpp {

template <typename Policy> 
class ThreadGroup {
public:
    ThreadGroup(std::shared_ptr<Runnable> a_runnable, const size_t a_numberOfThreads, const Policy &a_userPolicy);
    ~ThreadGroup() = default;

    ThreadGroup(const ThreadGroup &a_other) = delete;
    ThreadGroup &operator=(const ThreadGroup &a_other) = delete;

    void Join();
    void Detach();
    void Cancel(const bool a_isWaitingAfterCancelNecessary);

    void Add(const size_t a_numberOfThreads);
    size_t Remove(const size_t a_numberOfThreads);

    size_t NumberOfThreads() const;
    
private:
    void AddThreads(const size_t a_numberOfThreads);
    size_t RemoveDoneThreads();

    std::list<std::shared_ptr<Thread<Policy>>> m_threadList;
    std::shared_ptr<Runnable> m_runnable;
    Policy m_userPolicy;
};

#include "inl/thread_group.hxx" // Thread Group Inline

} // advcpp

#endif // THREAD_GROUP_HPP
