#ifndef MIN_STACK_HPP
#define MIN_STACK_HPP

#include <stack> // std::stack
#include <stdexcept> // throw

namespace advcpp {

template <typename T>
class MinStack {
public:
    MinStack() = default;
   ~MinStack() = default;

    MinStack(const MinStack &a_other) = delete;
    MinStack &operator=(const MinStack &a_other) = delete;

// Time Complexity: O(1)
// Space Complexity: O(1)
// Requires: operator<
    void Push(const T &a_element);

// Time Complexity: O(1)
// Space Complexity: O(1)
// Requires: operator==
    T Pop();

// Time Complexity: O(1)
// Space Complexity: O(1)
// Requires: operator*
    const T &Min() const;

private:
    std::stack<T> m_regularStack;
    std::stack<T*> m_minStack;
};

#include "inl/min_stack.hxx" // Min Stack Inline

} // advcpp

#endif /* MIN_STACK_HPP */
