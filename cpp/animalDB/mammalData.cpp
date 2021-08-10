#include "mammalData.hpp" /* Mammal Data Header */

MammalData::MammalData(const size_t &a_numberOfTeeth, const std::string &a_favoriteSeason)
: m_numberOfTeeth(a_numberOfTeeth)
, m_favoriteSeason(a_favoriteSeason){
}

size_t MammalData::GetNumberOfTeeth() const {
    return this->m_numberOfTeeth;
}

std::string MammalData::GetFavoriteSeason() const {
    return this->m_favoriteSeason;
}