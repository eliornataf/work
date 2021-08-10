#include "../inc/invoke_task.hpp" // Invoke Task Header

using namespace advcpp;

InvokeTask::InvokeTask(std::shared_ptr<Router> a_router, std::shared_ptr<Event> a_event, std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> a_encoderBlockingBoundedQueue)
: m_router(a_router)
, m_event(a_event)
, m_encoderBlockingBoundedQueue(a_encoderBlockingBoundedQueue)
{
}

void InvokeTask::run()
{
    m_router->Invoke(m_event, m_encoderBlockingBoundedQueue);
}
