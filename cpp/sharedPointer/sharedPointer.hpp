/*****************************************************************************
* File Name: Shared Pointer
* Written by: Elior Nataf
* Date: 7/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __SHARED_POINTER_HPP__
#define __SHARED_POINTER_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <cstddef> /* size_t */

/*-------------------------------- Structure -------------------------------*/

template <typename T>
class SharedPointer {
public:
    // Constructor

    SharedPointer();

    // Destructor

    ~SharedPointer();

    // Copy Constructor

    SharedPointer(const SharedPointer<T> &a_other);

    // Assignment Operator

    SharedPointer<T> &operator=(const SharedPointer<T> &a_other);

    // Move Constructor

    SharedPointer(SharedPointer<T> &&a_other);

    // Move Assignment Operator

    SharedPointer<T> &operator=(SharedPointer<T> &&a_other);

    // Functions

    T* operator->() const;
    T& operator*() const;
    T* GetPointer() const;
    size_t GetPointerRefCount() const;

private:
    // Constants

    static constexpr size_t ONE_REF = 1;

    // Functions

    void CleanUpExistData();

    // Class Members

    T *m_pointer;
    size_t *m_pointerRefCount;
};

#endif /* __SHARED_POINTER_HPP__ */
