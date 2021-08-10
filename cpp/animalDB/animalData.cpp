#include "animalData.hpp" /* Animal Data Header */

AnimalData::AnimalData(const double &a_maxSpeed, const double &a_averageWeight, const double a_lifeExpectancy)
: m_maxSpeed(a_maxSpeed)
, m_averageWeight(m_averageWeight)
, m_lifeExpectancy(a_lifeExpectancy){
}

double AnimalData::GetMaxSpeed() const {
    return this->m_maxSpeed;
}

double AnimalData::GetAverageWeight() const {
    return this->m_averageWeight;
}

double AnimalData::GetLifeExpectancy() const {
    return this->m_lifeExpectancy;
}
