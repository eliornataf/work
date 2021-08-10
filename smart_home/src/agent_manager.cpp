#include <algorithm> // std::for_each
#include "../inc/agent_manager.hpp" // Agent Manager Header

using namespace advcpp;

AgentManager::AgentManager(std::shared_ptr<IReader> a_reader)
: m_reader(a_reader)
{
}

void AgentManager::Add(std::shared_ptr<Agent> a_agent)
{  
    m_agentMap.insert({a_agent->GetID(), a_agent});
}

void AgentManager::Remove(const std::string &a_id)
{
    m_agentMap.erase(a_id);
}

std::shared_ptr<Agent> AgentManager::Find(const std::string &a_id) const
{
    if (m_agentMap.find(a_id) == m_agentMap.end())
    {
        return nullptr;
    }
    
    return m_agentMap.at(a_id);
}

void AgentManager::Connect(std::shared_ptr<Agent> a_agent)
{
    if (!a_agent->IsConnected())
    {
        a_agent->Connect();
    }
}

void AgentManager::Disconnect(std::shared_ptr<Agent> a_agent)
{
    if (a_agent->IsConnected())
    {
        a_agent->Disconnect();
    }
}

void AgentManager::InitializeAgents(const std::string &a_file)
{
    std::vector<std::shared_ptr<Agent>> agentVector = m_reader->Read(a_file);

    std::for_each(agentVector.begin(), agentVector.end(), [&](const std::shared_ptr<Agent> a_agent)
    {
        Add(a_agent);
    });    
}
