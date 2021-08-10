#ifndef ENCODER_HPP
#define ENCODER_HPP

#include <memory> // std::shared_ptr
#include <string> // std::string
#include "event.hpp" // Event Header
#include "i_encoder.hpp" // I Encoder

namespace advcpp {

class Encoder : public IEncoder {
public:  
    Encoder() = default;
    ~Encoder() = default;

    Encoder(const Encoder &a_other) = default;
    Encoder &operator=(const Encoder &a_other) = default;

    virtual std::string Encode(const std::shared_ptr<Event> &a_event) override;

private:
    static constexpr char EVENT_PARTS_DELIMITER = '|';
    static constexpr char NEW_LINE = '\n';
};

} // advcpp

#endif // ENCODER_HPP