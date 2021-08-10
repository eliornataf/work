#include <stdexcept> /* throw */
#include <list> /* std::list */
#include <string> /* std::string */
#include <vector> /* std::vector */
#include "bookInfo.hpp" /* Book Info Header */
#include "entry.hpp" /* Entry Header */
#include "hashFunc.hpp" /* Hash Function Header */
#include "hashMap.hpp" /* Hash Map Header */ 
#include "hashMapIter.hpp" /* Hash Map Iter Header */
#include "containerUtilites.hpp" /* Container Utilites Header */

HashMap::HashMap(const size_t &a_initSize, const HashFunc &a_hashFunc)
: m_container(a_initSize)
, m_hashFunc(a_hashFunc) {
    if (!a_initSize) {
        throw std::invalid_argument("a_initSize set to zero");
    }
}

HashMap::Status HashMap::Insert(const keyType &a_key, const valueType &a_value) {  
    size_t index = m_hashFunc.GetIndex(a_key) % this->m_container.size();

    innerContainer::const_iterator foundIter = FindEntry(this->m_container.at(index), a_key);
    innerContainer::iterator endIter = this->m_container.at(index).end();

    if (foundIter != endIter) {
        return FAILED;
    }

    this->m_container.at(index).push_back(Entry(a_key, a_value));
    return SUCCEEDED;
}

HashMap::Status HashMap::Remove(const keyType &a_key) {
    size_t index = m_hashFunc.GetIndex(a_key) % this->m_container.size();
    
    innerContainer::const_iterator foundIter = FindEntry(this->m_container.at(index), a_key);
    innerContainer::iterator endIter = this->m_container.at(index).end();

    if (foundIter != endIter) {
        this->m_container.at(index).erase(foundIter);
        return SUCCEEDED;
    }

    return FAILED;
} 

innerContainer::const_iterator HashMap::Find(const keyType &a_key) {
    size_t index = m_hashFunc.GetIndex(a_key) % this->m_container.size();
    
    innerContainer::const_iterator foundIter = FindEntry(this->m_container.at(index), a_key);
    innerContainer::iterator endIter = this->m_container.at(index).end();

    if (foundIter != endIter) {
        return foundIter;
    }

    return endIter;
}

innerContainer::const_iterator HashMap::FindEntry(const innerContainer &a_container, const keyType &a_key) {
    innerContainer::const_iterator currIter = a_container.begin();
    innerContainer::const_iterator endIter = a_container.end();

    for (;currIter != endIter;++currIter) {
        Entry currEntry = *currIter;
        if (a_key == currEntry.GetKey()) {
            return currIter;
        }
    }

    return endIter;
}

HashMapIter HashMap::Begin() const {
    outerContainer::const_iterator currVecIter = this->m_container.begin();
    outerContainer::const_iterator endVecIter = this->m_container.end();

    for (;currVecIter != endVecIter;++currVecIter) {
        if (!currVecIter->empty()) {
            return HashMapIter(currVecIter->begin(), currVecIter->end(), currVecIter, this->m_container.end());
        }
    }   

    return End();
}

HashMapIter HashMap::End() const {
    return HashMapIter(this->m_container.at(this->m_container.size() - 1).end(), this->m_container.at(this->m_container.size() - 1).end(), this->m_container.end(), this->m_container.end());
}
