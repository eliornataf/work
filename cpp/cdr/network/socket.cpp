#include <arpa/inet.h> // inet_addr 
#include <errno.h> // errno
#include <netinet/in.h> // sockaddr_in 
#include <string.h> // memset, strlen
#include <stdexcept> // std::runtime_error
#include "sys/socket.h" // socket 
#include <sys/types.h> // types 
#include <unistd.h> // close
#include "socket.hpp" // Socket Header 

/*******************************************************
******************* Public Functions *******************
*******************************************************/

Socket::Socket(const std::string &a_ipAddress, const unsigned int a_portNumber) 
: m_socket(socket(AF_INET, SOCK_STREAM, 0))
, m_socketAddress() {
    if (this->m_socket < 0) {
        throw std::runtime_error("Socket failed");
    }

    memset(&this->m_socketAddress, 0, sizeof(this->m_socketAddress));

    this->m_socketAddress.sin_family = AF_INET;
    this->m_socketAddress.sin_addr.s_addr = inet_addr(a_ipAddress.c_str());
    this->m_socketAddress.sin_port = htons(a_portNumber);
}

Socket::~Socket() {
    close(this->m_socket);
}

void Socket::Connect() {
    if (connect(this->m_socket, (struct sockaddr*)&this->m_socketAddress, sizeof(this->m_socketAddress)) < 0) {
        throw std::runtime_error("Socket connect failed");
    }
}

size_t Socket::Send(const char *a_message, const size_t a_messageSize) {
    ssize_t numOfSendBytes = send(this->m_socket, static_cast<const void*>(a_message), a_messageSize, 0);
    if(numOfSendBytes < 0) {
        throw std::runtime_error("Socket send error");
    }

    return numOfSendBytes;
}

char *Socket::Receive(const size_t a_bytesToReceive) {
    char *buffer = new char[a_bytesToReceive];
    ssize_t numOfReceivedBytes = recv(this->m_socket, static_cast<void*>(buffer), a_bytesToReceive, 0);
    if (numOfReceivedBytes < 0) {
        throw std::runtime_error("Socket receive error");
    }

    return buffer;
}
