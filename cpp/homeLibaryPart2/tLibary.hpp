/*****************************************************************************
* File Name: T Libary
* Written by: Elior Nataf
* Date: 13/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __T_LIBARY_H__
#define __T_LIBARY_H__

/*------------------------------- Header Files ------------------------------*/

#include <list> /* std::list */

/*-------------------------------- Structure -------------------------------*/

template <typename T>
class TLibary {
public:   
    // Constructor

    TLibary();

    // Destructor

    ~TLibary();

    // Copy Constructor

    TLibary(const TLibary &a_other);

    // Assignment Operator

    TLibary &operator=(const TLibary &a_other);

    // Functions

    void Add(T a_itemToAdd);
    typename std::list<T>::const_iterator Begin() const;
    typename std::list<T>::const_iterator End() const;
    
private:
    //  Struct members
    
    std::list<T> m_myLibary;
};

#endif /* __T_LIBARY_H__ */
