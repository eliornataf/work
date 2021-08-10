#include <algorithm> // std::for_each
#include "../inc/subscribers_manager.hpp" // Subscibers Manager Header

using namespace advcpp;

void SubscribersManager::Subscribe(std::shared_ptr<ISubscriber> a_subscriber, const std::string &a_type, const Location &a_location)
{
    if (m_unorderedMap.find({a_type, a_location}) == m_unorderedMap.end())
    {
        CreateNewEventTypeSubscriberList(a_type, a_location);
    }

    m_unorderedMap.at({a_type, a_location}).push_back(a_subscriber);
}

void SubscribersManager::Unsubscribe(std::shared_ptr<ISubscriber> a_subscriber, const std::string &a_type, const Location &a_location)
{
    if (m_unorderedMap.find({a_type, a_location}) == m_unorderedMap.end())
    {
        return;
    }

    m_unorderedMap.at({a_type, a_location}).remove(a_subscriber);
}

std::set<std::shared_ptr<ISubscriber>> SubscribersManager::GetEventRelevantSubscribers(std::shared_ptr<Event> a_event)
{
    std::list<std::shared_ptr<ISubscriber>> relevantSubscriberslist = m_unorderedMap.at({a_event->GetType(), a_event->GetLocation()});
    std::set<std::shared_ptr<ISubscriber>> relevantSubscribersSet;

    std::for_each(relevantSubscriberslist.begin(), relevantSubscriberslist.end(), [&](std::shared_ptr<ISubscriber> a_subscriber)
    {
        relevantSubscribersSet.insert(a_subscriber);
    });

    return relevantSubscribersSet;
}

////////////////////////// Private Methods ////////////////////////

void SubscribersManager::CreateNewEventTypeSubscriberList(const std::string &a_type, const Location &a_location)
{
    m_unorderedMap.insert({{a_type, a_location}, std::list<std::shared_ptr<ISubscriber>>()});
}
