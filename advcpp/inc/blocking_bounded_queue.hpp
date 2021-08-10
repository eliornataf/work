#ifndef BLOCKING_BOUNDED_QUEUE_HPP
#define BLOCKING_BOUNDED_QUEUE_HPP

#include <mutex> // std::mutex
#include <queue> // std::queue

#include "atomic_flag.hpp" // Atomic Flag Header
#include "atomic_value.hpp" // Atomic Flag Header
#include "barrier.hpp" // Barrier Header
#include "lock_guard.hpp" // Lock Guard Header
#include "semaphore.hpp" // Semaphore Header

namespace advcpp {

template <typename T>
class BlockingBoundedQueue {
public:
    explicit BlockingBoundedQueue(const size_t a_queueCapacity);
    ~BlockingBoundedQueue();

    BlockingBoundedQueue(const BlockingBoundedQueue &a_other) = delete;
    BlockingBoundedQueue &operator=(const BlockingBoundedQueue &a_other) = delete;

    bool Enqueue(const T &a_value);
    bool Dequeue(T &a_returnValue);

    size_t Capacity() const;
    size_t Size() const;
    bool IsEmpty() const;
    bool IsFull() const;

private:
    void FreeBlockedThreads(Semaphore &a_sem, const size_t a_numberOfThreads);

    std::queue<T> m_queue;
    size_t m_queueCapacity;
    Semaphore m_queueFreeSapces;
    Semaphore m_queueOccupiedPlaces;
    mutable std::mutex m_mutex;
    AtomicFlag m_isAliveQueue;
    AtomicValue<size_t> m_numberOfWaitingEnqueue;
    AtomicValue<size_t> m_numberOfWaitingDequeue;
};

#include "inl/blocking_bounded_queue.hxx" // Blocking Bounded Queue Inline

} // advcpp

#endif // BLOCKING_BOUNDED_QUEUE_HPP
