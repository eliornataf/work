/*****************************************************************************
* File Name: Hash Map
* Written by: Elior Nataf
* Date: 23/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __HASH_MAP_HPP__
#define __HASH_MAP_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <list> /* std::list */
#include <string> /* keyType */
#include <vector> /* std::vector */
#include "bookInfo.hpp" /* Book Info Header */
#include "entry.hpp" /* Entry Header */
#include "hashFunc.hpp" /* Hash Function */
#include "hashMapIter.hpp" /* Hash Map Iter Header */
#include "containerUtilites.hpp" /* Container Utilites Header */

/*-------------------------------- Structure -------------------------------*/

class HashMap {
public:
    // Enum

    enum Status {
        SUCCEEDED = 0,
        FAILED
    };

    // Constructor

    HashMap(const size_t &a_initSize, const HashFunc &a_hashFunc);

    // Destructor

    ~HashMap() = default;

    // Copy Constructor

    HashMap(const HashMap &a_other) = default;

    // Assignment Operator

    HashMap &operator=(const HashMap &a_other) = default;

    // Functions

    Status Insert(const keyType &a_key, const valueType &a_value);
    Status Remove(const keyType &a_key);
    innerContainer::const_iterator Find(const keyType &a_key);

    HashMapIter Begin() const;
    HashMapIter End() const;
    
private:   
    // Functions

    innerContainer::const_iterator FindEntry(const innerContainer &a_container, const keyType &a_key);

    //  Struct Members

    outerContainer m_container;
    HashFunc m_hashFunc;
};

#endif /* __HASH_MAP_HPP__ */
