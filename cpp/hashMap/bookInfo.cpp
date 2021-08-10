#include <stdexcept> /* throw */
#include <string.h> /* strlen, strcpy */
#include "bookInfo.hpp" /* Book Info Header */

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static size_t CheckStrForStrlen(const char *a_str);
static size_t CheckReleaseYearInput(const size_t a_releaseYear, const size_t a_minYear, const size_t a_maxYear);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

BookInfo::BookInfo(const char *a_name, const char *a_authorName, const size_t a_releaseYear, const char *a_purchasedDate)
: m_name(new char[CheckStrForStrlen(a_name) + 1])
, m_authorName(new char[CheckStrForStrlen(a_authorName) + 1])
, m_releaseYear(CheckReleaseYearInput(a_releaseYear, MIN_YEAR, MAX_YEAR))
, m_purchasedDate(new char[CheckStrForStrlen(a_purchasedDate) + 1]) {
    strcpy(this->m_name, a_name);
    strcpy(this->m_authorName, a_authorName);
    strcpy(this->m_purchasedDate, a_purchasedDate);
}

BookInfo::~BookInfo() {
    delete[] this->m_name;
    delete[] this->m_authorName;
    delete[] this->m_purchasedDate;
}

BookInfo::BookInfo(const BookInfo &a_other) 
: m_name(new char[strlen(a_other.m_name) + 1])
, m_authorName(new char[strlen(a_other.m_authorName) + 1])
, m_releaseYear(a_other.m_releaseYear)
, m_purchasedDate(new char[strlen(a_other.m_purchasedDate) + 1]) {
    strcpy(this->m_name, a_other.m_name);
    strcpy(this->m_authorName, a_other.m_authorName);
    strcpy(this->m_purchasedDate, a_other.m_purchasedDate);
}

BookInfo &BookInfo::operator=(const BookInfo &a_other) {
    delete[] this->m_name;
    delete[] this->m_authorName;
    delete[] this->m_purchasedDate;

    this->m_name = new char[strlen(a_other.m_name) + 1];
    this->m_authorName = new char[strlen(a_other.m_authorName) + 1];
    this->m_releaseYear = a_other.m_releaseYear;
    this->m_purchasedDate = new char[strlen(a_other.m_purchasedDate) + 1];

    strcpy(this->m_name, a_other.m_name);
    strcpy(this->m_authorName, a_other.m_authorName);
    strcpy(this->m_purchasedDate, a_other.m_purchasedDate);

    return *this;
}

char *BookInfo::GetName() const {
    return this->m_name;
}

char *BookInfo::GetAutourName() const {
    return this->m_authorName;
}

size_t BookInfo::GetReleaseYear() const {
    return this->m_releaseYear;
}

char *BookInfo::GetPurchasedDate() const {
    return this->m_purchasedDate;
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

static size_t CheckReleaseYearInput(const size_t a_releaseYear, const size_t a_minYear, const size_t a_maxYear) {
    if (a_releaseYear < a_minYear || a_maxYear < a_releaseYear) {
        std::invalid_argument("releaseYear invalid input");
    }

    return a_releaseYear;
}

/******************************************************/