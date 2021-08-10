/*****************************************************************************
* File Name: Listening Socket
* Written by: Elior Nataf
* Date: 20/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __LISTENING_SOCKET_HPP__
#define __LISTENING_SOCKET_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <string> // std::string
#include "socket.hpp" // Socket Header

/*-------------------------------- Structure -------------------------------*/

class ListeningSocket : public Socket {
public:
    // Constructor

    ListeningSocket(const unsigned int a_listeningPortNumber);

    // Destructor

    virtual ~ListeningSocket() = default;

    // Copy Constructor

    ListeningSocket(const ListeningSocket &a_other) = delete;

    // Assignment Operator

    ListeningSocket &operator=(const ListeningSocket &a_other) = delete;

    // Methods

    bool Accept();
    virtual char *Receive(const size_t a_bytesToReceive) override;

private:
    // Constants

    static constexpr int NOT_INITIALIZE = -1;
    static constexpr unsigned int ENABLE_OPTVAL = 1;
    static constexpr unsigned int QUEUE_LENGTH = 1;

    // Methods

    void Setsockopt();
    void Bind();
    void NonBlock();
    void Listen();

    // Class Members

    int m_clientSocket;
};

#endif /* __LISTENING_SOCKET_HPP__ */
