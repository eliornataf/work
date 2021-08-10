#include <list> /* std::list */
#include "tLibary.hpp" /* T Libary Header */

template <typename T>
TLibary<T>::TLibary() 
: m_myLibary() {
}

template <typename T>
TLibary<T>::~TLibary() {
}

template <typename T>
TLibary<T>::TLibary(const TLibary<T> &a_other) 
: m_myLibary(a_other.m_myLibary) {
}

template <typename T>
TLibary<T> &TLibary<T>::operator=(const TLibary<T> &a_other) {
    this->m_myLibary = a_other.m_myLibary;

    return *this;
}

template <typename T>
void TLibary<T>::Add(T a_itemToAdd) {
    this->m_myLibary.push_back(a_itemToAdd);
}

template <typename T>
typename std::list<T>::const_iterator TLibary<T>::Begin() const {
    return this->m_myLibary.begin();
}

template <typename T>
typename std::list<T>::const_iterator TLibary<T>::End() const {
    return this->m_myLibary.end();
}