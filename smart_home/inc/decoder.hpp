#ifndef DECODER_HPP
#define DECODER_HPP

#include <memory> // std::shared_ptr
#include <string> // std::string
#include "event.hpp" // Event Header
#include "i_decoder.hpp" // I Decoder
#include "timestamp.hpp" // TimeStamp Header

namespace advcpp {

class Decoder : public IDecoder {
public:
    Decoder() = default;
    ~Decoder() = default;

    Decoder(const Decoder &a_other) = default;
    Decoder &operator=(const Decoder &a_other) = default;

    virtual std::shared_ptr<Event> Decode(const std::string &a_event) override;

private:
    static constexpr char EVENT_PARTS_DELIMITER = '|';
    static constexpr int DUMMY = 0;
    static constexpr char PARTS_PARAMETERS_DELIMITER = ' ';

    enum EventPart {
        TYPE = 0,
        TIMESTAMP,
        PAYLOAD,
        LOCATION
    };

    enum TimestampPart {
        SECOND = 0,
        MINUTE,
        HOUR,
        DAY,
        MONTH,
        YEAR
    };

    enum LocationPart {
        FLOOR = 0,
        ROOM
    };

private:
    Timestamp ConvetStringToTimeStamp(const std::string &a_string);
    Location ConvetStringToLocation(const std::string &a_string);
};

} // advcpp

#endif // DECODER_HPP