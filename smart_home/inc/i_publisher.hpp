#ifndef I_PUBLISHER_HPP
#define I_PUBLISHER_HPP

#include <memory> // std::shared_ptr
#include "blocking_bounded_queue.hpp" // Blocking Bounded Queue
#include "event.hpp" // Event Header

namespace advcpp {

class IPublisher {  
public:
    virtual ~IPublisher() = default;

    virtual void Publish(const std::string &a_event, std::shared_ptr<BlockingBoundedQueue<std::shared_ptr<Event>>> a_decoderBlockingBoundedQueue) = 0;
};

} // advcpp

#endif // I_PUBLISHER_HPP