#include "../inc/lock_guard.hpp" // LockGuard Header

using namespace advcpp;

LockGuard::LockGuard(std::mutex &a_mutex)
: m_mutex(a_mutex) 
{
    m_mutex.lock();
}

LockGuard::~LockGuard() 
{
    m_mutex.unlock();
}