#ifndef SUBSCRIBERS_MANAGER_HPP
#define SUBSCRIBERS_MANAGER_HPP

#include <list> // std::list
#include <memory> // std::shared_ptr
#include <set> // std::set
#include <string> // std::string
#include <unordered_map> // std::unordered_map
#include "key.hpp" // Key Header
#include "i_subscribe.hpp" // I Subscribe Header
#include "i_subscriber.hpp" // I Subscriber Header
#include "location.hpp" // Location Header

namespace advcpp {

class SubscribersManager : public ISubscribe {
public:
    SubscribersManager() = default;
    ~SubscribersManager() = default;

    SubscribersManager(const SubscribersManager &a_other) = default;
    SubscribersManager &operator=(const SubscribersManager &a_other) = default;

    virtual void Subscribe(std::shared_ptr<ISubscriber> a_subscriber, const std::string &a_type, const Location &a_location) override;
    virtual void Unsubscribe(std::shared_ptr<ISubscriber> a_subscriber, const std::string &a_type, const Location &a_location) override;

    std::set<std::shared_ptr<ISubscriber>> GetEventRelevantSubscribers(std::shared_ptr<Event> a_event);

private:
    void CreateNewEventTypeSubscriberList(const std::string &a_type, const Location &a_location);

    std::unordered_map<Key, std::list<std::shared_ptr<ISubscriber>>, KeyHash, KeyEqual> m_unorderedMap;
};

} // advcpp

#endif // SUBSCRIBERS_MANAGER_HPP