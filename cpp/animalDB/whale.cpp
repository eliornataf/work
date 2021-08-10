#include "whale.hpp" /* Whale Header */

Whale::Whale(const std::string &a_name, const std::string &a_species, const double &a_maxSpeed, const double &a_averageWeight, const double a_lifeExpectancy, const double &a_lowestDepth, const size_t &a_numberOfTeeth, const std::string &a_favoriteSeason)
: Animal(a_name, a_species) 
, m_whaleAnimalData(a_maxSpeed, a_averageWeight, a_lifeExpectancy)
, m_whaleFishData(a_lowestDepth)
, m_whaleMammalData(a_numberOfTeeth, a_favoriteSeason) {
}

const AnimalData &Whale::GetAnimalData() const {
    return this->m_whaleAnimalData;
}

const FishData &Whale::GetFishData() const {
    return this->m_whaleFishData;
}

const MammalData &Whale::GetMammalData() const {
    return this->m_whaleMammalData;
}