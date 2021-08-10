#include <string> /* string */
#include "artWork.hpp" /* Art Work Header */
#include "collectionItem.hpp" /* Collection Item Header */
#include "findItemByAddedTimeToCollection.hpp" /* Find Item By Added Time To Collection Header */

FindItemByAddedTimeToCollection::FindItemByAddedTimeToCollection(const size_t &a_minYearToSearch, const std::string &a_collectionItemType) 
: m_minYearToSearch(a_minYearToSearch)
, m_collectionItemType(std::string(a_collectionItemType)) {
}

FindItemByAddedTimeToCollection::~FindItemByAddedTimeToCollection() {
}

FindItemByAddedTimeToCollection::FindItemByAddedTimeToCollection(const FindItemByAddedTimeToCollection &a_other)
: m_minYearToSearch(a_other.m_minYearToSearch)
, m_collectionItemType(a_other.m_collectionItemType) {
}

FindItemByAddedTimeToCollection &FindItemByAddedTimeToCollection::operator=(const FindItemByAddedTimeToCollection &a_other) {
    this->m_minYearToSearch = a_other.m_minYearToSearch;
    this->m_collectionItemType = a_other.m_collectionItemType;

    return *this;
}

bool FindItemByAddedTimeToCollection::IsPassesCriteria(const CollectionItem &a_item, const std::string &a_collectionItemType) const {
    return ( (this->m_minYearToSearch <= a_item.GetAddedTimeToCollection()) && (m_collectionItemType == a_collectionItemType) );
}