#include <cstdio> /* scanf */
#include <stdexcept> /* throw */
#include "endLine.hpp" /* EndLine Header */
#include "input.hpp" /* Input Header */

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

Input &Input::operator>>(char *a_str) {
    if (!a_str) {
        throw std::invalid_argument("NULL pointer error");
    }

    scanf("%s", a_str);

    return *this;
}

Input &Input::operator>>(char &a_char) {
    scanf(" %c", &a_char);

    return *this;
}

Input &Input::operator>>(double &a_floatingNumber) {
    scanf("%lf", &a_floatingNumber);

    return *this;
}

Input &Input::operator>>(int &a_wholeNumber) {
    scanf("%d", &a_wholeNumber);

    return *this;
}

Input &Input::operator>>(unsigned int &a_wholeNumber) {
    scanf("%u", &a_wholeNumber);

    return *this;
}

Input &Input::operator>>(long &a_wholeNumber) {
    scanf("%li", &a_wholeNumber);

    return *this;
}

Input &Input::operator>>(unsigned long &a_wholeNumber) {
    scanf("%lu", &a_wholeNumber);

    return *this;
}

Input &Input::operator>>(const EndLine &a_endLine) {
    (void)a_endLine;

    char ch;
    scanf("%[^\n]", &ch);

    return *this;
}