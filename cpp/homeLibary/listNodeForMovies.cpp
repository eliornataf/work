#include "listNodeForMovies.hpp" /* List Node For Movies Header */

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

ListNodeForMovies::ListNodeForMovies(const MovieInfo a_movie, ListNodeForMovies *m_next) 
: m_movie(a_movie)
, m_next(m_next) {
}

ListNodeForMovies::~ListNodeForMovies() {
}

ListNodeForMovies::ListNodeForMovies(const ListNodeForMovies &a_other) 
: m_movie(a_other.m_movie)
, m_next(a_other.m_next) {
}

ListNodeForMovies &ListNodeForMovies::operator=(const ListNodeForMovies &a_other) {
    this->m_movie = a_other.m_movie;
    this->m_next = a_other.m_next;

    return *this;
}

const MovieInfo ListNodeForMovies::GetMovie() const {
    return this->m_movie;
}

ListNodeForMovies *ListNodeForMovies::GetNext() const {
    return this->m_next;
}

void ListNodeForMovies::SetNext(ListNodeForMovies *a_next) {
    this->m_next = a_next;
}