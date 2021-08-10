#ifndef LISTENING_SOCKET_HPP
#define LISTENING_SOCKET_HPP

#include <string> // std::string
#include "socket.hpp" // Socket Header

namespace advcpp {

class ListeningSocket : public Socket {
public:
    ListeningSocket(const unsigned int a_port, const unsigned int a_queueLength);
    virtual ~ListeningSocket() = default;

    ListeningSocket(const ListeningSocket &a_other) = default;
    ListeningSocket &operator=(const ListeningSocket &a_other) = default;

    void Accept();
    virtual std::string Receive(const size_t a_bytesToReceive) override;

    int GetNewClientSocket() const;
    struct sockaddr_in GetNewClientSocketAddress() const;
    
private:
    static constexpr unsigned int ENABLE_OPTVAL = 1;
    static constexpr int SUCCESS = 0;
    static constexpr int ERROR = -1;

private:
    void Setsockopt();
    void Bind();
    void NonBlock();
    void Listen();

    int m_newClientSocket;
    struct sockaddr_in m_newClientSocketAddress;
    unsigned int m_queueLength;
};

} // advcpp

#endif // LISTENING_SOCKET_HPP
