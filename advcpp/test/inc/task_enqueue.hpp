#ifndef TASK_ENQUEUE_HPP
#define TASK_ENQUEUE_HPP

#include <cstddef> // size_t
#include <iostream> // std::cout
#include <memory> // std::shared_ptr
#include <mutex> // std::mutex
#include <vector> // std::vector
#include "blocking_bounded_queue.hpp" // Blocking Bounded Queue Header
#include "runnable.hpp" // Runnable Header

namespace advcpp {

template <typename T>
class TaskEnqueue : public Runnable {
public:
    TaskEnqueue(std::shared_ptr<BlockingBoundedQueue<T>> a_blockingBoundedQueue, const size_t a_numberOfIterations, std::shared_ptr<std::vector<T>> a_vector) : m_blockingBoundedQueue(a_blockingBoundedQueue), m_numberOfIterations(a_numberOfIterations), m_vector(a_vector) {}
    virtual ~TaskEnqueue() = default;

    TaskEnqueue(const TaskEnqueue &a_other) = delete;
    TaskEnqueue &operator=(const TaskEnqueue &a_other) = delete;

    T Get(const size_t a_index) const {return m_vector->at(a_index);}

    virtual void run() override {for (size_t i = 0;i < m_numberOfIterations;++i) {m_mutex.lock(); m_blockingBoundedQueue->Enqueue(i); m_vector->push_back(i); m_mutex.unlock();} }

private:
    std::shared_ptr<BlockingBoundedQueue<T>> m_blockingBoundedQueue;
    size_t m_numberOfIterations;
    std::shared_ptr<std::vector<T>> m_vector;
    std::mutex m_mutex;
};

} // advcpp

#endif // TASK_COUNTER_DECREMENT_HPP