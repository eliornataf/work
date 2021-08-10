#include "../inc/dispatcher_task.hpp" // Dispatcher Task Header

using namespace advcpp;

DispatcherTask::DispatcherTask(std::shared_ptr<ISubscriber> a_subscriber, std::shared_ptr<Event> a_event, std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> a_encoderBlockingBoundedQueue)
: m_subscriber(a_subscriber)
, m_event(a_event)
, m_encoderBlockingBoundedQueue(a_encoderBlockingBoundedQueue)
{
}

void DispatcherTask::run()
{
    m_subscriber->Notify(m_event, m_encoderBlockingBoundedQueue);
}