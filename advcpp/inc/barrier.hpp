#ifndef BARRIER_HPP
#define BARRIER_HPP

#include <pthread.h> // pthread_t
#include "atomic_flag.hpp" // Atomic Flag Header

namespace advcpp {

class Barrier {
public:
    Barrier() = default;
    ~Barrier();

    Barrier(const Barrier &a_other) = delete;
    Barrier &operator=(const Barrier &a_other) = delete;

    void Init(const unsigned int a_count);
    void Wait();

private:
    static constexpr unsigned int PTHREAD_SUCCESS = 0; 

    pthread_barrier_t m_barrier;
    AtomicFlag m_isInitalized;
    AtomicFlag m_isWaiting;
};

} // advcpp

#endif // BARRIER_HPP 
