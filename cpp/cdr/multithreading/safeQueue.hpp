/*****************************************************************************
* File Name: Safe Queue
* Written by: Elior Nataf
* Date: 15/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __SAFE_QUEUE_HPP__
#define __SAFE_QUEUE_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <cstddef> // size_t
#include <queue> // std::queue
#include "mutex.hpp" // Mutex Header
#include "semaphore.hpp" // Semaphore Header

/*-------------------------------- Structure -------------------------------*/

template <typename T>
class SafeQueue {
public:
    // Constructor

    SafeQueue(const unsigned int a_initCapacity);

    // Destructor

    ~SafeQueue() = default;

    // Copy Constructor

    SafeQueue(const SafeQueue &a_other) = delete;

    // Assignment Operator

    SafeQueue &operator=(const SafeQueue &a_other) = delete;

    // Methods

    void Push(const T &a_value);
    T Pop();
    T &Front();
    T &Tail();
    bool IsEmpty();
    size_t GetSize();

    bool CheckIfSafeQueueRunning();
    void StopSafeQueue();

private:
    // Constants

    static constexpr int IS_PSHARED = 0;

    // Class Members

    std::queue<T> m_queue;
    Mutex m_lock;
    Semaphore m_queueFreeSapces;
    Semaphore m_queueOccupiedPlaces;
    bool m_isRunningSafeQueue;
};

#endif /* __SAFE_QUEUE_HPP__ */
