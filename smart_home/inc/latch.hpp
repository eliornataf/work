#ifndef LATCH_HPP
#define LATCH_HPP

#include <condition_variable> // std::condition_variable
#include <mutex> // std::mutex
#include <thread> // std::lock_guard
#include "atomic_value.hpp" // Atomic Value Header

namespace advcpp {

class Latch {
public:
    Latch();
    ~Latch() = default;

    Latch(const Latch &a_other) = delete;
    Latch &operator=(const Latch &a_other) = delete;

    void SetAtomicValue(unsigned int a_value);
    void Wait();
    void CountDown();

    size_t GetAtomicValueSize() const;

private:
    std::condition_variable m_conditionVaraiable;
    std::mutex m_mutex;
    AtomicValue<size_t> m_atomicValue;
};

} // advcpp

#endif // LATCH_HPP