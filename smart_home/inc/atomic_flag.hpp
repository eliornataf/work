#ifndef ATOMIC_FLAG_HPP 
#define ATOMIC_FLAG_HPP 

namespace advcpp {

class AtomicFlag {
public: 
    AtomicFlag(bool a_value = false);

    ~AtomicFlag() = default;

    AtomicFlag(const AtomicFlag &a_other) = delete;
    AtomicFlag &operator=(const AtomicFlag &a_other) = delete;

    void Clear();
    void Set();

    bool Get() const;

private:
    mutable unsigned int m_value;
};

#include "inl/atomic_flag.hxx" // Atomic Flag Inline

} // advcpp

#endif // ATOMIC_FLAG_HPP