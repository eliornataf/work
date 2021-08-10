#include <stdexcept> /* throw */
#include <string.h> /* strlen, strcpy */
#include "movieInfo.hpp" /* Book Info Header */

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static size_t CheckStrForStrlen(const char *a_str);
static size_t CheckReleaseYearInput(const size_t a_releaseYear, const size_t a_minYear, const size_t a_maxYear);
static MovieInfo::Genre CheckGenreInput(const MovieInfo::Genre a_genre);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

MovieInfo::MovieInfo(const char *a_name, const char *a_directorName, const Genre a_genre, const size_t a_releaseYear, const char *a_purchasedDate)
: m_name(new char[CheckStrForStrlen(a_name) + 1])
, m_directorName(new char[CheckStrForStrlen(a_directorName) + 1])
, m_genre(CheckGenreInput(a_genre))
, m_releaseYear(CheckReleaseYearInput(a_releaseYear, MIN_YEAR, MAX_YEAR))
, m_purchasedDate(new char[CheckStrForStrlen(a_purchasedDate) + 1]) {
    strcpy(this->m_name, a_name);
    strcpy(this->m_directorName, a_directorName);
    strcpy(this->m_purchasedDate, a_purchasedDate);
}

MovieInfo::~MovieInfo() {
    delete[] this->m_name;
    delete[] this->m_directorName;
    delete[] this->m_purchasedDate;
}

MovieInfo::MovieInfo(const MovieInfo &a_other) 
: m_name(new char[strlen(a_other.m_name) + 1])
, m_directorName(new char[strlen(a_other.m_directorName) + 1])
, m_genre(a_other.m_genre)
, m_releaseYear(a_other.m_releaseYear)
, m_purchasedDate(new char[strlen(a_other.m_purchasedDate) + 1]) {
    strcpy(this->m_name, a_other.m_name);
    strcpy(this->m_directorName, a_other.m_directorName);
    strcpy(this->m_purchasedDate, a_other.m_purchasedDate);
}

MovieInfo &MovieInfo::operator=(const MovieInfo &a_other) {
    delete[] this->m_name;
    delete[] this->m_directorName;
    delete[] this->m_purchasedDate;

    this->m_name = new char[strlen(a_other.m_name) + 1];
    this->m_directorName = new char[strlen(a_other.m_directorName) + 1];
    this->m_genre = a_other.m_genre;
    this->m_releaseYear = a_other.m_releaseYear;
    this->m_purchasedDate = new char[strlen(a_other.m_purchasedDate) + 1];

    strcpy(this->m_name, a_other.m_name);
    strcpy(this->m_directorName, a_other.m_directorName);
    strcpy(this->m_purchasedDate, a_other.m_purchasedDate);

    return *this;
}

const char *MovieInfo::GetName() const {
    return this->m_name;
}

const char *MovieInfo::GetDirectorName() const {
    return this->m_directorName;
}

const MovieInfo::Genre MovieInfo::GetMovieGenre() const {
    return this->m_genre;
}

const size_t MovieInfo::GetReleaseYear() const {
    return this->m_releaseYear;
}

const char *MovieInfo::GetPurchasedDate() const {
    return this->m_purchasedDate;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static size_t CheckStrForStrlen(const char *a_str) {
    if (!a_str)
    {
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

static MovieInfo::Genre CheckGenreInput(const MovieInfo::Genre a_genre) {
    if (a_genre < MovieInfo::ACTION || MovieInfo::OTHER < a_genre) {
        std::invalid_argument("Genre invalid input");
    }

    return a_genre;
}

/******************************************************/