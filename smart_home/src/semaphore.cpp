#include <stdexcept> // std::runtime_error 
#include "../inc/semaphore.hpp" // Semaphore Header

using namespace advcpp;

Semaphore::Semaphore(const unsigned int a_value, const int a_pshared)
: m_semaphore() 
{
    if (PTHREAD_SUCCESS != sem_init(&m_semaphore, a_pshared, a_value)) 
    {
        throw std::runtime_error("semaphore init failed");
    }
}

Semaphore::~Semaphore() 
{
    sem_destroy(&m_semaphore);
}

void Semaphore::Wait() 
{
    if (PTHREAD_SUCCESS != sem_wait(&m_semaphore)) 
    {
        throw std::runtime_error("semaphore wait failed");
    }
}

void Semaphore::Post() 
{
    if (PTHREAD_SUCCESS != sem_post(&m_semaphore)) 
    {
        throw std::runtime_error("semaphore post failed");
    }
}

int Semaphore::GetValue() const
{
    int semValue;

    if (PTHREAD_SUCCESS != sem_getvalue(&m_semaphore, &semValue)) 
    {
        throw std::runtime_error("semaphore getValue failed");
    }

    return semValue;
}