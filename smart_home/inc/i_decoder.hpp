#ifndef I_DECODER_HPP
#define I_DECODER_HPP

#include <memory> // std::shared_ptr
#include <string> // std::string
#include "event.hpp" // Event Header

namespace advcpp {

class IDecoder {  
public:
    virtual ~IDecoder() = default;

    virtual std::shared_ptr<Event> Decode(const std::string &a_event) = 0;
};

} // advcpp

#endif // I_DECODER_HPP