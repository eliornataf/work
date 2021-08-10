#ifndef HUB_HPP
#define HUB_HPP

#include <memory> // std::shared_ptr
#include "agent_manager.hpp" // Agent Manager Header
#include "atomic_flag.hpp" // Atomic Flag Header
#include "i_reader.hpp" // I Reader Header
#include "blocking_bounded_queue.hpp" // Blocking Bounded Queue Header
#include "event.hpp" // Event Header
#include "protocol.hpp" // Protocol Header
#include "protocol_request_handler.hpp" // Protocol Request Handler Header
#include "socket_manager.hpp" // Socket Manager Header 
#include "subscribers_manager.hpp" // Subscribers Manager Header
#include "router.hpp" // Router Header
#include "thread_pool.hpp" // Thread Pool Header

namespace advcpp {

class Hub {
public:
    Hub(const std::shared_ptr<IReader> a_reader, std::shared_ptr<Protocol> a_protocol, unsigned int a_serverMaxConnectClients, unsigned int a_serverPort, unsigned int a_serqueueLength, const std::string &a_iniFile);
    ~Hub();

    Hub(const Hub &a_other) = delete;
    Hub &operator=(const Hub &a_other) = delete;

    void Run();
    
private:
    static constexpr size_t BLOCKING_BOUNDED_QUEUE_SIZE = 100;

private:
    void InitializeDecoderQueueDequeueTask();
    void InitializeEncoderQueueDequeueTask();

    std::shared_ptr<Router> m_router; 
    std::shared_ptr<SubscribersManager> m_subscribersManager;
    std::shared_ptr<AgentManager> m_agentManager;
    std::shared_ptr<BlockingBoundedQueue<std::shared_ptr<Event>>> m_decoderBlockingBoundedQueue;
    std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> m_encoderBlockingBoundedQueue;
    std::shared_ptr<ProtocolRequestHandler> m_protocolRequestHandler;
    std::shared_ptr<SocketManager> m_socketManager;
    std::shared_ptr<ThreadPool> m_decoderThreadPool;
    std::shared_ptr<ThreadPool> m_encoderThreadPool;
    unsigned int m_serverMaxConnectClients;
    unsigned int m_serverPort;
    unsigned int m_serverQueueLength;
    std::string m_iniFile;
    std::shared_ptr<AtomicFlag> m_decoderQueueDequeueTaskIsRunning;
    std::shared_ptr<AtomicFlag> m_encoderQueueDequeueTaskIsRunning;
};

} // advcpp

#endif // HUB_HPP