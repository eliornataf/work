#ifndef I_ENCODER_HPP
#define I_ENCODER_HPP

#include <memory> // std::shared_ptr
#include <string> // std::string
#include "event.hpp" // Event Header

namespace advcpp {

class IEncoder {  
public:
    virtual ~IEncoder() = default;

    virtual std::string Encode(const std::shared_ptr<Event> &a_event) = 0;
};

} // advcpp

#endif // I_ENCODER_HPP