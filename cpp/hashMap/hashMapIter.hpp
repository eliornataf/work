/*****************************************************************************
* File Name: Hash Map Iteration
* Written by: Elior Nataf
* Date: 23/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __HASH_MAP_ITER_HPP__
#define __HASH_MAP_ITER_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <deque> /* std::deque */
#include <iterator> /* std::iterator */
#include <list> /* std::list */
#include "entry.hpp" /* Entry Header */
#include "containerUtilites.hpp" /* Container Utilites Header */
#include "typesUtilites.hpp" /* Types Utilties */

/*-------------------------------- Structure -------------------------------*/

class HashMapIter : std::iterator<std::forward_iterator_tag, outerContainer> {
public:
    // Constructor

    HashMapIter() = default;
    HashMapIter(const innerContainer::const_iterator &a_currInnerContainer, const innerContainer::const_iterator &a_endInnerContainer, const outerContainer::const_iterator &a_currOuterContainer, const outerContainer::const_iterator &a_endOuterContainer);

    // Destructor

    ~HashMapIter() = default;

    // Copy Constructor

    HashMapIter(const HashMapIter &a_other) = default;

    // Assignment Operator

    HashMapIter &operator=(const HashMapIter &a_other) = default;

    // Functions
    
    HashMapIter &operator++();
    valueType operator*() const;

    bool operator==(const HashMapIter &a_other) const;
    bool operator!=(const HashMapIter &a_other) const;
    
private:   
    //  Struct Members

    innerContainer::const_iterator m_currInnerContainer;
    innerContainer::const_iterator m_endInnerContainer;
    outerContainer::const_iterator m_currOuterContainer;
    outerContainer::const_iterator m_endOuterContainer;
};

#endif /* __HASH_MAP_ITER_HPP__ */
