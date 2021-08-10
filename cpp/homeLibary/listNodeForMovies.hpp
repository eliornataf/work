/*****************************************************************************
* File Name: Singly Linked List For Movies
* Written by: Elior Nataf
* Date: 5/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __LIST_NODE_FOR_MOVIES_H__
#define __LIST_NODE_FOR_MOVIES_H__

/*------------------------------- Header Files ------------------------------*/

#include "movieInfo.hpp" /* Movie Info Header */

/*-------------------------------- Structure -------------------------------*/

class ListNodeForMovies {
public:
    // Constructor

    ListNodeForMovies(const MovieInfo a_movie, ListNodeForMovies *m_next);

    // Destructor

    ~ListNodeForMovies();

    // Copy Constructor

    ListNodeForMovies(const ListNodeForMovies &a_other);

    // Assignment Operator

    ListNodeForMovies &operator=(const ListNodeForMovies &a_other);

    // Functions

    const MovieInfo GetMovie() const;
    ListNodeForMovies *GetNext() const;
    void SetNext(ListNodeForMovies *a_next);

private:
    //  Struct members
    
    MovieInfo m_movie;
    ListNodeForMovies *m_next;
};

#endif /* __LIST_NODE_FOR_MOVIES_H__ */
