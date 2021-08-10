/*****************************************************************************
* File Name: Input
* Written by: Elior Nataf
* Date: 10/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __INPUT_H__
#define __INPUT_H__

/*------------------------------- Header Files ------------------------------*/

#include "endLine.hpp" /* EndLine Header */

/*-------------------------------- Structure -------------------------------*/

class Input {
public:   
    // Constructor

    Input() = default;

    // Destructor

    ~Input() = default;

    // Copy Constructor

    Input(const Input &a_other) = default;

    // Assignment Operator

    Input &operator=(const Input &a_other) = default;

    // Functions

    Input &operator>>(char *a_str);
    Input &operator>>(char &a_char);
    Input &operator>>(double &a_floatingNumber);
    Input &operator>>(int &a_wholeNumber);
    Input &operator>>(unsigned int &a_wholeNumber);
    Input &operator>>(long &a_wholeNumber);
    Input &operator>>(unsigned long &a_wholeNumber);
    Input &operator>>(const EndLine &a_endLine);
};

#endif /* __INPUT_H__ */
