#include "../inc/thread_pool_task_executer.hpp" // Thread Pool Task Header

using namespace advcpp;

ThreadPoolTaskExecuter::ThreadPoolTaskExecuter(BlockingBoundedQueue<std::shared_ptr<Runnable>> &a_blockingBoundedQueue, std::shared_ptr<Latch> a_latchImmediately)
: m_blockingBoundedQueue(a_blockingBoundedQueue)
, m_latchImmediately(a_latchImmediately)
{
}

void ThreadPoolTaskExecuter::run()
{
    while (true)
    {   
        if (0 != m_latchImmediately->GetAtomicValueSize())
        {
            m_latchImmediately->CountDown();
            break;
        }

        std::shared_ptr<Runnable> currentTask;
        
        if (!m_blockingBoundedQueue.Dequeue(currentTask))
        {
            break;
        }

        try
        {
            currentTask->run();
        }
        catch (...)
        {
            // do noting
        }
    }
}
