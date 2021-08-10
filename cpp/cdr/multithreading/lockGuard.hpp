/*****************************************************************************
* File Name: Lock Guard
* Written by: Elior Nataf
* Date: 15/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __LOCK_GUARD_HPP__
#define __LOCK_GUARD_HPP__

/*------------------------------- Header Files ------------------------------*/

#include "mutex.hpp" // Mutex Header

/*-------------------------------- Structure -------------------------------*/

class LockGuard {
public:
    // Constructor

    LockGuard(Mutex &a_mutex);

    // Destructor

    ~LockGuard();

    // Copy Constructor

    LockGuard(const LockGuard &a_other) = delete;

    // Assignment Operator

    LockGuard &operator=(const LockGuard &a_other) = delete;

private:
    // Class Members

    Mutex &m_mutex;
};

#endif /* __LOCK_GUARD_HPP__ */
