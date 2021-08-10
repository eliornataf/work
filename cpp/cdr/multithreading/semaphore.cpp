#include <stdexcept> // std::runtime_error 
#include "semaphore.hpp" // Semaphore Header

Semaphore::Semaphore(const int a_pshared, const unsigned int a_value)
: m_semaphore() {
    if (sem_init(&this->m_semaphore, a_pshared, a_value)) {
        throw std::runtime_error("Semaphore init failed");
    }
}

Semaphore::~Semaphore() {
    sem_destroy(&this->m_semaphore);
}

void Semaphore::Wait() {
    if (PTHREAD_SUCCESS != sem_wait(&this->m_semaphore)) {
        throw std::runtime_error("Semaphore wait failed");
    }
}

void Semaphore::Post() {
    if (PTHREAD_SUCCESS != sem_post(&this->m_semaphore)) {
        throw std::runtime_error("Semaphore post failed");
    }
}

void Semaphore::GetValue(int &getValue) {
    if (PTHREAD_SUCCESS != sem_getvalue(&this->m_semaphore, &getValue)) {
        throw std::runtime_error("Semaphore getValue failed");
    }
}