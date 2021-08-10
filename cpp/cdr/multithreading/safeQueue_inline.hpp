#include "lockGuard.hpp" // LockGuard Header
#include "safeQueue.hpp" // Safe Queue Header

template <typename T>
SafeQueue<T>::SafeQueue(const unsigned int a_initCapacity) 
: m_queue()
, m_lock()
, m_queueFreeSapces(IS_PSHARED, a_initCapacity)
, m_queueOccupiedPlaces(IS_PSHARED, 0)
, m_isRunningSafeQueue(true) {
}

template <typename T>
void SafeQueue<T>::Push(const T &a_value) {
    this->m_queueFreeSapces.Wait();
    LockGuard(this->m_lock);
    this->m_queue.push(a_value);
    this->m_queueOccupiedPlaces.Post();
}

template <typename T>
T SafeQueue<T>::Pop() {
    this->m_queueFreeSapces.Wait();
    LockGuard(this->m_lock);
    T frontElement = this->m_queue.front();
    this->m_queue.pop();
    this->m_queueOccupiedPlaces.Post();
    return frontElement;
}

template <typename T>
T &SafeQueue<T>::Front() {
    LockGuard(this->m_lock);
    return this->m_queue.front();
}

template <typename T>
T &SafeQueue<T>::Tail() {
    LockGuard(this->m_lock);
    return this->m_queue.front();
}

template <typename T>
bool SafeQueue<T>::IsEmpty() {
    LockGuard(this->m_lock);
    return this->m_queue.empty();
}

template <typename T>
size_t SafeQueue<T>::GetSize() {
    LockGuard(this->m_lock);
    return this->m_queue.size();
}

template <typename T>
bool SafeQueue<T>::CheckIfSafeQueueRunning() {
    return this->m_isRunningSafeQueue;
}

template <typename T>
void SafeQueue<T>::StopSafeQueue() {
    this->m_isRunningSafeQueue = false;
}