#ifndef I_SUBSCRIBE_HPP
#define I_SUBSCRIBE_HPP

#include <memory> // std::shared_ptr
#include "i_subscriber.hpp" // I Subscriber Header
#include "location.hpp" // Subscriber Location Header

namespace advcpp {

class ISubscribe {
public:
    virtual ~ISubscribe() = default;

    virtual void Subscribe(std::shared_ptr<ISubscriber> a_subscriber, const std::string &a_type, const Location &a_location) = 0;
    virtual void Unsubscribe(std::shared_ptr<ISubscriber> a_subscriber, const std::string &a_type, const Location &a_location) = 0;
};

} // advcpp

#endif // I_SUBSCRIBE_HPP