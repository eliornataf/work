#include <stdexcept> /* throw */
#include "bookInfo.hpp" /* Book Info Header */
#include "listNodeForBooks.hpp" /* List Node For Books Header */
#include "singlyLinkedListForBooks.hpp" /* Singly Linked List For Books Header */

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

SinglyLinkedListForBooks::SinglyLinkedListForBooks()
: m_head(NULL) {
}

SinglyLinkedListForBooks::~SinglyLinkedListForBooks() {
    ListNodeForBooks *currentNode = this->m_head;

    while (NULL != currentNode) {
        ListNodeForBooks *nextNode = currentNode->GetNext();
        delete currentNode;
        currentNode = nextNode;
    }
}

SinglyLinkedListForBooks::SinglyLinkedListForBooks(const SinglyLinkedListForBooks &a_other)
: m_head(NULL) {
    ListNodeForBooks *currentNode = a_other.m_head;

    while (NULL != currentNode) {
        this->PushTail(currentNode->GetBook());
        currentNode = currentNode->GetNext();
    }
}

SinglyLinkedListForBooks &SinglyLinkedListForBooks::operator=(const SinglyLinkedListForBooks &a_other) {
    ListNodeForBooks *currentNode = this->m_head;

    while (NULL != currentNode) {
        ListNodeForBooks *nextNode = currentNode->GetNext();
        delete currentNode;
        currentNode = nextNode;
    }

    currentNode = a_other.m_head;

    while (NULL != currentNode) {
        this->PushTail(currentNode->GetBook());
        currentNode = currentNode->GetNext();
    }

    return *this;
}

void SinglyLinkedListForBooks::PushHead(const BookInfo &a_book) {
    ListNodeForBooks *newNode = new ListNodeForBooks(a_book, this->m_head);
    this->m_head = newNode;
}

void SinglyLinkedListForBooks::PushTail(const BookInfo &a_book) {
    if (!this->m_head) {
        this->PushHead(a_book);
        return;
    }
    
    ListNodeForBooks *currentNode = this->m_head;

    while (NULL != currentNode) {
        currentNode = currentNode->GetNext();
    }

    ListNodeForBooks *newNode = new ListNodeForBooks(a_book, NULL);
    currentNode->SetNext(newNode);
}

const BookInfo SinglyLinkedListForBooks::PopHead() {
    if(!this->m_head) {
        throw std::out_of_range("List is Empty");
    }

    BookInfo removedbook = this->m_head->GetBook();
    ListNodeForBooks *nextHeadNode = this->m_head->GetNext();
    
    delete this->m_head;
    this->m_head = nextHeadNode;

    return removedbook;
}

const BookInfo SinglyLinkedListForBooks::PopTail() const {
    if(!this->m_head) {
        throw std::out_of_range("List is Empty");
    }
    
    ListNodeForBooks *currentNode = this->m_head;
    ListNodeForBooks *prevCurrentNode = NULL;

    while (NULL != currentNode) {
        prevCurrentNode = currentNode;
        currentNode = currentNode->GetNext();
    }

    BookInfo removedbook = currentNode->GetBook();

    prevCurrentNode->SetNext(NULL);
    delete currentNode;

    return removedbook;
}

const BookInfo SinglyLinkedListForBooks::GetHead() const {
    if(!this->m_head) {
        throw std::out_of_range("List is Empty");
    }
    
    return this->m_head->GetBook();
}

const BookInfo SinglyLinkedListForBooks::GetTail() const {
    if(!this->m_head) {
        throw std::out_of_range("List is Empty");
    }
    
    ListNodeForBooks *currentNode = this->m_head;

    while (NULL != currentNode) {
        currentNode = currentNode->GetNext();
    }
    
    return currentNode->GetBook();
}

const BookInfo SinglyLinkedListForBooks::GetBook(size_t a_index) const {
    if (this->Size() <= a_index) {
        throw std::out_of_range("index is not exist");
    }

    ListNodeForBooks *currentNode = this->m_head;

    for (size_t i = 0; i < a_index;++i)
    {
        currentNode = currentNode->GetNext();
    }

    return currentNode->GetBook();
}

const size_t SinglyLinkedListForBooks::Size() const {
    ListNodeForBooks *currentNode = this->m_head;
    size_t countNodes = 0;

    while (NULL != currentNode) {
        currentNode = currentNode->GetNext();
        ++countNodes;
    }

    return countNodes;
}