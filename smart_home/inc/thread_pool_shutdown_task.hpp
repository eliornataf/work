#ifndef THREAD_POOL_SHUTDOWN_TASK_HPP
#define THREAD_POOL_SHUTDOWN_TASK_HPP

#include <memory> // std::shared_ptr
#include "barrier.hpp" // Barrier Header
#include "blocking_bounded_queue.hpp" // Blocking Bounded Queue
#include "runnable.hpp" // Runnable

namespace advcpp {

class ThreadPoolShutdownTask : public Runnable {
public:
    explicit ThreadPoolShutdownTask(std::shared_ptr<Barrier> a_barrier);
    ~ThreadPoolShutdownTask() = default;

    ThreadPoolShutdownTask(const ThreadPoolShutdownTask &a_other) = delete;
    ThreadPoolShutdownTask &operator=(const ThreadPoolShutdownTask &a_other) = delete;
    
    virtual void run() override;

private:
    std::shared_ptr<Barrier> m_barrier;
};

} // advcpp

#endif // THREAD_POOL_SHUTDOWN_TASK_HPP
