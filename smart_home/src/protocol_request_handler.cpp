#include <memory> // std::shared_ptr
#include "../inc/controller_agent.hpp" // Controller Agent Header
#include "../inc/protocol_request_handler.hpp" // Protocol Request Handler Header 
#include "../inc/sensor_agent.hpp" // Sensor Agent Header

using namespace advcpp;

ProtocolRequestHandler::ProtocolRequestHandler::ProtocolRequestHandler(std::shared_ptr<Protocol> a_protocol)
: m_protocol(a_protocol)
, m_agentManager(nullptr)
, m_subscribersManager(nullptr)
, m_decoderBlockingBoundedQueue(nullptr)
, m_socketManager(nullptr)
{
}

void ProtocolRequestHandler::InitializeAgentManagerManager(std::shared_ptr<AgentManager> a_agentManager)
{
    m_agentManager = a_agentManager;
}

void ProtocolRequestHandler::InitializeSubscriberManager(std::shared_ptr<SubscribersManager> a_subscriberManager)
{
    m_subscribersManager = a_subscriberManager;
}

void ProtocolRequestHandler::InitializeBlockingBoundedQueue(std::shared_ptr<BlockingBoundedQueue<std::shared_ptr<Event>>> a_decoderBlockingBoundedQueue)
{
    m_decoderBlockingBoundedQueue = a_decoderBlockingBoundedQueue;
}

void ProtocolRequestHandler::InitializeSocketManager(std::shared_ptr<SocketManager> a_socketManager)
{
    m_socketManager = a_socketManager;
}

void ProtocolRequestHandler::Handle(const std::string &a_request, std::shared_ptr<Socket> a_clientSocket)
{
    std::shared_ptr<RequestType> request = m_protocol->GetDataByType(a_request);

    std::shared_ptr<Agent> agent = m_agentManager->Find(request->GetID());
    if (!agent)
    {
        return;
    }

    switch(request->GetRequestType())
    {
        case CONNECT:
        { 
            m_agentManager->Connect(agent);
            m_socketManager->Add(request->GetID(), a_clientSocket);
        }
            
        case DISCONNECT:
        {
            m_agentManager->Disconnect(agent);
            m_socketManager->Remove(request->GetID());
        }
           
        case EVENT:
        {
            std::shared_ptr<EventRequest> eventRequest = std::dynamic_pointer_cast<EventRequest>(request);
            std::shared_ptr<SensorAgent> sensorAgent = std::dynamic_pointer_cast<SensorAgent>(agent);
            sensorAgent->Publish(eventRequest->GetEvent(), m_decoderBlockingBoundedQueue);
        }
            
        case SUBSCRIBE:
        {
            std::shared_ptr<SubscribeRequest> subscribeRequest = std::dynamic_pointer_cast<SubscribeRequest>(request);
            std::shared_ptr<ControllerAgent> controllerAgent = std::dynamic_pointer_cast<ControllerAgent>(agent);
            m_subscribersManager->Subscribe(controllerAgent, subscribeRequest->GetType(), Location(std::atoi(subscribeRequest->GetFloor().c_str()), std::atoi(subscribeRequest->GetRoom().c_str())));
        }
            
        case UNSUBSCRIBE:
        {
            std::shared_ptr<UnSubscribeRequest> unSubscribeRequest = std::dynamic_pointer_cast<UnSubscribeRequest>(request);
            std::shared_ptr<ControllerAgent> controllerAgent = std::dynamic_pointer_cast<ControllerAgent>(agent);
            m_subscribersManager->Unsubscribe(controllerAgent, unSubscribeRequest->GetType(), Location(std::atoi(unSubscribeRequest->GetFloor().c_str()), std::atoi(unSubscribeRequest->GetRoom().c_str())));
        }
    }
}