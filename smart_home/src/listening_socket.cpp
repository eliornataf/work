#include <cstring> // memcpy
#include <fcntl.h> // fcntl 
#include <stdexcept> // std::runtime_error
#include "../inc/listening_socket.hpp" // Listen Socket Header

using namespace advcpp;

ListeningSocket::ListeningSocket(const unsigned int a_port, const unsigned int a_queueLength) 
: Socket("0.0.0.0", a_port)
, m_newClientSocket()
, m_queueLength(a_queueLength) 
{
    if (0 == a_queueLength)
    {
        throw std::runtime_error("Queue Length input is not valid");
    }

    Setsockopt();
    Bind();
    NonBlock();
    Listen();
}

void ListeningSocket::Accept() 
{
    socklen_t newclientSocketAddressLength = sizeof(m_newClientSocketAddress);

    m_newClientSocket = accept(m_socket, (struct sockaddr*)&m_newClientSocketAddress, &newclientSocketAddressLength);
    if (ERROR == m_socket && EAGAIN != errno && EWOULDBLOCK != errno) 
    {
        throw std::runtime_error("Listening socket accept failed");
    }
}

std::string ListeningSocket::Receive(const size_t a_bytesToReceive) 
{
    std::string receivedMessage;
    size_t currentReceivedBytes = 0;

    do 
    {
        char *buffer = new char[a_bytesToReceive];

        currentReceivedBytes = recv(m_socket, buffer, a_bytesToReceive, 0);
        if (ERROR == currentReceivedBytes && (EAGAIN != errno && EWOULDBLOCK != errno)) 
        {
            delete[] buffer;
            throw std::runtime_error("Listening socket receive failed");
        }

        receivedMessage += buffer;
        delete[] buffer; 
    } while (0 != currentReceivedBytes);
    
    return receivedMessage;
}

int ListeningSocket::GetNewClientSocket() const
{
    return m_newClientSocket;
}

struct sockaddr_in ListeningSocket::GetNewClientSocketAddress() const
{
    return m_newClientSocketAddress;
}

////////////////// Private methods //////////////////

void ListeningSocket::Setsockopt() 
{
    int optval = ENABLE_OPTVAL;
    if (SUCCESS != setsockopt(m_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval))) 
    {
        throw std::runtime_error("Listening socket setsockopt failed");
    }
}

void ListeningSocket::Bind() 
{   
    if (SUCCESS != bind(m_socket, (struct sockaddr*)&m_socketAddress, sizeof(m_socketAddress))) 
    {
        throw std::runtime_error("Listening socket bind error");
    }
}

void ListeningSocket::NonBlock() 
{
    int serverSocketStatus = fcntl(m_socket, F_GETFL);

    if (ERROR == serverSocketStatus) 
    {
        throw std::runtime_error("Listening socket nonblock failed");
    }

    if (ERROR == fcntl(m_socket, F_SETFL, serverSocketStatus | O_NONBLOCK)) 
    {
        throw std::runtime_error("Listening socket nonblock failed");
    }
}

void ListeningSocket::Listen() {
    if (SUCCESS != listen(m_socket, m_queueLength)) 
    {
        throw std::runtime_error("Listening socket bind error");
    }
}
