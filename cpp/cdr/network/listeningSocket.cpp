#include <cstring> // memcpy
#include <fcntl.h> // fcntl 
#include <stdexcept> // std::runtime_error
#include "listeningSocket.hpp" // Listen Socket Header

/*******************************************************
******************* Public Functions *******************
*******************************************************/

ListeningSocket::ListeningSocket(const unsigned int a_listeningPortNumber) 
: Socket("0.0.0.0", a_listeningPortNumber)
, m_clientSocket(NOT_INITIALIZE) {
    this->Setsockopt();
    this->Bind();
    this->NonBlock();
    this->Listen();
}

bool ListeningSocket::Accept() {
    struct sockaddr_in clientSocketAddress;
    socklen_t clientSocketAddressLength = sizeof(this->m_socketAddress);
    this->m_clientSocket = accept(this->m_socket, (struct sockaddr*)&clientSocketAddress, &clientSocketAddressLength);
    if (m_clientSocket < 0) {
        if (EAGAIN != errno && EWOULDBLOCK != errno) {
            throw std::runtime_error("Listening socket accept failed");
        }
        
        return false;
    }

    return true;
}

char *ListeningSocket::Receive(const size_t a_bytesToReceive) {
    char *buffer = new char[a_bytesToReceive];
    ssize_t numOfReceivedBytes = recv(this->m_clientSocket, static_cast<void*>(buffer), a_bytesToReceive, 0);
    if (numOfReceivedBytes < 0) {
        if (EAGAIN != errno && EWOULDBLOCK != errno) {
            throw std::runtime_error("Listening socket receive failed");
        }
    }

    buffer[numOfReceivedBytes] = '\0';

    return buffer;
}

/*******************************************************
******************* Private Functions *******************
*******************************************************/

void ListeningSocket::Setsockopt() {
    int optval = ENABLE_OPTVAL;
    if (setsockopt(this->m_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        throw std::runtime_error("Listening socket setsockopt failed");
    }
}

void ListeningSocket::Bind() {   
    if (bind(this->m_socket, (struct sockaddr*)&this->m_socketAddress, sizeof(this->m_socketAddress)) < 0) {
        throw std::runtime_error("Listening socket bind error");
    }
}

void ListeningSocket::NonBlock() {
    int serverSocketStatus = fcntl(this->m_socket, F_GETFL);

    if (serverSocketStatus < 0) {
        throw std::runtime_error("Listening socket nonblock failed");
    }

    if (fcntl(this->m_socket, F_SETFL, serverSocketStatus | O_NONBLOCK) < 0) {
        throw std::runtime_error("Listening socket nonblock failed");
    }
}

void ListeningSocket::Listen() {
    if (listen(this->m_socket, QUEUE_LENGTH) < 0) {
        throw std::runtime_error("Listening socket bind error");
    }
}
