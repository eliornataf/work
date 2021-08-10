#ifndef AGENT_MANAGER_HPP
#define AGENT_MANAGER_HPP

#include <memory> // std:shared_ptr
#include <unordered_map> // std::unordered_map
#include "agent.hpp" // Agent Header
#include "i_reader.hpp" // I Reader Header

namespace advcpp {

class AgentManager {
public:
    explicit AgentManager(std::shared_ptr<IReader> a_reader);
    ~AgentManager() = default;

    AgentManager(const AgentManager &a_other) = default;
    AgentManager &operator=(const AgentManager &a_other) = default;

    void Add(std::shared_ptr<Agent> a_agent);
    void Remove(const std::string &a_id);
    std::shared_ptr<Agent> Find(const std::string &a_id) const;

    void Connect(std::shared_ptr<Agent> a_agent);
    void Disconnect(std::shared_ptr<Agent> a_agent);

    void InitializeAgents(const std::string &a_file);

private: 
    std::unordered_map<std::string, std::shared_ptr<Agent>> m_agentMap;
    std::shared_ptr<IReader> m_reader;
};

} // advcpp

#endif // AGENT_MANAGER_HPP