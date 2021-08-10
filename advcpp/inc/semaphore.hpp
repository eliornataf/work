#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

#include <semaphore.h> // sem_t

namespace advcpp {

class Semaphore {
public:
    Semaphore(const unsigned int a_value, const int a_pshared = IS_PSHARED);
    ~Semaphore();

    Semaphore(const Semaphore &a_other) = delete;
    Semaphore &operator=(const Semaphore &a_other) = delete;

    void Wait();
    void Post();
    int GetValue() const;

private:
    static constexpr unsigned int PTHREAD_SUCCESS = 0; 
    static constexpr int IS_PSHARED = 0;

    mutable sem_t m_semaphore;
};

} // advcpp

#endif // SEMAPHORE_HPP 
