#ifndef ROUTER_HPP
#define ROUTER_HPP

#include <memory> // std::shared_ptr
#include <string> // std::string
#include "blocking_bounded_queue.hpp" // Blocking Bounded Queue
#include "event.hpp" // Event Header
#include "dispatcher.hpp" // Dispatcher Header
#include "subscribers_manager.hpp" // Subscribers Manager Header
#include "thread_pool.hpp"

namespace advcpp {

class Router {
public:
    Router();
    ~Router() = default;

    Router(const Router &a_other) = delete;
    Router &operator=(const Router &a_other) = delete;

    void InitializeSubscriberManager(std::shared_ptr<SubscribersManager> a_subscriberManager);

    void Invoke(std::shared_ptr<Event> a_event, std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> a_blockingBoundedQueue);

private:
    std::shared_ptr<SubscribersManager> m_subscriberManager;
    Dispatcher m_dispatcher;
};

} // advcpp

#endif // ROUTER_HPP