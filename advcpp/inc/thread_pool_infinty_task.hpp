#ifndef THREAD_POOL_INFINITY_HPP
#define THREAD_POOL_INFINITY_HPP

#include "latch.hpp" // Latch
#include "runnable.hpp" // Runnable

namespace advcpp {

class ThreadPoolInfinityTask : public Runnable {
public:
    ThreadPoolInfinityTask(std::shared_ptr<Latch> a_latch);
    ~ThreadPoolInfinityTask() = default;

    ThreadPoolInfinityTask(const ThreadPoolInfinityTask &a_other) = delete;
    ThreadPoolInfinityTask &operator=(const ThreadPoolInfinityTask &a_other) = delete;
    
    virtual void run() override;

private:
    std::shared_ptr<Latch> m_latch;
};

} // advcpp

#endif // THREAD_POOL_INFINITY_HPP
