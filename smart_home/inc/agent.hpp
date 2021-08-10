#ifndef AGENT_HPP
#define AGENT_HPP

#include <string> // std::string
#include "location.hpp" // Subscriber Location Header

namespace advcpp {

class Agent {
public:
    Agent(const std::string &a_id, const std::string &a_type, const Location &a_location, const std::string &a_log, const std::string &a_config);
    virtual ~Agent() = default;

    Agent(const Agent &a_other) = default;
    Agent &operator=(const Agent &a_other) = default;

    void Connect();
    void Disconnect();

    std::string GetID() const;
    std::string GetType() const;
    Location GetLocation() const;
    std::string GetLog() const;
    std::string GetConfig() const;
    bool IsConnected() const;

protected:
    std::string m_id;
    std::string m_type;
    Location m_location;
    std::string m_log;
    std::string m_config;
    bool m_isConnected;
};

} // advcpp

#endif // AGENT_HPP