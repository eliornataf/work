/*****************************************************************************
* File Name: Singly Linked List For Books
* Written by: Elior Nataf
* Date: 5/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __LIST_NODE_FOR_BOOKS_H__
#define __LIST_NODE_FOR_BOOKS_H__

/*------------------------------- Header Files ------------------------------*/

#include "bookInfo.hpp" /* Book Info Header */

/*-------------------------------- Structure -------------------------------*/

class ListNodeForBooks {
public:
    // Constructor

    ListNodeForBooks(const BookInfo a_book, ListNodeForBooks *m_next);

    // Destructor

    ~ListNodeForBooks();

    // Copy Constructor

    ListNodeForBooks(const ListNodeForBooks &a_other);

    // Assignment Operator

    ListNodeForBooks &operator=(const ListNodeForBooks &a_other);

    // Functions

    const BookInfo GetBook() const;
    ListNodeForBooks *GetNext() const;
    void SetNext(ListNodeForBooks *a_next);

private:
    //  Struct members
    
    BookInfo m_book;
    ListNodeForBooks *m_next;
};

#endif /* __LIST_NODE_FOR_BOOKS_H__ */
