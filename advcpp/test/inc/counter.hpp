#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <cstddef> // size_t
#include <mutex> // Mutex Header		

namespace advcpp {

class Counter {
public:
    Counter() = default;
    ~Counter() = default;

    Counter(const Counter &a_other) = delete;
    Counter &operator=(const Counter &a_other) = delete;

    void Increment() {m_mutex.lock(); ++m_count; m_mutex.unlock();}
    void Decrement() {m_mutex.lock(); --m_count; m_mutex.unlock();}

    size_t GetCount() const {return m_count;}

private:
    size_t m_count = 0;
    std::mutex m_mutex;
};

} // advcpp

#endif // COUNTER_HPP
