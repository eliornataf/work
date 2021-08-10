#include <iostream> /* cout */
#include <stdexcept> /* throw */
#include <string.h> /* strlen, strcpy, strcat, strcmp */
#include "string.hpp" /* String Header */

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static size_t CheckStrForStrlen(const char *a_str);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

String::String(const char *a_str)
: m_strLength(CheckStrForStrlen(a_str))
, m_str(new char[this->m_strLength + sizeof('\0')]) {
    memcpy(this->m_str, a_str, this->m_strLength + sizeof('\0'));
}

String::~String() {
    delete[] this->m_str;
}

String::String(const String &a_other) 
: m_strLength(CheckStrForStrlen(a_other.m_str))
, m_str(new char[this->m_strLength + sizeof('\0')]) {
    memcpy(this->m_str, a_other.m_str, this->m_strLength + sizeof('\0'));
}

String &String::operator=(const String &a_other) {
    if (!strcmp(a_other.m_str, this->m_str)) {
        return *this;
    }

    delete[] this->m_str;
    this->m_strLength = a_other.m_strLength;
    this->m_str = new char[this->m_strLength + sizeof('\0')];
    memcpy(this->m_str, a_other.m_str, this->m_strLength + sizeof('\0'));

    return *this;
}

void String::Print() const {
    std::cout << this->m_str << std::endl;
}

void String::operator+=(const String *a_string) {
    if (!a_string) {
        throw std::invalid_argument("NULL pointer error");
    }
    
    size_t strAfterConcatLength = strlen(this->m_str) + strlen(a_string->m_str);
    char *strAfterConcat = new char[strAfterConcatLength + sizeof('\0')];

    strcpy(strAfterConcat, this->m_str);
    strcat(strAfterConcat, a_string->m_str);

    delete[] this->m_str;

    this->m_strLength = strAfterConcatLength;
    this->m_str = strAfterConcat;
}

char &String::operator[](const size_t a_index) const {
    if (this->m_strLength - 1 < a_index)
    {
        throw std::out_of_range("Index is bigger then string length");
    }

    return this->m_str[a_index];
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