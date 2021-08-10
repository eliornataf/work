#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <netinet/in.h> // sockaddr_in 
#include <string> // std::string

namespace advcpp {

class Socket {
public:
    Socket(const std::string &a_ip, const unsigned int a_port);
    virtual ~Socket();

    Socket(const Socket &a_other) = default;
    Socket &operator=(const Socket &a_other) = default;

    void Connect();
    size_t Send(const char *a_message, const size_t a_messageSize);
    virtual std::string Receive(const size_t a_bytesToReceive);

    int GetSocket() const;

protected:
    int m_socket;
    struct sockaddr_in m_socketAddress;

private:
    static constexpr int MINIMUM_PORT = 1025;
    static constexpr int MAXIMUM_PORT = 65535;
    static constexpr int SUCCESS = 0;
    static constexpr int ERROR = -1;
};

} // advcpp

#endif // SOCKET_HPP
