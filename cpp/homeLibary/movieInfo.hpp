/*****************************************************************************
* File Name: Movie Info 
* Written by: Elior Nataf
* Date: 6/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __MOVIE_INFO_H__
#define __MOVIE_INFO_H__

/*------------------------------- Header Files ------------------------------*/

#include <cstddef> /* size_t */

/*-------------------------------- Structure -------------------------------*/

class MovieInfo {
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

    MovieInfo(const char *a_name, const char *a_directorName, const Genre a_genre, const size_t a_releaseYear, const char *a_purchasedDate);

    // Destructor

    ~MovieInfo();

    // Copy Constructor

    MovieInfo(const MovieInfo &a_other);

    // Assignment Operator

    MovieInfo &operator=(const MovieInfo &a_other);

    // Functions

    const char *GetName() const;
    const char *GetDirectorName() const;
    const Genre GetMovieGenre() const; 
    const size_t GetReleaseYear() const;
    const char *GetPurchasedDate() const;

private:
    //  Constants

    static const size_t MIN_YEAR = 1900;
    static const size_t MAX_YEAR = 2021;

    //  Struct members
    
    char *m_name;
    char *m_directorName;
    Genre m_genre;
    size_t m_releaseYear;
    char *m_purchasedDate;
};

#endif /* __MOVIE_INFO_H__ */
