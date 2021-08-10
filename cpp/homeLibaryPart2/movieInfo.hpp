/*****************************************************************************
* File Name: Movie Info 
* Written by: Elior Nataf
* Date: 13/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __MOVIE_INFO_H__
#define __MOVIE_INFO_H__

/*------------------------------- Header Files ------------------------------*/

#include <cstddef> /* size_t */
#include <string> /* std::string */
#include "artWork.hpp" /* Art Work Header */

/*-------------------------------- Structure -------------------------------*/

class MovieInfo : public ArtWork {
public:
    // Enum

    enum Genre {
        ACTION = 0,
        COMEDY,
        DRAMA,
        ANIME,
        OTHER
    };

    // Constructor

    MovieInfo(const std::string &a_movieName, const std::string &a_directorName, const Genre &a_genre, const size_t &a_releaseYear, const size_t &addedTimeToCollection);

    // Destructor

    ~MovieInfo();

    // Copy Constructor

    MovieInfo(const MovieInfo &a_other);

    // Assignment Operator

    MovieInfo &operator=(const MovieInfo &a_other);

    // Functions

    const Genre GetMovieGenre() const; 

private:
    //  Struct members
    
    Genre m_genre;
};

#endif /* __MOVIE_INFO_H__ */
