/*****************************************************************************
* File Name: String 
* Written by: Elior Nataf
* Date: 3/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __STRING_H__
#define __STRING_H__

/*------------------------------- Header Files ------------------------------*/

#include <cstddef> /* size_t */

/*-------------------------------- Structure -------------------------------*/

class String {
public:   
    // Constructor

    String(const char *a_str);

    // Destructor

    ~String();

    // Copy Constructor

    String(const String &a_other);

    // Assignment Operator

    String &operator=(const String &a_other);

    // Functions

    void Print() const;
    void operator+=(const String *a_string);
    char &operator[](const size_t a_index) const;

private:
    //  Struct members
    
    size_t m_strLength;
    char *m_str;
};

/*-------------------------------------------------------------------------*/

#endif /* __STRING_H__ */
