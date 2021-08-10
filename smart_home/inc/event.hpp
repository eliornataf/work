#ifndef EVENT_HPP
#define EVENT_HPP

#include <string> // std::string
#include "location.hpp" // Location Header
#include "timestamp.hpp" // Timestamp Header

namespace advcpp {

class Event {
public:
    Event(const std::string &a_type, const std::string &a_payload, const Location &a_location);
    Event(const std::string &a_type, const Timestamp &a_timestamp, const std::string &a_payload, const Location &a_location);
    ~Event() = default;

    Event(const Event &a_other) = default;
    Event &operator=(const Event &a_other) = default;

    bool operator==(const Event &a_other) const;
    bool operator!=(const Event &a_other) const;

    std::string GetType() const;
    Timestamp GetTimestamp() const;
    std::string GetPayload() const;
    Location GetLocation() const noexcept;

private:
    std::string m_type;
    Timestamp m_timestamp;
    std::string m_payload;
    Location m_location;
};

} // advcpp

#endif // EVENT_HPP
