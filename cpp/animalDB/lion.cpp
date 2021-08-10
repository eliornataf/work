#include "lion.hpp" /* Lion Header */    

Lion::Lion(const std::string &a_name, const std::string &a_species, const double &a_maxSpeed, const double &a_averageWeight, const double a_lifeExpectancy, const size_t &a_numberOfTeeth, const std::string &a_favoriteSeason)
: Animal(a_name, a_species)
, m_lionAnimalData(a_maxSpeed, a_averageWeight, a_lifeExpectancy)
, m_lionMammalData(a_numberOfTeeth, a_favoriteSeason) {
}

const AnimalData &Lion::GetAnimalData() const {
    return this->m_lionAnimalData;
}

const MammalData &Lion::GetMammalData() const {
    return this->m_lionMammalData;
}
