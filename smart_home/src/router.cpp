#include <set> // std::set
#include "../inc/router.hpp" // Router Header

using namespace advcpp;

Router::Router()
: m_subscriberManager(nullptr)
, m_dispatcher()
{
}

void Router::InitializeSubscriberManager(std::shared_ptr<SubscribersManager> a_subscriberManager)
{
    m_subscriberManager = a_subscriberManager;
}

void Router::Invoke(std::shared_ptr<Event> a_event, std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> a_blockingBoundedQueue)
{
    std::set<std::shared_ptr<ISubscriber>> eventRelevantSubscribers = m_subscriberManager->GetEventRelevantSubscribers(a_event);
    m_dispatcher.Dispatch(eventRelevantSubscribers, a_event, a_blockingBoundedQueue);
}