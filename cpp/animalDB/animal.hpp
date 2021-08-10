/*****************************************************************************
* File Name: Animal
* Written by: Elior Nataf
* Date: 6/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <string> /* std::string */
#include "animalData.hpp" /* Animal Data Header */

/*-------------------------------- Structure -------------------------------*/

class Animal {
public:
    // Constructor

    Animal(const std::string &a_name, const std::string &a_species);

    // Destructor

    ~Animal() = default;

    // Copy Constructor

    Animal(const Animal &a_other) = default;

    // Assignment Operator

    Animal &operator=(const Animal &a_other) = default;

    // Functions

    std::string GetName() const;
    std::string GetSpecies() const;

    double GetMaxSpeed() const;
    double GetAverageWeight() const;
    double GetLifeExpectancy() const;

protected:
    //  Virtual Functions

    virtual const AnimalData &GetAnimalData() const = 0;
    
private:
    // Class Members

    std::string m_name;
    std::string m_species;
};

#endif /* __ANIMAL_HPP__ */
