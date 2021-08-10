/*****************************************************************************
* File Name: Entry
* Written by: Elior Nataf
* Date: 23/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __ENTRY_HPP__
#define __ENTRY_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <string> /* std::string */
#include "bookInfo.hpp" /* Book Info Header */
#include "typesUtilites.hpp" /* Types Utilties */

/*-------------------------------- Structure -------------------------------*/

class Entry {
public:
    // Constructor

    Entry(const keyType &a_key, const valueType &a_value);

    // Destructor

    ~Entry();

    // Copy Constructor

    Entry(const Entry &a_other);

    // Assignment Operator

    Entry &operator=(const Entry &a_other);

    // Functions

    keyType GetKey() const;
    valueType GetValue() const;
    
private:
    //  Struct Members

    std::string m_key;
    BookInfo m_value;
};

#endif /* __ENTRY_HPP__ */
