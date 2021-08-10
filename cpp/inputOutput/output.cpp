#include <cstdio> /* printf, putchar */
#include <cctype> /* tolower, touppper */
#include <stdexcept> /* throw */
#include <cstring> /* memcpy, strlen */
#include "endLine.hpp" /* EndLine Header */
#include "output.hpp" /* Output Header */

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

// Constructor

Output::Output()
: m_letterCase(NORMAL) {
}

// Destructor

Output::~Output() {
}

// Copy Constructor

Output::Output(const Output &a_other) 
: m_letterCase(a_other.m_letterCase) {
}

// Assignment Operator

Output &Output::operator=(const Output &a_other){
    this->m_letterCase = a_other.m_letterCase;

    return *this;
}

// Functions

Output &Output::operator<<(const char *a_str) {
    if (!a_str) {
        throw std::invalid_argument("NULL pointer error");
    }

    if (NORMAL == this->m_letterCase) {
        printf("%s", a_str);
        return *this;
    }

    size_t stringLength = strlen(a_str) + sizeof('\0');
    char *newString = new char[stringLength];

    if (LOWER == this->m_letterCase) {
        for (size_t i = 0;i < stringLength;++i) {
            newString[i] = tolower(a_str[i]);
        }
    }
    else {
        for (size_t i = 0;i < stringLength;++i) {
            newString[i] = toupper(a_str[i]);
        }
    }

    newString[stringLength] = '\0';

    printf("%s", newString);

    delete[] newString;

    return *this;
}

Output &Output::operator<<(const char &a_char) {
    putchar(a_char);

    return *this;
}

Output &Output::operator<<(const double &a_floatingNumber) {
    printf("%f", a_floatingNumber);

    return *this;
}

Output &Output::operator<<(const int &a_wholeNumber) {
    printf("%d", a_wholeNumber);

    return *this;
}

Output &Output::operator<<(const unsigned int &a_wholeNumber) {
    printf("%u", a_wholeNumber);

    return *this;
}

Output &Output::operator<<(const long &a_wholeNumber) {
    printf("%li", a_wholeNumber);

    return *this;
}

Output &Output::operator<<(const unsigned long &a_wholeNumber) {
    printf("%lu", a_wholeNumber);

    return *this;
}

Output &Output::operator<<(const EndLine &a_endLine) {
    (void)a_endLine;

    putchar('\n');

    return *this;
}

Output &Output::operator<<(const LetterCase &a_letterCase) {
    if (NORMAL == a_letterCase) {
        m_letterCase = NORMAL;
    }
    else if (LOWER == a_letterCase) {
        m_letterCase = LOWER;
    }
    else if (UPPER == a_letterCase) {
        m_letterCase = UPPER;
    }
    else {
        throw std::invalid_argument("enum input error");
    }

    return *this;
}
