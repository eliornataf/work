#include <stdexcept> // std::runtime_error 
#include "mutex.hpp" // Mutex Header 

Mutex::Mutex() 
: m_mutex(PTHREAD_MUTEX_INITIALIZER) {
    if (pthread_mutex_init(&this->m_mutex, NULL)) {
        throw std::runtime_error("Mutex init failed");
    }
}

Mutex::~Mutex() {
    this->Unlock();
    pthread_mutex_destroy(&this->m_mutex);
}

void Mutex::Lock() {
    if (PTHREAD_SUCCESS != pthread_mutex_lock(&this->m_mutex)) {
        throw std::runtime_error("Mutex lock failed");
    }
}

void Mutex::Unlock() {
    if (PTHREAD_SUCCESS != pthread_mutex_unlock(&this->m_mutex)) {
        throw std::runtime_error("Mutex unlock failed");
    }
}

pthread_mutex_t &Mutex::GetMutex() {
    return this->m_mutex;
}
