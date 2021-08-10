#ifndef MIN_STACK_HXX
#define MIN_STACK_HXX

template <typename T>
void MinStack<T>::Push(const T &a_element) 
{
    m_regularStack.push(a_element);

    if (m_minStack.empty() || const_cast<T&>(a_element) < *m_minStack.top()) 
    {
        m_minStack.push(&m_regularStack.top());
    }
}

template <typename T>
T MinStack<T>::Pop() 
{
    if (m_regularStack.empty())
    {
        throw std::runtime_error("stack is empty");
    }

    T& popedElement = m_regularStack.top();
    m_regularStack.pop();

    if (&popedElement == m_minStack.top()) 
    {
        m_minStack.pop();
    }

    return popedElement;
}

template <typename T>
const T &MinStack<T>::Min() const
{
    if (m_minStack.empty())
    {
        throw std::runtime_error("min stack is empty");
    }

    return *m_minStack.top();
}

#endif // MIN_STACK_HXX
