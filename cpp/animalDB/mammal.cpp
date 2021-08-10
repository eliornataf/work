#include "mammal.hpp" /* Mammal Header */

size_t Mammal::GetNumberOfTeeth() const {
    return GetMammalData().GetNumberOfTeeth();
}

std::string Mammal::GetFavoriteSeason() const {
    return GetMammalData().GetFavoriteSeason();
}