#ifndef ATOMIC_VALUE_HPP 
#define ATOMIC_VALUE_HPP 

#include <cassert> // assert
#include <type_traits> // std::type_traits

namespace advcpp {

template <typename T>
class AtomicValue {
public:
    explicit AtomicValue(T a_value);
    ~AtomicValue() = default;

    AtomicValue(const AtomicValue &a_other) = delete;
    AtomicValue &operator=(const AtomicValue &a_other) = delete;

    void operator=(const T a_value);
    void operator++();
    void operator--();

    void Set(const T a_value);
    T Get() const;

private:
    mutable T m_value;
};

#include "inl/atomic_value.hxx" // Atomic Value Inline

} // advcpp

#endif // ATOMIC_VALUE_HPP