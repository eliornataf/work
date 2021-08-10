#include "animal.hpp" /* Animal Header */

Animal::Animal(const std::string &a_name, const std::string &a_species) 
: m_name(a_name)
, m_species(a_species){
}

std::string Animal::GetName() const {
    return this->m_name;
}

std::string Animal::GetSpecies() const {
    return this->m_species;
}

double Animal::GetMaxSpeed() const {
    return GetAnimalData().GetMaxSpeed();
}

double Animal::GetAverageWeight() const {
    return GetAnimalData().GetAverageWeight();
}

double Animal::GetLifeExpectancy() const {
    return GetAnimalData().GetLifeExpectancy();
}
