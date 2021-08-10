#include <ctype.h> /* islower, isupper, tolower, toupper */
#include <iostream> /* cout */
#include <stdexcept> /* throw */
#include <string.h> /* memcpy, memset, strlen, strcpy, strcat, strcmp, strstr */
#include "stringPart2.hpp" /* String Part 2 Header */

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static size_t CheckStrForStrlen(const char *a_str);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

StringPart2::StringPart2()
: m_strLength(0)
, m_str(new char[sizeof('\0')]) {;
}

StringPart2::StringPart2(const char *a_str)
: m_strLength(CheckStrForStrlen(a_str))
, m_str(new char[this->m_strLength + sizeof('\0')]) {
    memcpy(this->m_str, a_str, this->m_strLength + sizeof('\0'));
}

StringPart2::~StringPart2() {
    delete[] this->m_str;
}

StringPart2::StringPart2(const StringPart2 &a_other) 
: m_strLength(CheckStrForStrlen(a_other.m_str))
, m_str(new char[this->m_strLength + sizeof('\0')]) {
    memcpy(this->m_str, a_other.m_str, this->m_strLength + sizeof('\0'));
}

StringPart2 &StringPart2::operator=(const StringPart2 &a_other) {
    if (this != &a_other) {
        delete[] this->m_str;
        this->m_strLength = a_other.m_strLength;
        this->m_str = new char[this->m_strLength + sizeof('\0')];
        memcpy(this->m_str, a_other.m_str, this->m_strLength + sizeof('\0'));
    }

    return *this;
}

bool StringPart2::operator==(const StringPart2 &a_other) const {
    return !strcmp(this->m_str, a_other.m_str);
}

bool StringPart2::operator!=(const StringPart2 &a_other) const {
    return strcmp(this->m_str, a_other.m_str);
}

bool StringPart2::operator>(const StringPart2 &a_other) const {
    return (0 < strcmp(this->m_str, a_other.m_str));
}

bool StringPart2::operator<(const StringPart2 &a_other) const {
    return (strcmp(this->m_str, a_other.m_str) < 0);
}

bool StringPart2::operator>=(const StringPart2 &a_other) const {
    return (0 <= strcmp(this->m_str, a_other.m_str));
}

bool StringPart2::operator<=(const StringPart2 &a_other) const {
    return (strcmp(this->m_str, a_other.m_str) <= 0);
}

StringPart2 StringPart2::operator+(const StringPart2 &a_other) const {
    size_t strAfterConcatLength = strlen(this->m_str) + strlen(a_other.m_str);
    char *strAfterConcat = new char[strAfterConcatLength + sizeof('\0')];

    strcpy(strAfterConcat, this->m_str);
    strcat(strAfterConcat, a_other.m_str);
    
    StringPart2 newString(strAfterConcat);
    newString.m_strLength = strAfterConcatLength;

    delete[] strAfterConcat;

    return newString;
}

StringPart2 StringPart2::operator-(const StringPart2 &a_other) const {
    if (!strstr(this->m_str, a_other.m_str)) {
        return StringPart2();
    }
    
    size_t strAfterMinusLength = strlen(this->m_str) - strlen(a_other.m_str);
    char *strAfterMinus = new char[strAfterMinusLength + sizeof('\0')];

    strcpy(strAfterMinus, this->m_str);

    StringPart2 newString(strAfterMinus);
    newString.m_strLength = strAfterMinusLength;

    delete[] strAfterMinus;

    return newString;
}

StringPart2 &StringPart2::operator+=(const StringPart2 &a_other) {
    return *this = this->operator+(a_other);
}

StringPart2 &StringPart2::operator++() {
    size_t strAfterConcatLength = strlen(this->m_str) + sizeof(char);
    char *strAfterConcat = new char[strAfterConcatLength + sizeof('\0')];

    strcpy(strAfterConcat, this->m_str);
    strcat(strAfterConcat, "!");

    delete[] this->m_str;

    this->m_str = strAfterConcat;
    this->m_strLength = strAfterConcatLength;

    return *this;
}

StringPart2 StringPart2::operator++(int) {
    StringPart2 newString(*this);

    this->operator++();

    return newString;
}

StringPart2 StringPart2::operator<<(const size_t a_numOfShifts) {
    if (this->m_strLength < a_numOfShifts) {
        return StringPart2();
    }

    size_t strAfterShiftLength = strlen(this->m_str) - a_numOfShifts;
    char *strAfterShift = new char[strAfterShiftLength + sizeof('\0')];
    
    char *stringAfterShiftLeft = this->m_str;
    stringAfterShiftLeft += a_numOfShifts;

    strcpy(strAfterShift, stringAfterShiftLeft);

    StringPart2 newString(strAfterShift);
    newString.m_strLength = strAfterShiftLength;

    delete[] strAfterShift;

    return newString;
}

StringPart2 StringPart2::operator>>(const size_t a_numOfShifts) {
    if (this->m_strLength < a_numOfShifts) {
        return StringPart2();
    }

    size_t strAfterShiftLength = strlen(this->m_str) - a_numOfShifts;
    char *strAfterShift = new char[strAfterShiftLength + sizeof('\0')];

    strncpy(strAfterShift, this->m_str, strAfterShiftLength);

    StringPart2 newString(strAfterShift);
    newString.m_strLength = strAfterShiftLength;

    delete[] strAfterShift;

    return newString;
}

char &StringPart2::operator[](const size_t a_index) const {
    if (this->m_strLength - 1 < a_index) {
        throw std::out_of_range("Index is bigger then string length");
    }

    return this->m_str[a_index];
}

StringPart2 StringPart2::operator+() const {
    char *strAfterPlus = new char[this->m_strLength + sizeof('\0')];

    memset(strAfterPlus, '+', this->m_strLength);
    strAfterPlus[this->m_strLength] = '\0';

    StringPart2 newString(strAfterPlus);
    newString.m_strLength = this->m_strLength;

    delete[] strAfterPlus;

    return newString;
}

StringPart2 StringPart2::operator-() const {
    char *strAfterMinus = new char[this->m_strLength + sizeof('\0')];

    memset(strAfterMinus, '-', this->m_strLength);
    strAfterMinus[this->m_strLength] = '\0';

    StringPart2 newString(strAfterMinus);
    newString.m_strLength = this->m_strLength;

    delete[] strAfterMinus;

    return newString;
}

StringPart2 StringPart2::operator!() const {
    char *strAfterLetterChange = new char[this->m_strLength + sizeof('\0')]; 
    size_t i = 0;

    for (;i < this->m_strLength;++i) {
        char currChar = this->m_str[i];
        strAfterLetterChange[i] = islower(currChar) ? toupper(currChar) : tolower(currChar);
    }

    strAfterLetterChange[i] = '\0';

    StringPart2 newString(strAfterLetterChange);
    newString.m_strLength = this->m_strLength;

    delete[] strAfterLetterChange;

    return newString;
}

void StringPart2::Print() const {
    std::cout << this->m_str << std::endl;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static size_t CheckStrForStrlen(const char *a_str) {
    if (!a_str) {
        throw std::invalid_argument("NULL pointer error");
    }

    return strlen(a_str);
}

/******************************************************/