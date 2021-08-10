#include "../inc/encoder_queue_dequeue_task.hpp" // Encoder Queue Dequeue Task Header
#include "../inc/send_message_task.hpp" // Send Message Task Header

using namespace advcpp;

EncoderQueueDequeueTask::EncoderQueueDequeueTask(std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> a_encoderBlockingBoundedQueue, std::shared_ptr<ThreadPool> a_encoderThreadPool, std::shared_ptr<SocketManager> a_socketManager, std::shared_ptr<AtomicFlag> a_encoderQueueDequeueTaskIsRunning)
: m_encoderBlockingBoundedQueue(a_encoderBlockingBoundedQueue)
, m_encoderThreadPool(a_encoderThreadPool)
, m_socketManager(a_socketManager)
, m_encoderQueueDequeueTaskIsRunning(a_encoderQueueDequeueTaskIsRunning)
{
}

void EncoderQueueDequeueTask::run()
{
    while (m_encoderQueueDequeueTaskIsRunning->Get())
    {
        std::pair<std::string, std::string> agentPair;
        if (!m_encoderBlockingBoundedQueue->Dequeue(agentPair))
        {
            break;
        }

        std::shared_ptr<Runnable> sendMessageTask(new SendMessageTask(m_socketManager, agentPair.first, agentPair.second));
        m_encoderThreadPool->Submit(sendMessageTask);
    }
}
