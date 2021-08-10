#include <cassert> // assert
#include <stdexcept> // std::runtime_error 
#include "mutex.hpp" // Mutex Header 

using namespace advcpp;

Mutex::Mutex() 
: m_mutex() 
, m_isMutexLocked(false)
{
    if (pthread_mutex_init(&this->m_mutex, NULL)) 
    {
        throw std::runtime_error("mutex init failed");
    }
}

Mutex::~Mutex() 
{
    if (m_isMutexLocked)
    {
        this->Unlock();
    }

    assert(PTHREAD_SUCCESS == pthread_mutex_destroy(&this->m_mutex));
}

void Mutex::Lock() 
{
    if (PTHREAD_SUCCESS != pthread_mutex_lock(&this->m_mutex)) 
    {
        throw std::runtime_error("mutex lock failed");
    }

    m_isMutexLocked = true;
}

void Mutex::Unlock() 
{
    if (m_isMutexLocked) 
    {
        if (PTHREAD_SUCCESS != pthread_mutex_unlock(&this->m_mutex)) 
        {
            throw std::runtime_error("mutex unlock failed");
        }

        m_isMutexLocked = false;
    }
}

pthread_mutex_t &Mutex::GetMutex() const
{
    return this->m_mutex;
}
