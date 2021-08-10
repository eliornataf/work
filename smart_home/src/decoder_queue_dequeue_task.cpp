#include "../inc/decoder_queue_dequeue_task.hpp" // Task Dequeue Header

using namespace advcpp;

DecoderQueueDequeueTask::DecoderQueueDequeueTask(std::shared_ptr<BlockingBoundedQueue<std::shared_ptr<Event>>> a_decoderBlockingBoundedQueue, std::shared_ptr<ThreadPool> a_decoderThreadPool, std::shared_ptr<Router> a_router, std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> a_encoderBlockingBoundedQueue, std::shared_ptr<AtomicFlag> a_decoderQueueDequeueTaskIsRunning)
: m_decoderBlockingBoundedQueue(a_decoderBlockingBoundedQueue)
, m_decoderThreadPool(a_decoderThreadPool)
, m_router(a_router)
, m_encoderBlockingBoundedQueue(a_encoderBlockingBoundedQueue)
, m_decoderQueueDequeueTaskIsRunning(a_decoderQueueDequeueTaskIsRunning)
{
}

void DecoderQueueDequeueTask::run()
{
    while (m_decoderQueueDequeueTaskIsRunning->Get())
    {
        std::shared_ptr<Event> event;
        if (!m_decoderBlockingBoundedQueue->Dequeue(event))
        {
            break;
        }
        
        std::shared_ptr<Runnable> invokeTask(new InvokeTask(m_router, event, m_encoderBlockingBoundedQueue));
        m_decoderThreadPool->Submit(invokeTask);
    }
}
