#include <string> /* std::string */
#include "collectionItem.hpp" /* Collection Item Header */

CollectionItem::CollectionItem(const std::string &a_collectionItemType, const size_t &a_timeAddedToCollection)
: m_collectionItemType(a_collectionItemType)
, m_addedTimeToCollection(a_timeAddedToCollection) {
}

CollectionItem::~CollectionItem() {
}

CollectionItem::CollectionItem(const CollectionItem &a_other)
: m_collectionItemType(a_other.m_collectionItemType)
, m_addedTimeToCollection(a_other.m_addedTimeToCollection) {
}

CollectionItem &CollectionItem::operator=(const CollectionItem &a_other) {
    this->m_collectionItemType = a_other.m_collectionItemType;
    this->m_addedTimeToCollection = a_other.m_addedTimeToCollection;

    return *this;
}

const std::string &CollectionItem::GetCollectionType() const {
    return this->m_collectionItemType;
}

const size_t &CollectionItem::GetAddedTimeToCollection() const {
    return this->m_addedTimeToCollection;
}