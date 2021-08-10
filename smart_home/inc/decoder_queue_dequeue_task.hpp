#ifndef DECODER_QUEUE_DEQUEUE_TASK_HPP
#define DECODER_QUEUE_DEQUEUE_TASK_HPP

#include <memory> // std::shared_ptr
#include "atomic_flag.hpp" // Atomic Flag Header
#include "blocking_bounded_queue.hpp" // Blocking Bounded Queue Header
#include "event.hpp" // Event Header
#include "router.hpp" // Router Header
#include "invoke_task.hpp" // Invoke Task Header
#include "runnable.hpp" // Runnable Header
#include "thread_pool.hpp" // Thread Pool Header

namespace advcpp {

class DecoderQueueDequeueTask : public Runnable {
public:
    DecoderQueueDequeueTask(std::shared_ptr<BlockingBoundedQueue<std::shared_ptr<Event>>> a_decoderBlockingBoundedQueue, std::shared_ptr<ThreadPool> a_decoderThreadPool, std::shared_ptr<Router> a_router, std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> a_encoderBlockingBoundedQueue, std::shared_ptr<AtomicFlag> a_decoderQueueDequeueTaskIsRunning);
    virtual ~DecoderQueueDequeueTask() = default;

    DecoderQueueDequeueTask(const DecoderQueueDequeueTask &a_other) = delete;
    DecoderQueueDequeueTask &operator=(const DecoderQueueDequeueTask &a_other) = delete;

    virtual void run() override;

private:
    std::shared_ptr<BlockingBoundedQueue<std::shared_ptr<Event>>> m_decoderBlockingBoundedQueue;
    std::shared_ptr<ThreadPool> m_decoderThreadPool;
    std::shared_ptr<Router> m_router;
    std::shared_ptr<BlockingBoundedQueue<std::pair<std::string, std::string>>> m_encoderBlockingBoundedQueue;
    std::shared_ptr<AtomicFlag> m_decoderQueueDequeueTaskIsRunning;
};

} // advcpp

#endif // DECODER_QUEUE_DEQUEUE_TASK_HPP