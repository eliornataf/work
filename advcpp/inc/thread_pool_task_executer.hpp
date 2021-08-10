#ifndef THREAD_POOL_TASK_EXECUTER_HPP
#define THREAD_POOL_TASK_EXECUTER_HPP

#include <memory> // std::shared_ptr

#include "blocking_bounded_queue.hpp" // Blocking Bounded Queue
#include "latch.hpp" // Latch Header
#include "runnable.hpp" // Runnable

namespace advcpp {

class ThreadPoolTaskExecuter : public Runnable {
public:
    ThreadPoolTaskExecuter(BlockingBoundedQueue<std::shared_ptr<Runnable>> &a_blockingBoundedQueue, std::shared_ptr<Latch> a_latchImmediately);
    ~ThreadPoolTaskExecuter() = default;

    ThreadPoolTaskExecuter(const ThreadPoolTaskExecuter &a_other) = delete;
    ThreadPoolTaskExecuter &operator=(const ThreadPoolTaskExecuter &a_other) = delete;
    
    virtual void run() override;

private:
    BlockingBoundedQueue<std::shared_ptr<Runnable>> &m_blockingBoundedQueue;
    std::shared_ptr<Latch> m_latchImmediately;
};

} // advcpp

#endif // THREAD_POOL_TASK_EXECUTER_HPP
