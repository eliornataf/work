/*****************************************************************************
* File Name: String Part 2
* Written by: Elior Nataf
* Date: 9/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __STRING_PART_2_H__
#define __STRING_PART_2_H__

/*------------------------------- Header Files ------------------------------*/

#include <cstddef> /* size_t */

/*-------------------------------- Structure -------------------------------*/

class StringPart2 {
public:   
    // Constructor

    StringPart2();
    StringPart2(const char *a_str);

    // Destructor

    ~StringPart2();

    // Copy Constructor

    StringPart2(const StringPart2 &a_other);

    // Assignment Operator

    StringPart2 &operator=(const StringPart2 &a_other);

    // Functions

    bool operator==(const StringPart2 &a_other) const;
    bool operator!=(const StringPart2 &a_other) const;
    bool operator>(const StringPart2 &a_other) const;
    bool operator<(const StringPart2 &a_other) const;
    bool operator>=(const StringPart2 &a_other) const;
    bool operator<=(const StringPart2 &a_other) const;

    StringPart2 operator+(const StringPart2 &a_other) const;
    StringPart2 operator-(const StringPart2 &a_other) const;
    StringPart2 &operator+=(const StringPart2 &a_other);
    StringPart2 &operator++();
    StringPart2 operator++(int);
    StringPart2 operator<<(const size_t a_numOfShifts);
    StringPart2 operator>>(const size_t a_numOfShifts);
    char &operator[](const size_t a_index) const;
    StringPart2 operator+() const;
    StringPart2 operator-() const;
    StringPart2 operator!() const;

    void Print() const;

private:
    //  Struct members
    
    size_t m_strLength;
    char *m_str;
};

#endif /* __STRING_PART_2_H__ */
