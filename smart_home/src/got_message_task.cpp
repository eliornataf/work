#include "../inc/got_message_task.hpp" // Got Message Task Header

using namespace advcpp;

GotMessageTask::GotMessageTask(std::shared_ptr<ProtocolRequestHandler> a_protocolRequestHandler, const std::string &a_message, std::shared_ptr<Socket> a_clientSocket)
: m_protocolRequestHandler(a_protocolRequestHandler)
, m_message(a_message)
, m_clientSocket(a_clientSocket)
{
}

void GotMessageTask::run()
{
    m_protocolRequestHandler->Handle(m_message, m_clientSocket);
}