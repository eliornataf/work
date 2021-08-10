#include "../inc/event.hpp" // Event Header

using namespace advcpp;

Event::Event(const std::string &a_type, const std::string &a_payload, const Location &a_location)
: m_type(a_type)
, m_timestamp()
, m_payload(a_payload)
, m_location(a_location)
{
}

Event::Event(const std::string &a_type, const Timestamp &a_timestamp, const std::string &a_payload, const Location &a_location)
: m_type(a_type)
, m_timestamp(a_timestamp)
, m_payload(a_payload)
, m_location(a_location)
{
}

bool Event::operator==(const Event &a_other) const
{
    return (m_type == a_other.m_type && m_timestamp == a_other.m_timestamp && m_payload == a_other.m_payload && m_location == a_other.m_location);
}

bool Event::operator!=(const Event &a_other) const
{
    return (m_type != a_other.m_type || m_timestamp != a_other.m_timestamp || m_payload != a_other.m_payload || m_location != a_other.m_location);
}

std::string Event::GetType() const
{
    return m_type;
}

Timestamp Event::GetTimestamp() const
{
    return m_timestamp;
}

std::string Event::GetPayload() const
{
    return m_payload;
}

Location Event::GetLocation() const noexcept
{
    return m_location;
}