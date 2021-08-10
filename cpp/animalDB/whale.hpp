/*****************************************************************************
* File Name: Whale
* Written by: Elior Nataf
* Date: 6/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __WHALE_HPP__
#define __WHALE_HPP__

/*------------------------------- Header Files ------------------------------*/

#include "animal.hpp" /* Animal Header */
#include "fish.hpp" /* Fish Header */
#include "mammal.hpp" /* Mammal Header */
#include "animalData.hpp" /* Animal Data Header */
#include "fishData.hpp" /* Fish Data Header */
#include "mammalData.hpp" /* Mammal Data Header */

/*-------------------------------- Structure -------------------------------*/

class Whale : public Animal, public Fish, public Mammal {
public:
    // Constructor

    Whale(const std::string &a_name, const std::string &a_species, const double &a_maxSpeed, const double &a_averageWeight, const double a_lifeExpectancy, const double &a_lowestDepth, const size_t &a_numberOfTeeth, const std::string &a_favoriteSeason); 

    // Destructor

    ~Whale() = default;

    // Copy Constructor

    Whale(const Whale &a_other) = default;

    // Assignment Operator

    Whale &operator=(const Whale &a_other) = default;

protected:
    //  Virtual Functions

    virtual const AnimalData &GetAnimalData() const;
    virtual const FishData &GetFishData() const;
    virtual const MammalData &GetMammalData() const;

private:
    // Class Members

    AnimalData m_whaleAnimalData;
    FishData m_whaleFishData;
    MammalData m_whaleMammalData;
};

#endif /* __WHALE_HPP__ */
