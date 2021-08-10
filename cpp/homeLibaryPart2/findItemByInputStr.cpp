#include <string> /* string */
#include "artWork.hpp" /* Art Work Header */
#include "collectionItem.hpp" /* Collection Item Header */
#include "findItemByInputStr.hpp" /* Find Item By Input Str Header */

FindItemByInputStr::FindItemByInputStr(const std::string &a_inputStr, const std::string &a_collectionItemType)
: m_inputStr(a_inputStr)
, m_collectionItemType(a_collectionItemType) {
}

FindItemByInputStr::~FindItemByInputStr() {
}

FindItemByInputStr::FindItemByInputStr(const FindItemByInputStr &a_other)
: m_inputStr(a_other.m_inputStr)
, m_collectionItemType(a_other.m_collectionItemType) {
}

FindItemByInputStr &FindItemByInputStr::operator=(const FindItemByInputStr &a_other) {
    this->m_inputStr = a_other.m_inputStr;
    this->m_collectionItemType = a_other.m_collectionItemType;

    return *this;
}

bool FindItemByInputStr::IsPassesCriteria(const CollectionItem &a_item, const std::string &a_collectionItemType) const {
    return ( (static_cast<const ArtWork&>(a_item).GetArtWorkName().find(this->m_inputStr) != std::string::npos) && (m_collectionItemType == a_collectionItemType) );
}