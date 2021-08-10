#ifndef THREAD_POOL_HPP
#define THREAD_POOL_HPP

#include <memory> // std::shared_ptr
#include <mutex> // std::mutex
#include <stdexcept> // std::runtime_error
#include <thread> // std::lock_guard

#include "atomic_flag.hpp" // Atomic Flag Header
#include "blocking_bounded_queue.hpp" // Blocking Bounded Queue
#include "latch.hpp" // Latch Header
#include "runnable.hpp" // Runnable Header
#include "thread.hpp" // Thread Header
#include "thread_group.hpp" // Thread Group Header
#include "thread_pool_empty_task.hpp" // Thread Pool Empty Task Header
#include "thread_pool_infinty_task.hpp" // Thread Pool Infinty Task Header
#include "thread_pool_task_executer.hpp" // Thread Pool Task Header

namespace advcpp {

class ThreadPool {
public:
    ThreadPool(const size_t a_blockingBoundedQueueCapacity, const size_t a_numberOfThreads = std::thread::hardware_concurrency());
    ~ThreadPool();

    ThreadPool(const ThreadPool &a_other) = delete;
    ThreadPool &operator=(const ThreadPool &a_other) = delete;

    void Submit(std::shared_ptr<Runnable> a_task);

    void AddThreads(const size_t a_numberOfThreads);

    void ShutDown();
    void ShutDownImmediately();

    void RemoveThreads(const size_t a_numberOfThreads);
private:
    static size_t CheckBlockingBoundedQueueCapacity(const size_t a_blockingBoundedQueueCapacity);

private:
    static constexpr size_t ONE_SHUTDOWN_TASK = 1;

    void AddInfinityTaskToFreeWaitingThread(const size_t a_numberOfTests);
    void AddEmptyTaskToFreeWaitingThread(const size_t a_numberOfTests);

    BlockingBoundedQueue<std::shared_ptr<Runnable>> m_blockingBoundedQueue;
    AtomicFlag m_isShutDownOn;
    std::shared_ptr<Latch> m_latchInfinityTask;
    std::shared_ptr<Latch> m_latchImmediately;
    std::mutex m_mutex;
    ThreadGroup<JoinPolicy> m_threadGroup;
};

} // advcpp

#endif // THREAD_POOL_HPP