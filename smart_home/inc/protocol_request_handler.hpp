#ifndef PROTOCOL_REQUEST_HANDLER_HPP
#define PROTOCOL_REQUEST_HANDLER_HPP

#include <memory> // std::shared_ptr
#include "agent_manager.hpp" // Agent Manager Header
#include "blocking_bounded_queue.hpp" // Blocking Bounded Queue Header
#include "event.hpp" // Event Header
#include "protocol.hpp" // Protocol Header
#include "protocol_request_types.hpp" // Protocol Request Types Header
#include "socket.hpp" // Socket Header
#include "socket_manager.hpp" // Socket Manager Header
#include "subscribers_manager.hpp" // Subscribers Manager Header

namespace advcpp {

class ProtocolRequestHandler {
public:    
    ProtocolRequestHandler(std::shared_ptr<Protocol> a_protocol);
    ~ProtocolRequestHandler() = default;

    ProtocolRequestHandler(const ProtocolRequestHandler &a_other) = default;
    ProtocolRequestHandler &operator=(const ProtocolRequestHandler &a_other) = default;

    void InitializeAgentManagerManager(std::shared_ptr<AgentManager> a_agentManager);
    void InitializeSubscriberManager(std::shared_ptr<SubscribersManager> a_subscriberManager);
    void InitializeBlockingBoundedQueue(std::shared_ptr<BlockingBoundedQueue<std::shared_ptr<Event>>> a_decoderBlockingBoundedQueue);
    void InitializeSocketManager(std::shared_ptr<SocketManager> a_socketManager);

    void Handle(const std::string &a_request, std::shared_ptr<Socket> a_clientSocket);

private:
    std::shared_ptr<Protocol> m_protocol;
    std::shared_ptr<AgentManager> m_agentManager;
    std::shared_ptr<SubscribersManager> m_subscribersManager;
    std::shared_ptr<BlockingBoundedQueue<std::shared_ptr<Event>>> m_decoderBlockingBoundedQueue;
    std::shared_ptr<SocketManager> m_socketManager;
};

} // advcpp


#endif // PROTOCOL_REQUEST_HANDLER_HPP