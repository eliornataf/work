/*****************************************************************************
* File Name: Singly Linked List For Books
* Written by: Elior Nataf
* Date: 5/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __SINGLY_LINKED_LIST_FOR_BOOKS_H__
#define __SINGLY_LINKED_LIST_FOR_BOOKS_H__

/*------------------------------- Header Files ------------------------------*/

#include <cstddef> /* size_t */
#include "listNodeForBooks.hpp" /* List Node For Books Header */
#include "bookInfo.hpp" /* Book Info Header */

/*-------------------------------- Structure -------------------------------*/

class SinglyLinkedListForBooks {
public:   
    // Constructor

    SinglyLinkedListForBooks();

    // Destructor

    ~SinglyLinkedListForBooks();

    // Copy Constructor

    SinglyLinkedListForBooks(const SinglyLinkedListForBooks &a_other);

    // Assignment Operator

    SinglyLinkedListForBooks &operator=(const SinglyLinkedListForBooks &a_other);

    // Functions

    void PushHead(const BookInfo &a_book);
    void PushTail(const BookInfo &a_book);

    const BookInfo PopHead();
    const BookInfo PopTail() const;

    const BookInfo GetHead() const;
    const BookInfo GetTail() const;
    const BookInfo GetBook(size_t a_index) const;

    const size_t Size() const;
    
private:
    //  Struct members
    
    ListNodeForBooks *m_head;
};

#endif /* __SINGLY_LINKED_LIST_FOR_BOOKS_H__ */
