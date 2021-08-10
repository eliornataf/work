#include "lockGuard.hpp" // LockGuard Header

LockGuard::LockGuard(Mutex &a_mutex)
: m_mutex(a_mutex) {
    this->m_mutex.Lock();
}

LockGuard::~LockGuard() {
    this->m_mutex.Unlock();
}
