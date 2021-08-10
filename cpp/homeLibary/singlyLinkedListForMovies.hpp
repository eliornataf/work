/*****************************************************************************
* File Name: Singly Linked List For Movies
* Written by: Elior Nataf
* Date: 5/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __SINGLY_LINKED_LIST_FOR_MOVIES_H__
#define __SINGLY_LINKED_LIST_FOR_MOVIES_H__

/*------------------------------- Header Files ------------------------------*/

#include <cstddef> /* size_t */
#include "listNodeForMovies.hpp" /* List Node For Movies Header */
#include "movieInfo.hpp" /* Movie Info Header */

/*-------------------------------- Structure -------------------------------*/

class SinglyLinkedListForMovies {
public:   
    // Constructor

    SinglyLinkedListForMovies();

    // Destructor

    ~SinglyLinkedListForMovies();

    // Copy Constructor

    SinglyLinkedListForMovies(const SinglyLinkedListForMovies &a_other);

    // Assignment Operator

    SinglyLinkedListForMovies &operator=(const SinglyLinkedListForMovies &a_other);

    // Functions

    void PushHead(const MovieInfo &a_movie);
    void PushTail(const MovieInfo &a_movie);

    const MovieInfo PopHead();
    const MovieInfo PopTail() const;

    const MovieInfo GetHead() const;
    const MovieInfo GetTail() const;
    const MovieInfo GetMovie(size_t a_index) const;

    const size_t Size() const;
    
private:
    //  Struct members
    
    ListNodeForMovies *m_head;
};

#endif /* __SINGLY_LINKED_LIST_FOR_MOVIES_H__ */
