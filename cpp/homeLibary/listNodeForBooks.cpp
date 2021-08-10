#include "listNodeForBooks.hpp" /* List Node For Books Header */

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

ListNodeForBooks::ListNodeForBooks(const BookInfo a_book, ListNodeForBooks *m_next) 
: m_book(a_book)
, m_next(m_next) {
}

ListNodeForBooks::~ListNodeForBooks() {
}

ListNodeForBooks::ListNodeForBooks(const ListNodeForBooks &a_other) 
: m_book(a_other.m_book)
, m_next(a_other.m_next) {
}

ListNodeForBooks &ListNodeForBooks::operator=(const ListNodeForBooks &a_other) {
    this->m_book = a_other.m_book;
    this->m_next = a_other.m_next;

    return *this;
}

const BookInfo ListNodeForBooks::GetBook() const {
    return this->m_book;
}

ListNodeForBooks *ListNodeForBooks::GetNext() const {
    return this->m_next;
}

void ListNodeForBooks::SetNext(ListNodeForBooks *a_next) {
    this->m_next = a_next;
}