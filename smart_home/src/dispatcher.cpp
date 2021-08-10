#include "../inc/dispatcher_task.hpp" // Dispatcher Task Header
#include "../inc/dispatcher.hpp" // Dispatcher Header
#include "../inc/runnable.hpp" // Runnable Header

using namespace advcpp;

Dispatcher::Dispatcher()
: m_threadPool(BLOCKING_BOUNDED_QUEUE_SIZE)
{
}

void Dispatcher::Dispatch(std::set<std::shared_ptr<ISubscriber>> a_set, std::shared_ptr<Event> a_event, std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> a_encoderBlockingBoundedQueue)
{
    std::for_each(a_set.begin(), a_set.end(), [&](std::shared_ptr<ISubscriber> a_subscriber) 
    {
        std::shared_ptr<Runnable> dispatcherTask(new DispatcherTask(a_subscriber, a_event, a_encoderBlockingBoundedQueue));
        
        m_threadPool.Submit(dispatcherTask);
    });
}