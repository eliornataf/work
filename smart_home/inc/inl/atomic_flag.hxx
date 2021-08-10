#ifndef ATOMIC_FLAG_HXX
#define ATOMIC_FLAG_HXX

inline AtomicFlag::AtomicFlag(bool a_value)
: m_value(a_value)
{
}

inline void AtomicFlag::Clear()
{
    __sync_and_and_fetch(&m_value, 0);
}

inline void AtomicFlag::Set()
{
    __sync_or_and_fetch(&m_value, 1);
}

inline bool AtomicFlag::Get() const
{
    return __sync_add_and_fetch(&m_value, 0);
}

#endif // ATOMIC_FLAG_HXX
