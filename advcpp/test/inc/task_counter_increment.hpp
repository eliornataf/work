#ifndef TASK_COUNTER_INCREMENT_HPP
#define TASK_COUNTER_INCREMENT_HPP

#include "counter.hpp" // Counter Header
#include "runnable.hpp" // Runnable Header

namespace advcpp {

class TaskCounterIncrement : public Runnable {
public:
    TaskCounterIncrement(Counter &a_counter, const size_t a_numberOfIterations) : m_counter(a_counter), m_numberOfIterations(a_numberOfIterations) {}
    virtual ~TaskCounterIncrement() = default;

    TaskCounterIncrement(const TaskCounterIncrement &a_other) = delete;
    TaskCounterIncrement &operator=(const TaskCounterIncrement &a_other) = delete;

    virtual void run() override { for(size_t i = 0;i < m_numberOfIterations;++i) {m_counter.Increment();} }

private:
    Counter &m_counter;
    size_t m_numberOfIterations;
};

} // advcpp

#endif // TASK_COUNTER_INCREMENT_HPP