#include "../inc/agent.hpp" // Agent Header

using namespace advcpp;

Agent::Agent(const std::string &a_id, const std::string &a_type, const Location &a_location, const std::string &a_log, const std::string &a_config)
: m_id(a_id)
, m_type(a_type)
, m_location(a_location)
, m_log(a_log)
, m_config(a_config)
, m_isConnected(false)
{
}

void Agent::Connect()
{
    m_isConnected = true;
}

void Agent::Disconnect()
{
    m_isConnected = false;
}

std::string Agent::GetID() const
{
    return m_id;
}

std::string Agent::GetType() const
{
    return m_type;
}

Location Agent::GetLocation() const
{
    return m_location;
}

std::string Agent::GetLog() const
{
    return m_log;
}

std::string Agent::GetConfig() const
{
    return m_config;
}

bool Agent::IsConnected() const
{
    return m_isConnected;
}
