#ifndef TCP_SERVER_HPP
#define TCP_SERVER_HPP

#include <list> // std::list
#include <unordered_map> // std::unordered_map
#include <string> // std::string
#include <sys/select.h> // fd_set

#include "thread_pool.hpp" // Thread Pool
#include "listening_socket.hpp" // Listening Socket Header
#include "protocol_request_handler.hpp" // Protocol Request Hander Header
#include "socket.hpp" // Socket Header

namespace advcpp {
class TCPServer {
public:
    TCPServer(unsigned int a_maxConnectClients, unsigned int a_port, unsigned int a_queueLength, const size_t a_blockingBoundedQueueCapacity, std::shared_ptr<ProtocolRequestHandler> a_protocolRequestHandler);
    ~TCPServer();

    void Run();

    size_t SendMessage(const int a_clientSocket, const char *a_message, const size_t a_messageSize);

private:
    static unsigned int CheckMaxConnectClientsInput(const unsigned int a_maxConnectClients);

    static constexpr int ERROR = -1; 
    static constexpr int DESCRIPTORS_LIMIT = 1020;
    static constexpr unsigned int BUFFER_SIZE = 4096;

    enum CheckForNewClientsStatus {
        MAX_CONNECTION_ERROR = 0,
        ACCPET_FAILED_ERROR, 
        SOCKET_NOT_VALIED_ERROR,
        SUCCESS
    };

    enum CheckClientReceiveMessageStatus {
        CLIENT_ERROR = 0,
        CLIENT_FINISH, 
        KEEP_CLIENT
    };

private:
    void SetMasterMonitorDescriptor();
    void CloseAllConnectClients();
    CheckForNewClientsStatus CheckForNewClients();
    void AddNewClients(const int a_newClientSocket, struct sockaddr_in a_newClientSocketAddress);
    void CheckCurrentClients(const fd_set a_tempMonitorDescriptor, size_t a_numberOfSignaledSockets);
    CheckClientReceiveMessageStatus CheckClientReceiveMessage(std::shared_ptr<Socket> &a_clientSocket);
    void GotMessage(const std::string &a_message, std::shared_ptr<Socket> a_clientSocket);

    unsigned int m_maxConnectClients;
    unsigned int m_currentConnectClients;
    ListeningSocket m_listeningSocket;
    std::unordered_map<int, std::shared_ptr<Socket>> m_serverClients;
    fd_set m_masterMonitorDescriptor;
    ThreadPool m_threadPool;
    std::shared_ptr<ProtocolRequestHandler> m_protocolRequestHandler;
};

} // advcpp

#endif // TCP_SERVER_HPP