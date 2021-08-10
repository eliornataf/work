#include "../inc/latch.hpp" // Latch Header

using namespace advcpp;

Latch::Latch()
: m_conditionVaraiable()
, m_mutex()
, m_atomicValue(0)
{
}

void Latch::SetAtomicValue(unsigned int a_value)
{
    m_atomicValue = a_value;
}

void Latch::Wait()
{
    std::unique_lock<std::mutex> uniqueLock(m_mutex);
    
    while (0 != m_atomicValue.Get())
    {    
        try
        {
            m_conditionVaraiable.wait(uniqueLock);
        }
        catch(...)
        {
            // do noting
        }
    }
}

void Latch::CountDown()
{
    if (0 != m_atomicValue.Get())
    {
        --m_atomicValue;
        m_conditionVaraiable.notify_all();
    }
}

size_t Latch::GetAtomicValueSize() const
{
    return m_atomicValue.Get();
}
