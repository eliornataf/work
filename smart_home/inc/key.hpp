#ifndef KEY_HPP
#define KEY_HPP

#include <string> // std::string
#include "location.hpp" // Location Header

namespace advcpp {

struct Key {
    std::string m_type;
    Location m_location;
};

struct KeyHash {
    size_t operator()(const Key &a_key) const
    {
        return std::hash<std::string>()(a_key.m_type) ^ 
            (std::hash<unsigned int>()( a_key.m_location.GetFloor() ^
                a_key.m_location.GetRoom()) << 1);
    }
};
 
struct KeyEqual {
    bool operator()(const Key &lhs, const Key &rhs) const
    {
        return lhs.m_type == rhs.m_type && lhs.m_location == rhs.m_location;
    }
};

} // advcpp

#endif // KEY_HPP
