#ifndef LOCK_GUARD_HPP
#define LOCK_GUARD_HPP

#include <mutex> // std::mutex

namespace advcpp {

class LockGuard {
public:
    LockGuard(std::mutex &a_mutex);
    ~LockGuard();

    LockGuard(const LockGuard &a_other) = delete;
    LockGuard &operator=(const LockGuard &a_other) = delete;

private:
    std::mutex &m_mutex;
};

} // advcpp

#endif // LOCK_GUARD_HPP
