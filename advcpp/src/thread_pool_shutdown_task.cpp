#include "thread_pool_shutdown_task.hpp" // Thread Pool Shutdown Task Header

using namespace advcpp;

ThreadPoolShutdownTask::ThreadPoolShutdownTask(std::shared_ptr<Barrier> a_barrier)
: m_barrier(a_barrier)
{
}

void ThreadPoolShutdownTask::run()
{
    m_barrier->Wait();
}
