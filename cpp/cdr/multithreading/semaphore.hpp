/*****************************************************************************
* File Name: Semaphore
* Written by: Elior Nataf
* Date: 9/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __SEMAPHORE_HPP__
#define __SEMAPHORE_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <semaphore.h> // sem_t

/*-------------------------------- Structure -------------------------------*/

class Semaphore {
public:
    // Constructor

    explicit Semaphore(const int a_pshared, const unsigned int a_value);

    // Destructor

    ~Semaphore();

    // Copy Constructor

    Semaphore(const Semaphore &a_other) = delete;

    // Assignment Operator

    Semaphore &operator=(const Semaphore &a_other) = delete;

    // Functions

    void Wait();
    void Post();
    void GetValue(int &getValue);

private:
    // Constants

    static constexpr unsigned int PTHREAD_SUCCESS = 0; 

    // Class Members

    sem_t m_semaphore;
};

#endif /* __SEMAPHORE_HPP__ */
