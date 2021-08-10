#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <string> // std::string

namespace advcpp {

class Location {
public:
    Location();
    Location(const unsigned int a_floor, const unsigned int a_room);
    ~Location() = default;

    Location(const Location &a_other) = default;
    Location &operator=(const Location &a_other) = default;

    bool operator==(const Location &a_other) const noexcept;
    bool operator!=(const Location &a_other) const noexcept;

    unsigned int GetFloor() const noexcept;
    unsigned int GetRoom() const noexcept;
    std::string GetCompleteLocation() const;

private:
    static constexpr char DELIMETER = ' ';

private:
    unsigned int m_floor;
    unsigned int m_room;
};

} // advcpp

#endif // LOCATION_HPP