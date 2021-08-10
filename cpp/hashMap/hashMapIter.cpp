#include "entry.hpp" /* Entry Header */
#include "hashMapIter.hpp" /* Hash Map Iter Header */
#include "containerUtilites.hpp" /* Container Utilites Header */
#include "typesUtilites.hpp" /* Types Utilties */
#include <list> /* std::list */
#include <string> /* std::string */
#include <deque> /* std::deque */

HashMapIter::HashMapIter(const innerContainer::const_iterator &a_currInnerContainer, const innerContainer::const_iterator &a_endInnerContainer, const outerContainer::const_iterator &a_currOuterContainer, const outerContainer::const_iterator &a_endOuterContainer)
: m_currInnerContainer(a_currInnerContainer)
, m_endInnerContainer(a_endInnerContainer)
, m_currOuterContainer(a_currOuterContainer)
, m_endOuterContainer(a_endOuterContainer) {
}

HashMapIter &HashMapIter::operator++() {
    while (this->m_currOuterContainer != this->m_endOuterContainer) {
        if (this->m_currInnerContainer != this->m_endInnerContainer) {
            ++this->m_currInnerContainer;
            if (this->m_currInnerContainer == this->m_endInnerContainer) {
                ++this->m_currOuterContainer;
                if (this->m_currOuterContainer != this->m_endOuterContainer) {
                    this->m_currInnerContainer = this->m_currOuterContainer->begin();
                    this->m_endInnerContainer = this->m_currOuterContainer->end();
                }
            }
            else {
                break;
            }
        }
        else {
            ++this->m_currOuterContainer;
            if (this->m_currOuterContainer != this->m_endOuterContainer) {
                this->m_currInnerContainer = this->m_currOuterContainer->begin();
                this->m_endInnerContainer = this->m_currOuterContainer->end();

                if (this->m_currInnerContainer != this->m_endInnerContainer) {
                    break;
                }
            }
        }       
    }

    return *this;
}

valueType HashMapIter::operator*() const {
    return this->m_currInnerContainer->GetValue();
}

bool HashMapIter::operator==(const HashMapIter &a_other) const {
    return (this->m_currInnerContainer == a_other.m_currInnerContainer);
}

bool HashMapIter::operator!=(const HashMapIter &a_other) const {
    return (this->m_currInnerContainer != a_other.m_currInnerContainer);
}
