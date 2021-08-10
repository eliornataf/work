#include <algorithm> // std::for_each
#include <arpa/inet.h> // inet_ntoa
#include <cstring> // strlen
#include <memory> // std::shared_ptr
#include <stdexcept> // std::runtime_error
#include <string> // std:string
#include <unistd.h> // close
#include "../inc/tcp_server.hpp" // TCP Server Header
#include "../inc/got_message_task.hpp" // Got Message Task Header

using namespace advcpp;

unsigned int TCPServer::CheckMaxConnectClientsInput(const unsigned int a_maxConnectClients)
{
    if (DESCRIPTORS_LIMIT < a_maxConnectClients)
    {
        throw std::runtime_error("Max connect clients is not valid");
    }

    return a_maxConnectClients;
}

TCPServer::TCPServer(unsigned int a_maxConnectClients, unsigned int a_port, unsigned int a_queueLength, const size_t a_blockingBoundedQueueCapacity, std::shared_ptr<ProtocolRequestHandler> a_protocolRequestHandler)
: m_maxConnectClients(CheckMaxConnectClientsInput(a_maxConnectClients))
, m_currentConnectClients(0)
, m_listeningSocket(a_port, a_queueLength)
, m_serverClients()
, m_masterMonitorDescriptor()
, m_threadPool(a_blockingBoundedQueueCapacity)
, m_protocolRequestHandler(a_protocolRequestHandler)
{
    assert(a_protocolRequestHandler);

    SetMasterMonitorDescriptor();
}

TCPServer::~TCPServer()
{
    CloseAllConnectClients();
}

void TCPServer::Run()
{
    while (true)
    {
        fd_set tempMonitorDescriptor = m_masterMonitorDescriptor;

        int numberOfSignaledSockets = select(DESCRIPTORS_LIMIT, &tempMonitorDescriptor, nullptr, nullptr, nullptr);
        if (ERROR == numberOfSignaledSockets)
        {
            break;
        }

        if (FD_ISSET(m_listeningSocket.GetSocket(), &tempMonitorDescriptor))
        {
            if (ACCPET_FAILED_ERROR == CheckForNewClients())
            {
                break;
            }

            --numberOfSignaledSockets;
        }

        if (numberOfSignaledSockets)
        {
            CheckCurrentClients(tempMonitorDescriptor, numberOfSignaledSockets);
        }
    }
}

size_t TCPServer::SendMessage(const int a_clientSocket, const char *a_message, const size_t a_messageSize)
{
    return m_serverClients[a_clientSocket]->Send(a_message, a_messageSize);
}

////////////////////// private Methods //////////////////////

void TCPServer::SetMasterMonitorDescriptor()
{
    FD_ZERO(&m_masterMonitorDescriptor);
    FD_SET(m_listeningSocket.GetSocket(), &m_masterMonitorDescriptor);
}

void TCPServer::CloseAllConnectClients()
{
    auto iterBegin = m_serverClients.begin();
    auto iterEnd = m_serverClients.end();

    while (iterBegin != iterEnd)
    {
        close(iterBegin->first);
    }
}

TCPServer::CheckForNewClientsStatus TCPServer::CheckForNewClients()
{
    if (m_currentConnectClients == m_maxConnectClients)
    {
        return MAX_CONNECTION_ERROR;
    }

    try 
    {
        m_listeningSocket.Accept();
    } 
    catch (...) 
    {
        return ACCPET_FAILED_ERROR;
    }

    int newClientSocket = m_listeningSocket.GetNewClientSocket();

    if (ERROR == newClientSocket)
    {
        return SOCKET_NOT_VALIED_ERROR;
    }

    AddNewClients(newClientSocket, m_listeningSocket.GetNewClientSocketAddress());

    return SUCCESS;
}

void TCPServer::AddNewClients(const int a_newClientSocket, struct sockaddr_in a_newClientSocketAddress)
{
    std::shared_ptr<Socket> newClientSocket(std::make_shared<Socket>(inet_ntoa(a_newClientSocketAddress.sin_addr), ntohs(a_newClientSocketAddress.sin_port)));
    m_serverClients[a_newClientSocket] = newClientSocket;
    FD_SET(a_newClientSocket, &m_masterMonitorDescriptor);
    ++m_currentConnectClients;
}

void TCPServer::CheckCurrentClients(const fd_set a_tempMonitorDescriptor, size_t a_numberOfSignaledSockets)
{
    auto iterBegin = m_serverClients.begin();
    auto iterEnd = m_serverClients.end();

    while (iterBegin != iterEnd)
    {
        auto currentClient = *iterBegin;

        if (FD_ISSET(currentClient.first, &a_tempMonitorDescriptor))
        {
            int clientReceiveMessageStatus = CheckClientReceiveMessage(currentClient.second);

            if (KEEP_CLIENT != clientReceiveMessageStatus)
            {
                iterBegin = m_serverClients.erase(iterBegin);
                FD_CLR(currentClient.first, &m_masterMonitorDescriptor);
                close(currentClient.first);
                --m_currentConnectClients;
            }
            else 
            {
                --a_numberOfSignaledSockets;

                if (0 == a_numberOfSignaledSockets)
                {
                    break;
                }

                ++iterBegin;
            }
        }
    }
}

TCPServer::CheckClientReceiveMessageStatus TCPServer::CheckClientReceiveMessage(std::shared_ptr<Socket> &a_clientSocket)
{
    std::string buffer;
    size_t bufferSize;

    try
    {
        buffer = a_clientSocket->Receive(BUFFER_SIZE);
        bufferSize = buffer.size();
    }
    catch(...)
    {
        return CLIENT_ERROR;
    }

    if (0 == bufferSize)
    {
        return CLIENT_FINISH;
    }

    GotMessage(buffer, a_clientSocket);

    return KEEP_CLIENT;
}

void TCPServer::GotMessage(const std::string &a_message, std::shared_ptr<Socket> a_clientSocket)
{
    std::shared_ptr<Runnable> gotMessageTask(new GotMessageTask(m_protocolRequestHandler, a_message, a_clientSocket));
    m_threadPool.Submit(gotMessageTask);
}
