#ifndef THREAD_POOL_EMPTY_TASK_HPP
#define THREAD_POOL_EMPTY_TASK_HPP

#include "runnable.hpp" // Runnable

namespace advcpp {

class ThreadPoolEmptyTask : public Runnable {
public:
    ThreadPoolEmptyTask() = default;
    ~ThreadPoolEmptyTask() = default;

    ThreadPoolEmptyTask(const ThreadPoolEmptyTask &a_other) = delete;
    ThreadPoolEmptyTask &operator=(const ThreadPoolEmptyTask &a_other) = delete;
    
    virtual void run() override;
};

} // advcpp

#endif // THREAD_POOL_EMPTY_TASK_HPP
