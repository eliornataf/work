#include <stdexcept> /* throw */
#include "sharedPointer.hpp" /* Shared Pointer Header */

template <typename T>
void SharedPointer<T>::CleanUpExistData() {
    if (ONE_REF < *this->m_pointerRefCount) {
        --(*this->m_pointerRefCount); 
    }
    else {
        if (this->m_pointer) {
            delete this->m_pointer;
        }
        delete this->m_pointerRefCount;
    }    
}

template <typename T>
SharedPointer<T>::SharedPointer()
: m_pointer(nullptr)
, m_pointerRefCount(new int {0}) {
}

template <typename T>
SharedPointer<T>::~SharedPointer() {
    this->CleanUpExistData();
}

template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T> &a_other)
: m_pointer(a_other.m_pointer)
, m_pointerRefCount(a_other.m_pointerRefCount) {
    if (this->m_pointer) {
        ++(*(this->m_pointerRefCount));
    }
}

template <typename T>
SharedPointer<T> &SharedPointer<T>::operator=(const SharedPointer<T> &a_other) {
    if (this != &a_other) {
        this->CleanUpExistData();
        
        this->m_pointer = a_other.m_pointer;
        this->m_pointerRefCount = a_other.m_pointerRefCount;

        if (this->m_pointer) {
            ++(*(this->m_pointerRefCount));
        }
    }

    return *this;
}

template <typename T>
SharedPointer<T>::SharedPointer(SharedPointer<T> &&a_other)
: m_pointer(a_other.m_pointer)
, m_pointerRefCount(a_other.m_pointerRefCount) {
    a_other.m_pointer = nullptr;
    a_other.m_pointerRefCount = nullptr;
}

template <typename T>
SharedPointer<T> &SharedPointer<T>::operator=(SharedPointer<T> &&a_other) {
     if (this != &a_other) {
        this->CleanUpExistData();
        
        this->m_pointer = a_other.m_pointer;
        this->m_pointerRefCount = a_other.m_pointerRefCount;

        if (this->m_pointer) {
            ++(*(this->m_pointerRefCount));
        }

        a_other.m_pointer = nullptr;
        a_other.m_pointerRefCount = nullptr;
    }

    return *this;
}

template <typename T>
T* SharedPointer<T>::operator->() const {
    if (!this->m_pointer) {
        std::invalid_argument("NULL pointer error");
    }

    return this->m_pointer;
}

template <typename T>
T& SharedPointer<T>::operator*() const {
    if (!this->m_pointer) {
        std::invalid_argument("NULL pointer error");
    }

    return (*(this->m_pointer));
}

template <typename T>
T* SharedPointer<T>::GetPointer() const {
    return this->m_pointer;
}

template <typename T>
size_t SharedPointer<T>::GetPointerRefCount() const {
    return (*(this->m_pointerRefCount));
}
