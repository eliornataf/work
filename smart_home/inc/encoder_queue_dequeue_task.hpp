#ifndef ENCODER_QUEUE_DEQUEUE_TASK_HPP
#define ENCODER_QUEUE_DEQUEUE_TASK_HPP

#include <memory> // std::shared_ptr
#include "atomic_flag.hpp" // Atomic Flag Header
#include "blocking_bounded_queue.hpp" // Blocking Bounded Queue Header
#include "event.hpp" // Event Header
#include "runnable.hpp" // Runnable Header
#include "socket_manager.hpp" // Socket Manager Header
#include "thread_pool.hpp" // Thread Pool Header

namespace advcpp {

class EncoderQueueDequeueTask : public Runnable {
public:
    EncoderQueueDequeueTask(std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> a_encoderBlockingBoundedQueue, std::shared_ptr<ThreadPool> a_encoderThreadPool, std::shared_ptr<SocketManager> a_socketManager, std::shared_ptr<AtomicFlag> a_encoderQueueDequeueTaskIsRunning);
    virtual ~EncoderQueueDequeueTask() = default;

    EncoderQueueDequeueTask(const EncoderQueueDequeueTask &a_other) = delete;
    EncoderQueueDequeueTask &operator=(const EncoderQueueDequeueTask &a_other) = delete;

    virtual void run() override;

private:
    std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> m_encoderBlockingBoundedQueue;
    std::shared_ptr<ThreadPool> m_encoderThreadPool;
    std::shared_ptr<SocketManager> m_socketManager;
    std::shared_ptr<AtomicFlag> m_encoderQueueDequeueTaskIsRunning;
};

} // advcpp

#endif // ENCODER_QUEUE_DEQUEUE_TASK_HPP