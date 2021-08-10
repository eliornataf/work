/*****************************************************************************
* File Name: Mammal
* Written by: Elior Nataf
* Date: 6/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __MAMMAL_HPP__
#define __MAMMAL_HPP__

/*------------------------------- Header Files ------------------------------*/

#include "mammalData.hpp" /* Mammal Data Header */

/*-------------------------------- Structure -------------------------------*/

class Mammal {
public:
    // Constructor

    Mammal() = default; 

    // Destructor

    ~Mammal() = default;

    // Copy Constructor

    Mammal(const Mammal &a_other) = default;

    // Assignment Operator

    Mammal &operator=(const Mammal &a_other) = default;

    // Functions

    size_t GetNumberOfTeeth() const;
    std::string GetFavoriteSeason() const;

protected:
    //  Virtual Functions

    virtual const MammalData &GetMammalData() const = 0;
};

#endif /* __MAMMAL_HPP__ */
