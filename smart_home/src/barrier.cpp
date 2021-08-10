#include <stdexcept> // std::runtime_error 
#include "../inc/barrier.hpp" // Barrier Header

using namespace advcpp;

Barrier::~Barrier()
{
    if (m_isInitalized.Get())
    {
        pthread_barrier_destroy(&m_barrier);
    }
}

void Barrier::Init(const unsigned int a_count)
{
    if (!m_isInitalized.Get())
    {
        if (PTHREAD_SUCCESS != pthread_barrier_init(&m_barrier, nullptr, a_count)) 
        {
            throw std::runtime_error("barrier init failed");
        }

        m_isInitalized.Set();
    }
}

void Barrier::Wait()
{
    if (m_isInitalized.Get() && !m_isWaiting.Get())
    {
        pthread_barrier_wait(&m_barrier);

        m_isWaiting.Set();
    }
}