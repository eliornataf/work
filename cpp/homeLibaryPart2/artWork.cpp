#include <string> /* std::string */
#include "artWork.hpp" /* Art Work Header */
#include "collectionItem.hpp" /* Collection Item Header */

ArtWork::ArtWork(const std::string &a_artWorkName, const std::string &a_artistName, const size_t &a_releaseYear, const std::string &a_artWorkType, const size_t &a_addedTimeToCollection)
: m_artWorkName(a_artWorkName)
, m_artistName(a_artistName)
, m_releaseYear(a_releaseYear)
, CollectionItem(a_artWorkType, a_addedTimeToCollection) {
}

ArtWork::~ArtWork() {
}

ArtWork::ArtWork(const ArtWork &a_other)
: m_artWorkName(a_other.m_artWorkName)
, m_artistName(a_other.m_artistName)
, m_releaseYear(a_other.m_releaseYear)
, CollectionItem(a_other) {
}

ArtWork &ArtWork::operator=(const ArtWork &a_other) {
    this->m_artWorkName = a_other.m_artWorkName;
    this->m_artistName = a_other.m_artistName;
    this->m_releaseYear = a_other.m_releaseYear;
    this->CollectionItem::operator=(a_other);

    return *this;
}

const std::string &ArtWork::GetArtWorkName() const {
    return this->m_artWorkName;
}

const std::string &ArtWork::GetArtistName() const {
    return this->m_artistName;
}

const size_t &ArtWork::GetReleaseYear() const {
    return this->m_releaseYear;
}
