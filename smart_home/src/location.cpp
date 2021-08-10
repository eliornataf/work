#include "../inc/location.hpp" // Location Header

using namespace advcpp;

Location::Location()
{
}

Location::Location(const unsigned int a_floor, const unsigned int a_room)
: m_floor(a_floor)
, m_room(a_room)
{
}

bool Location::operator==(const Location &a_other) const noexcept
{
    return (m_floor == a_other.m_floor && m_room == a_other.m_room);
}

bool Location::operator!=(const Location &a_other) const noexcept
{
    return (m_floor != a_other.m_floor || m_room != a_other.m_room);
}

unsigned int Location::GetFloor() const noexcept
{
    return m_floor;
}

unsigned int Location::GetRoom() const noexcept
{
    return m_room;
}

std::string Location::GetCompleteLocation() const
{
    return std::string(std::to_string(m_floor) + DELIMETER + std::to_string(m_room));
}
