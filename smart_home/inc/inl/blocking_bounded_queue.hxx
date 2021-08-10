#include <climits> // ULONG_MAX
#include <stdexcept> // std::runtime_error

static size_t CheckCapacity(size_t a_queueCapacity) 
{
    if (!a_queueCapacity)
    {
        throw std::runtime_error("capacity is zero");
    }

    return a_queueCapacity;
}

template <typename T>
BlockingBoundedQueue<T>::BlockingBoundedQueue(const size_t a_queueCapacity) 
: m_queue()
, m_queueCapacity(CheckCapacity(a_queueCapacity))
, m_queueFreeSapces(a_queueCapacity)
, m_queueOccupiedPlaces(0)
, m_mutex()
, m_isAliveQueue(true)
, m_numberOfWaitingEnqueue(0)
, m_numberOfWaitingDequeue(0)
{
}

template <typename T>
BlockingBoundedQueue<T>::~BlockingBoundedQueue()
{
    m_isAliveQueue.Clear();

    FreeBlockedThreads(m_queueFreeSapces, m_numberOfWaitingEnqueue.Get());
    FreeBlockedThreads(m_queueOccupiedPlaces, m_numberOfWaitingDequeue.Get());
}

template <typename T>
bool BlockingBoundedQueue<T>::Enqueue(const T &a_value) 
{
    if (m_isAliveQueue.Get())
    {
        ++m_numberOfWaitingEnqueue;

        m_queueFreeSapces.Wait();

        if (!m_isAliveQueue.Get())
        {
            return false;
        }

        --m_numberOfWaitingEnqueue;

        {
            LockGuard lockGuard(m_mutex);

            try {
                m_queue.push(a_value);
            }
            catch(...) {
                m_queueFreeSapces.Post();
                throw;
            }
        }

        m_queueOccupiedPlaces.Post();

        return true;
    }

    return false;
}

template <typename T>
bool BlockingBoundedQueue<T>::Dequeue(T &a_returnValue) 
{
    if (m_isAliveQueue.Get())
    {
        ++m_numberOfWaitingDequeue;
    
        m_queueOccupiedPlaces.Wait();
        
        if (!m_isAliveQueue.Get())
        {
            return false;
        }

        --m_numberOfWaitingDequeue;

        {
            LockGuard lockGuard(m_mutex);

            try {
                a_returnValue = m_queue.front();
            } catch(...) {
                m_queueOccupiedPlaces.Post();
                throw;
            }

            m_queue.pop();
        }

        m_queueFreeSapces.Post();

        return true;
    }

    return false;
}

template <typename T>
size_t BlockingBoundedQueue<T>::Capacity() const
{
    LockGuard lockGuard(m_mutex);

    return m_queueCapacity;
}

template <typename T>
size_t BlockingBoundedQueue<T>::Size() const
{
    LockGuard lockGuard(m_mutex);

    return m_queue.size();
}

template <typename T>
bool BlockingBoundedQueue<T>::IsEmpty() const
{
    LockGuard lockGuard(m_mutex);

    return m_queue.empty();
}

template <typename T>
bool BlockingBoundedQueue<T>::IsFull() const
{
    LockGuard lockGuard(m_mutex);
    
    return (m_queue.size() == m_queueCapacity);
}

///////////////////////////// Private Methods ///////////////////////////

template <typename T>
void BlockingBoundedQueue<T>::FreeBlockedThreads(Semaphore &a_sem, const size_t a_numberOfThreads)
{
    for (size_t i = a_numberOfThreads;0 < i;--i)
    {
        a_sem.Post();
    }
}