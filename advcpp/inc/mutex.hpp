#ifndef MUTEX_HPP
#define MUTEX_HPP

#include <pthread.h> // pthread_mutex_t

namespace advcpp {

class Mutex {
public:
    Mutex();
   ~Mutex();

    Mutex(const Mutex &a_other) = delete;
    Mutex &operator=(const Mutex &a_other) = delete;

    void Lock();
    void Unlock();
    pthread_mutex_t &GetMutex() const;

private:
    static constexpr unsigned int PTHREAD_SUCCESS = 0; 

    mutable pthread_mutex_t m_mutex;
    bool m_isMutexLocked;
};

} // advcpp

#endif // MUTEX_HPP
