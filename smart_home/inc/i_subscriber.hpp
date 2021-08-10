#ifndef I_SUBSCRIBER_HPP
#define I_SUBSCRIBER_HPP

#include <memory> // std::shared_ptr
#include "blocking_bounded_queue.hpp" // Blocking Bounded Queue
#include "event.hpp" // Event Header

namespace advcpp {

class ISubscriber {
public:
    virtual ~ISubscriber() = default;
    
    virtual void Notify(std::shared_ptr<Event> a_event, std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> a_encoderBlockingBoundedQueue) = 0;
};

} // advcpp

#endif // I_SUBSCRIBER_HPP