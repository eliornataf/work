#include "fishData.hpp" /* Fish Data Header */

FishData::FishData(const double &a_lowestDepth) 
: m_lowestDepth(a_lowestDepth) {
}

double FishData::GetLowestDepth() const {
    return this->m_lowestDepth;
}
