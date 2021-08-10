/*****************************************************************************
* File Name: Output
* Written by: Elior Nataf
* Date: 10/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __OUTPUT_H__
#define __OUTPUT_H__

/*------------------------------- Header Files ------------------------------*/

#include "endLine.hpp" /* EndLine Header */

/*-------------------------------- Structure -------------------------------*/

class Output {
public:   
    // Enum

    enum LetterCase {
        NORMAL = 0,
        LOWER,
        UPPER
    };

    // Constructor

    Output();

    // Destructor

    ~Output();

    // Copy Constructor

    Output(const Output &a_other);

    // Assignment Operator

    Output &operator=(const Output &a_other);

    // Functions

    Output &operator<<(const char *a_str);
    Output &operator<<(const char &a_char);
    Output &operator<<(const double &a_floatingNumber);
    Output &operator<<(const int &a_wholeNumber);
    Output &operator<<(const unsigned int &a_wholeNumber);
    Output &operator<<(const long &a_wholeNumber);
    Output &operator<<(const unsigned long &a_wholeNumber);
    Output &operator<<(const EndLine &a_endLine);
    Output &operator<<(const LetterCase &a_letterCase);

private:
    // Struct members

    LetterCase m_letterCase;
};

#endif /* __OUTPUT_H__ */
