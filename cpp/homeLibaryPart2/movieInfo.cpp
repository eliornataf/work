#include <stdexcept> /* throw */
#include <string> /* std::string */
#include "artWork.hpp" /* Art Work Header */
#include "movieInfo.hpp" /* Book Info Header */

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static MovieInfo::Genre CheckGenreInput(const MovieInfo::Genre a_genre);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

MovieInfo::MovieInfo(const std::string &a_movieName, const std::string &a_directorName, const Genre &a_genre, const size_t &a_releaseYear, const size_t &addedTimeToCollection)
: ArtWork(a_movieName, a_directorName, a_releaseYear, std::string("Movie"), addedTimeToCollection)
, m_genre(CheckGenreInput(a_genre)) {
}

MovieInfo::~MovieInfo() {
}

MovieInfo::MovieInfo(const MovieInfo &a_other) 
: ArtWork(a_other)
, m_genre(a_other.m_genre) {
}

MovieInfo &MovieInfo::operator=(const MovieInfo &a_other) {
    this->ArtWork::operator=(a_other);
    this->m_genre = a_other.m_genre;

    return *this;
}

const MovieInfo::Genre MovieInfo::GetMovieGenre() const {
    return this->m_genre;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static MovieInfo::Genre CheckGenreInput(const MovieInfo::Genre a_genre) {
    if (a_genre < MovieInfo::ACTION || MovieInfo::OTHER < a_genre) {
        std::invalid_argument("Genre invalid input");
    }

    return a_genre;
}

/******************************************************/