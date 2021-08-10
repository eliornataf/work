/*****************************************************************************
* File Name: Thread
* Written by: Elior Nataf
* Date: 9/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __THREAD_HPP__
#define __THREAD_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <pthread.h> // pthread_t

/*-------------------------------- Structure -------------------------------*/

class Thread {
public:
    // Typedef

    typedef void* (*ThreadFunction)(void* a_context);

    // Constructor

    Thread(ThreadFunction a_threadFunction);
    Thread(ThreadFunction a_threadFunction, const void *a_arg);

    // Destructor

    ~Thread() = default;

    // Copy Constructor

    Thread(const Thread &a_other) = delete;

    // Assignment Operator

    Thread &operator=(const Thread &a_other) = delete;

    // Move Constructor

    Thread(Thread &&a_rvalue);

    // Move Assignment

    Thread& operator=(Thread &&a_rvalue);

    // Methods

    void Detach();
    void *Join();
    void Cancel();

private:
    // Constants

    static constexpr unsigned int PTHREAD_SUCCESS = 0; 

    // Class Members

    pthread_t m_thread;
};

#endif /* __THREAD_HPP__ */
