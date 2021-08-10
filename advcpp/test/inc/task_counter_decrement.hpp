#ifndef TASK_COUNTER_DECREMENT_HPP
#define TASK_COUNTER_DECREMENT_HPP

#include "counter.hpp" // Counter Header
#include "runnable.hpp" // Runnable Header

namespace advcpp {

class TaskCounterDecrement : public Runnable {
public:
    TaskCounterDecrement(Counter &a_counter, const size_t a_numberOfIterations) : m_counter(a_counter) , m_numberOfIterations(a_numberOfIterations) {}
    virtual ~TaskCounterDecrement() = default;

    TaskCounterDecrement(const TaskCounterDecrement &a_other) = delete;
    TaskCounterDecrement &operator=(const TaskCounterDecrement &a_other) = delete;

    virtual void run() override { for(size_t i = 0;i < m_numberOfIterations;++i) {m_counter.Decrement();} }

private:
    Counter &m_counter;
    size_t m_numberOfIterations;
};

} // advcpp

#endif // TASK_COUNTER_DECREMENT_HPP