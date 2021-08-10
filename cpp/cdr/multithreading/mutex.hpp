/*****************************************************************************
* File Name: Mutex
* Written by: Elior Nataf
* Date: 9/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __MUTEX_HPP__
#define __MUTEX_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <pthread.h> // pthread_mutex_t

/*-------------------------------- Structure -------------------------------*/

class Mutex {
public:
    // Constructor

    Mutex();

    // Destructor

    ~Mutex();

    // Copy Constructor

    Mutex(const Mutex &a_other) = delete;

    // Assignment Operator

    Mutex &operator=(const Mutex &a_other) = delete;

    // Functions

    void Lock();
    void Unlock();
    pthread_mutex_t &GetMutex();

private:
    // Constants

    static constexpr unsigned int PTHREAD_SUCCESS = 0; 

    // Class Members

    pthread_mutex_t m_mutex;
};

#endif /* __MUTEX_HPP__ */
