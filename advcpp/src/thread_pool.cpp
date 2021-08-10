#include "thread_pool.hpp" // Thread Pool Header

using namespace advcpp;

ThreadPool::ThreadPool(const size_t a_blockingBoundedQueueCapacity, const size_t a_numberOfThreads)
: m_blockingBoundedQueue(CheckBlockingBoundedQueueCapacity(a_blockingBoundedQueueCapacity))
, m_isShutDownOn()
, m_latchInfinityTask(new Latch())
, m_latchImmediately(new Latch())
, m_mutex()
, m_threadGroup(std::shared_ptr<Runnable>(new ThreadPoolTaskExecuter(m_blockingBoundedQueue, m_latchImmediately)), a_numberOfThreads, JoinPolicy())
{
}

ThreadPool::~ThreadPool()
{
    if (!m_isShutDownOn.Get())
    {
        ShutDown();
    }
}

void ThreadPool::Submit(std::shared_ptr<Runnable> a_task)
{
    if (!m_isShutDownOn.Get() && a_task)
    {
        m_blockingBoundedQueue.Enqueue(a_task);
    }
}

void ThreadPool::AddThreads(const size_t a_numberOfThreads)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    if (!m_isShutDownOn.Get())
    {
        m_threadGroup.Add(a_numberOfThreads);
    }
}

void ThreadPool::ShutDown()
{
    if (!m_isShutDownOn.Get()) 
    {
        size_t numberOfThreads = m_threadGroup.NumberOfThreads();

        m_isShutDownOn.Set(); 

        m_latchInfinityTask->SetAtomicValue(numberOfThreads);
        AddInfinityTaskToFreeWaitingThread(numberOfThreads);
        m_latchInfinityTask->Wait();

        m_threadGroup.Remove(numberOfThreads);
    }
}

void ThreadPool::ShutDownImmediately()
{
    if (!m_isShutDownOn.Get()) 
    {
        size_t numberOfThreads = m_threadGroup.NumberOfThreads();

        m_isShutDownOn.Set();

        AddEmptyTaskToFreeWaitingThread(std::min(m_blockingBoundedQueue.Capacity(), numberOfThreads));
        
        m_latchImmediately->SetAtomicValue(numberOfThreads);
        m_latchImmediately->Wait();

        m_threadGroup.Remove(numberOfThreads);
    }
}

void ThreadPool::RemoveThreads(const size_t a_numberOfThreads)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    if (!m_isShutDownOn.Get())
    {
        size_t numberOfThreadsToRemove = std::min(a_numberOfThreads, m_threadGroup.NumberOfThreads());

        AddEmptyTaskToFreeWaitingThread(numberOfThreadsToRemove);

        m_latchImmediately->SetAtomicValue(numberOfThreadsToRemove);
        m_latchImmediately->Wait();

        m_threadGroup.Remove(numberOfThreadsToRemove);
    }
}

//////////////////////// Private Methods /////////////////////////

void ThreadPool::AddInfinityTaskToFreeWaitingThread(const size_t a_numberOfTests)
{
    std::shared_ptr<Runnable> infintyTask(new ThreadPoolInfinityTask(m_latchInfinityTask));

    for (size_t i = 0;i < a_numberOfTests;++i)
    {
        m_blockingBoundedQueue.Enqueue(infintyTask);
    }
}

void ThreadPool::AddEmptyTaskToFreeWaitingThread(const size_t a_numberOfTests)
{
    std::shared_ptr<Runnable> emptyTask(new ThreadPoolEmptyTask());

    for (size_t i = 0;i < a_numberOfTests;++i)
    {
        m_blockingBoundedQueue.Enqueue(emptyTask);
    }
}

//////////////////////////// Static Methods ////////////////////////////

size_t ThreadPool::CheckBlockingBoundedQueueCapacity(const size_t a_blockingBoundedQueueCapacity)
{
    if (0 == a_blockingBoundedQueueCapacity)
    {
        throw std::runtime_error("blocking bounded queue capacity is zero");
    }

    return a_blockingBoundedQueueCapacity;
}