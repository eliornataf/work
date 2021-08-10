/*****************************************************************************
* File Name: Thread Pool
* Written by: Elior Nataf
* Date: 20/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __THREAD_POOL_HPP__
#define __THREAD_POOL_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <vector> // std::vector
#include "../task/task.hpp" // Tash Header
#include "thread.hpp" // Thread Header
#include "safeQueue_inline.hpp" // Safe Queue Inline

/*-------------------------------- Structure -------------------------------*/

class ThreadPool {
public:
    // Constructor

    ThreadPool(const unsigned int a_numOfThreads, const unsigned int a_safeQueueCapacity);

    // Destructor

    ~ThreadPool();

    // Copy Constructor

    ThreadPool(const ThreadPool &a_other) = default;

    // Assignment Operator

    ThreadPool &operator=(const ThreadPool &a_other) = default;

    // Methods

    void AddTaskToSafeQueue(Task *a_task);
    void StopSafeQueueExecution();

private:  
    // Class Members

    std::vector<Thread> m_threadVector;
    SafeQueue<Task*> *m_safeQueue;
};

#endif /* __THREAD_POOL_HPP__ */
