#include <cassert> // assert
#include "../inc/decoder_queue_dequeue_task.hpp" // Decoder Queue Dequeue Task Dequeue Header
#include "../inc/encoder_queue_dequeue_task.hpp" // Encoder Queue Dequeue Task Dequeue Header
#include "../inc/hub.hpp" // Hub Header 
#include "../inc/tcp_server.hpp" // Tcp Server Header
#include "../inc/thread.hpp" // Thread Header

using namespace advcpp;

Hub::Hub(std::shared_ptr<IReader> a_reader, std::shared_ptr<Protocol> a_protocol, unsigned int a_serverMaxConnectClients, unsigned int a_serverPort, unsigned int a_serverQueueLength, const std::string &a_iniFile)
: m_router(std::make_shared<Router>())
, m_subscribersManager(std::make_shared<SubscribersManager>())
, m_agentManager(std::make_shared<AgentManager>(a_reader))
, m_decoderBlockingBoundedQueue(std::make_shared<BlockingBoundedQueue<std::shared_ptr<Event>>>(BLOCKING_BOUNDED_QUEUE_SIZE))
, m_encoderBlockingBoundedQueue(std::make_shared<BlockingBoundedQueue<std::pair<std::string, std::string>>>(BLOCKING_BOUNDED_QUEUE_SIZE))
, m_protocolRequestHandler(std::make_shared<ProtocolRequestHandler>(a_protocol))
, m_socketManager(std::make_shared<SocketManager>())
, m_decoderThreadPool(std::make_shared<ThreadPool>(BLOCKING_BOUNDED_QUEUE_SIZE))
, m_encoderThreadPool(std::make_shared<ThreadPool>(BLOCKING_BOUNDED_QUEUE_SIZE))
, m_serverMaxConnectClients(a_serverMaxConnectClients)
, m_serverPort(a_serverPort)
, m_serverQueueLength(a_serverQueueLength)
, m_iniFile(a_iniFile)
, m_decoderQueueDequeueTaskIsRunning(std::make_shared<AtomicFlag>(true))
, m_encoderQueueDequeueTaskIsRunning(std::make_shared<AtomicFlag>(true))
{ 
    assert(a_reader);
    assert(a_protocol);

    m_router->InitializeSubscriberManager(m_subscribersManager);
    m_protocolRequestHandler->InitializeAgentManagerManager(m_agentManager);
    m_protocolRequestHandler->InitializeSubscriberManager(m_subscribersManager);
    m_protocolRequestHandler->InitializeBlockingBoundedQueue(m_decoderBlockingBoundedQueue);
    m_protocolRequestHandler->InitializeSocketManager(m_socketManager);
    m_agentManager->InitializeAgents(m_iniFile);

    InitializeDecoderQueueDequeueTask();
    InitializeEncoderQueueDequeueTask();
}

Hub::~Hub()
{
    m_decoderQueueDequeueTaskIsRunning->Clear();
    m_encoderQueueDequeueTaskIsRunning->Clear();
}

void Hub::InitializeDecoderQueueDequeueTask()
{
    std::shared_ptr<Runnable> decoderQueueDequeueTask(new DecoderQueueDequeueTask(m_decoderBlockingBoundedQueue, m_decoderThreadPool, m_router, m_encoderBlockingBoundedQueue, m_decoderQueueDequeueTaskIsRunning));
    Thread<DetachPolicy> decoderQueueDequeueThread(decoderQueueDequeueTask, DetachPolicy());
    decoderQueueDequeueThread.Detach();
}

void Hub::InitializeEncoderQueueDequeueTask()
{
    std::shared_ptr<Runnable> encoderQueueDequeueTask(new EncoderQueueDequeueTask(m_encoderBlockingBoundedQueue, m_encoderThreadPool, m_socketManager, m_encoderQueueDequeueTaskIsRunning));
    Thread<DetachPolicy> encoderQueueDequeueThread(encoderQueueDequeueTask, DetachPolicy());
    encoderQueueDequeueThread.Detach();
}

void Hub::Run()
{
    TCPServer tcpServer(m_serverMaxConnectClients, m_serverPort, m_serverQueueLength, BLOCKING_BOUNDED_QUEUE_SIZE, m_protocolRequestHandler);
    tcpServer.Run();
}