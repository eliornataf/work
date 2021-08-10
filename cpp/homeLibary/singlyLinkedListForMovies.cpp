#include <stdexcept> /* throw */
#include "listNodeForMovies.hpp" /* List Node For Movies Header */
#include "singlyLinkedListForMovies.hpp" /* Singly Linked List For Movies Header */
#include "movieInfo.hpp" /* Movie Info Header */

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

SinglyLinkedListForMovies::SinglyLinkedListForMovies()
: m_head(NULL) {
}

SinglyLinkedListForMovies::~SinglyLinkedListForMovies() {
    ListNodeForMovies *currentNode = this->m_head;

    while (NULL != currentNode) {
        ListNodeForMovies *nextNode = currentNode->GetNext();
        delete currentNode;
        currentNode = nextNode;
    }
}

SinglyLinkedListForMovies::SinglyLinkedListForMovies(const SinglyLinkedListForMovies &a_other)
: m_head(NULL) {
    ListNodeForMovies *currentNode = a_other.m_head;

    while (NULL != currentNode) {
        this->PushTail(currentNode->GetMovie());
        currentNode = currentNode->GetNext();
    }
}

SinglyLinkedListForMovies &SinglyLinkedListForMovies::operator=(const SinglyLinkedListForMovies &a_other) {
    ListNodeForMovies *currentNode = this->m_head;

    while (NULL != currentNode) {
        ListNodeForMovies *nextNode = currentNode->GetNext();
        delete currentNode;
        currentNode = nextNode;
    }

    currentNode = a_other.m_head;

    while (NULL != currentNode) {
        this->PushTail(currentNode->GetMovie());
        currentNode = currentNode->GetNext();
    }

    return *this;
}

void SinglyLinkedListForMovies::PushHead(const MovieInfo &a_movie) {
    ListNodeForMovies *newNode = new ListNodeForMovies(a_movie, this->m_head);
    this->m_head = newNode;
}

void SinglyLinkedListForMovies::PushTail(const MovieInfo &a_movie) {
    if (!this->m_head) {
        this->PushHead(a_movie);
        return;
    }
    
    ListNodeForMovies *currentNode = this->m_head;

    while (NULL != currentNode) {
        currentNode = currentNode->GetNext();
    }

    ListNodeForMovies *newNode = new ListNodeForMovies(a_movie, NULL);
    currentNode->SetNext(newNode);
}

const MovieInfo SinglyLinkedListForMovies::PopHead() {
    if(!this->m_head) {
        throw std::out_of_range("List is Empty");
    }

    MovieInfo removedMovie = this->m_head->GetMovie();
    ListNodeForMovies *nextHeadNode = this->m_head->GetNext();
    
    delete this->m_head;
    this->m_head = nextHeadNode;

    return removedMovie;
}

const MovieInfo SinglyLinkedListForMovies::PopTail() const {
    if(!this->m_head) {
        throw std::out_of_range("List is Empty");
    }
    
    ListNodeForMovies *currentNode = this->m_head;
    ListNodeForMovies *prevCurrentNode = NULL;

    while (NULL != currentNode) {
        prevCurrentNode = currentNode;
        currentNode = currentNode->GetNext();
    }

    MovieInfo removedMovie = currentNode->GetMovie();

    prevCurrentNode->SetNext(NULL);
    delete currentNode;

    return removedMovie;
}

const MovieInfo SinglyLinkedListForMovies::GetHead() const {
    if(!this->m_head) {
        throw std::out_of_range("List is Empty");
    }

    return this->m_head->GetMovie();
}

const MovieInfo SinglyLinkedListForMovies::GetTail() const {
    if(!this->m_head) {
        throw std::out_of_range("List is Empty");
    }
    
    ListNodeForMovies *currentNode = this->m_head;

    while (NULL != currentNode) {
        currentNode = currentNode->GetNext();
    }
    
    return currentNode->GetMovie();
}

const MovieInfo SinglyLinkedListForMovies::GetMovie(size_t a_index) const {
    if (this->Size() <= a_index) {
        throw std::out_of_range("index is not exist");
    }

    ListNodeForMovies *currentNode = this->m_head;

    for (size_t i = 0; i < a_index;++i)
    {
        currentNode = currentNode->GetNext();
    }

    return currentNode->GetMovie();
}

const size_t SinglyLinkedListForMovies::Size() const {
    ListNodeForMovies *currentNode = this->m_head;
    size_t countNodes = 0;

    while (NULL != currentNode) {
        currentNode = currentNode->GetNext();
        ++countNodes;
    }

    return countNodes;
}
