#include "../inc/send_message_task.hpp" // Send Message Task Header

using namespace advcpp;

SendMessageTask::SendMessageTask(std::shared_ptr<SocketManager> a_socketManager, const std::string &a_agentID, const std::string &a_event)
: m_socketManager(a_socketManager)
, m_agentID(a_agentID)
, m_event(a_event)
{
}

void SendMessageTask::run()
{
    std::shared_ptr<Socket> agentSocket = m_socketManager->Find(m_agentID);
    if (agentSocket)
    {
        agentSocket->Send(m_event.c_str(), m_event.size());
    }
}
