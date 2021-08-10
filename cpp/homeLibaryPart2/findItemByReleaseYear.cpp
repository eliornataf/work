#include "artWork.hpp" /* Art Work Header */
#include "collectionItem.hpp" /* Collection Item Header */
#include "findItemByReleaseYear.hpp" /* Find Item By Release Year Header */

FindItemByReleaseYear::FindItemByReleaseYear(const size_t &a_minYearToSearch, const std::string &a_collectionItemType) 
: m_minYearToSearch(a_minYearToSearch)
, m_collectionItemType(a_collectionItemType) {
}

FindItemByReleaseYear::~FindItemByReleaseYear() {
}

FindItemByReleaseYear::FindItemByReleaseYear(const FindItemByReleaseYear &a_other)
: m_minYearToSearch(a_other.m_minYearToSearch)
, m_collectionItemType(a_other.m_collectionItemType) {
}

FindItemByReleaseYear &FindItemByReleaseYear::operator=(const FindItemByReleaseYear &a_other) {
    this->m_minYearToSearch = a_other.m_minYearToSearch;
    this->m_collectionItemType = a_other.m_collectionItemType;

    return *this;
}

bool FindItemByReleaseYear::IsPassesCriteria(const CollectionItem &a_item, const std::string &a_collectionItemType) const {
    return ( (this->m_minYearToSearch <= static_cast<const ArtWork&>(a_item).GetReleaseYear()) && (m_collectionItemType == a_collectionItemType) );
}