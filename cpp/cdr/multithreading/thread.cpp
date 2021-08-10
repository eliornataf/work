#include <stdexcept> // std::runtime_error
#include "thread.hpp" // Thread Header 

Thread::Thread(ThreadFunction a_threadFunction)
: m_thread() {
    if (PTHREAD_SUCCESS != pthread_create(&this->m_thread, NULL, a_threadFunction, NULL)) {
        throw std::runtime_error("Thread create failed");
    }
}

Thread::Thread(ThreadFunction a_threadFunction, const void *a_arg)
: m_thread() {
    if (PTHREAD_SUCCESS != pthread_create(&this->m_thread, NULL, a_threadFunction, const_cast<void*>(a_arg))) {
        throw std::runtime_error("Thread create failed");
    }
}

Thread::Thread(Thread &&a_rvalue)
: m_thread(a_rvalue.m_thread) {
}

Thread &Thread::operator=(Thread &&a_rvalue) {
    if (this != &a_rvalue) {
        this->Cancel();
        this->m_thread = a_rvalue.m_thread;
    }

    return *this;
}

void Thread::Detach() {
    if (PTHREAD_SUCCESS != pthread_detach(this->m_thread)) {
        throw std::runtime_error("Thread detach failed");
    }
}
    
void *Thread::Join() {
    void *returnValue = nullptr;
    if (PTHREAD_SUCCESS != pthread_join(this->m_thread, &returnValue)) {
        throw std::runtime_error("Thread join failed");
    }

    return returnValue;
}

void Thread::Cancel() {
    if (PTHREAD_SUCCESS != pthread_cancel(this->m_thread)) {
        throw std::runtime_error("Thread cancel failed");
    }
}