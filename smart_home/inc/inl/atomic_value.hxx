#ifndef ATOMIC_VALUE_HXX
#define ATOMIC_VALUE_HXX

template <typename T>
AtomicValue<T>::AtomicValue(T a_value) 
: m_value(a_value) 
{
    assert(std::is_arithmetic<T>::value);
}

template <typename T>
void AtomicValue<T>::operator=(const T a_value)
{
    Set(a_value);
}

template <typename T>
void AtomicValue<T>::operator++()
{
    Set(Get() + 1);
}

template <typename T>
void AtomicValue<T>::operator--()
{
    Set(Get() - 1);
}

template <typename T>
void AtomicValue<T>::Set(const T a_value)
{
    T currentValue = m_value;
    T returnValue = __sync_val_compare_and_swap(&m_value, currentValue, a_value);

    while (currentValue != returnValue) 
    {
        currentValue = m_value;
        returnValue = __sync_val_compare_and_swap(&m_value, currentValue, a_value);
    }
}

template <typename T>
T AtomicValue<T>::Get() const
{
    return __sync_add_and_fetch(&m_value, T());
}

#endif // ATOMIC_VALUE_HXX