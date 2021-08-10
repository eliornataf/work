#include <arpa/inet.h> // inet_addr 
#include <errno.h> // errno
#include <netinet/in.h> // sockaddr_in 
#include <string.h> // memset
#include <stdexcept> // std::runtime_error
#include "sys/socket.h" // socket 
#include <sys/types.h> // types 
#include <unistd.h> // close
#include "../inc/socket.hpp" // Socket Header 

using namespace advcpp;

Socket::Socket(const std::string &a_ip, const unsigned int a_port) 
: m_socket()
, m_socketAddress() 
{
    if (a_port < MINIMUM_PORT || MAXIMUM_PORT < a_port)
    {
        throw std::runtime_error("Port number input is not valid");
    }

    m_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (ERROR == m_socket) 
    {
        throw std::runtime_error("Socket failed");
    }

    memset(&m_socketAddress, 0, sizeof(m_socketAddress));

    m_socketAddress.sin_family = AF_INET;
    m_socketAddress.sin_addr.s_addr = inet_addr(a_ip.c_str());
    m_socketAddress.sin_port = htons(a_port);
}

Socket::~Socket() 
{
    close(m_socket);
}

void Socket::Connect() 
{
    if (SUCCESS != connect(m_socket, (struct sockaddr*)&m_socketAddress, sizeof(m_socketAddress))) 
    {
        throw std::runtime_error("Socket connect failed");
    }
}

size_t Socket::Send(const char *a_message, const size_t a_messageSize) 
{
    ssize_t totalSendBytes = 0;
    ssize_t currentSendBytes = 0;

    do 
    {
        currentSendBytes = send(m_socket, a_message, a_messageSize, 0);
        if (ERROR == currentSendBytes) 
        {
            throw std::runtime_error("Socket send error");
        }

        totalSendBytes += currentSendBytes;
    } while (0 != currentSendBytes);

    delete[] a_message;
    return totalSendBytes;
}

std::string Socket::Receive(const size_t a_bytesToReceive) 
{
    std::string receivedMessage;
    size_t currentReceivedBytes = 0;

    do 
    {
        char *buffer = new char[a_bytesToReceive];

        currentReceivedBytes = recv(m_socket, buffer, a_bytesToReceive, 0);
        if (ERROR == currentReceivedBytes) 
        {
            delete[] buffer;
            throw std::runtime_error("Socket receive error");
        }

        receivedMessage += buffer;
        delete[] buffer; 
    } while (0 != currentReceivedBytes);
    
    return receivedMessage;
}

int Socket::GetSocket() const
{
    return m_socket;
}
