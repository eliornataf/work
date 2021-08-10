/*****************************************************************************
* File Name: Lion
* Written by: Elior Nataf
* Date: 6/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __LION_HPP__
#define __LION_HPP__

/*------------------------------- Header Files ------------------------------*/

#include "animal.hpp" /* Animal Header */
#include "mammal.hpp" /* Mammal Header */
#include "animalData.hpp" /* Animal Data Header */
#include "mammalData.hpp" /* Mammal Data Header */

/*-------------------------------- Structure -------------------------------*/

class Lion : public Animal, public Mammal {
public:
    // Constructor

    Lion(const std::string &a_name, const std::string &a_species, const double &a_maxSpeed, const double &a_averageWeight, const double a_lifeExpectancy, const size_t &a_numberOfTeeth, const std::string &a_favoriteSeason); 

    // Destructor

    ~Lion() = default;

    // Copy Constructor

    Lion(const Lion &a_other) = default;

    // Assignment Operator

    Lion &operator=(const Lion &a_other) = default;

protected:
    //  Virtual Functions

    virtual const AnimalData &GetAnimalData() const;
    virtual const MammalData &GetMammalData() const;

private:
    // Class Members

    AnimalData m_lionAnimalData;
    MammalData m_lionMammalData;
};

#endif /* __LION_HPP__ */
