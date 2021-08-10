#include "thread_pool_infinty_task.hpp" // Thread Pool Infinty Task Header

using namespace advcpp;

ThreadPoolInfinityTask::ThreadPoolInfinityTask(std::shared_ptr<Latch> a_latch)
: m_latch(a_latch)
{
}

void ThreadPoolInfinityTask::run()
{
    m_latch->CountDown();

    while (true)
    {
       // do nothing 
    }
}
