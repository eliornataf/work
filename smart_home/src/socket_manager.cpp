#include "../inc/socket_manager.hpp" // Socket Manager Header

using namespace advcpp;

void SocketManager::Add(const std::string &a_id, std::shared_ptr<Socket> a_socket)
{
    m_socketMap.insert({a_id, a_socket});
}   

void SocketManager::Remove(const std::string &a_id)
{
    m_socketMap.erase(a_id);
}

std::shared_ptr<Socket> SocketManager::Find(const std::string &a_id)
{
    if (m_socketMap.find(a_id) != m_socketMap.end())
    {
        return m_socketMap.at(a_id);
    }

    return nullptr;
}
