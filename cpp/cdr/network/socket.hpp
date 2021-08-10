/*****************************************************************************
* File Name: Socket
* Written by: Elior Nataf
* Date: 20/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __SOCKET_HPP__
#define __SOCKET_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <netinet/in.h> // sockaddr_in 
#include <string> // std::string

/*-------------------------------- Structure -------------------------------*/

class Socket {
public:
    // Constructor

    Socket(const std::string &a_ipAddress, const unsigned int a_portNumber);

    // Destructor

    virtual ~Socket();

    // Copy Constructor

    Socket(const Socket &a_other) = delete;

    // Assignment Operator

    Socket &operator=(const Socket &a_other) = delete;

    // Methods

    void Connect();
    size_t Send(const char *a_message, const size_t a_messageSize);
    virtual char *Receive(const size_t a_bytesToReceive);

protected:
    // Class members

    int m_socket;
    struct sockaddr_in m_socketAddress;
};

#endif /* __SOCKET_HPP__ */
