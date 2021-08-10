/*****************************************************************************
* File Name: Hash Function
* Written by: Elior Nataf
* Date: 23/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __HASH_FUNCTION_HPP__
#define __HASH_FUNCTION_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <string> /* std::string */
#include "typesUtilites.hpp" /* Types Utilites Header */

/*-------------------------------- Structure -------------------------------*/

class HashFunc {
public:
    // Functions

    size_t GetIndex(const keyType &a_key) const;
};

#endif /* __HASH_FUNCTION_HPP__ */