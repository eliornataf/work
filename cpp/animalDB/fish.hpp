/*****************************************************************************
* File Name: Fish
* Written by: Elior Nataf
* Date: 6/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __FISH_HPP__
#define __FISH_HPP__

/*------------------------------- Header Files ------------------------------*/

#include "fishData.hpp" /* Fish Data Header */

/*-------------------------------- Structure -------------------------------*/

class Fish {
public:
    // Constructor

    Fish() = default; 

    // Destructor

    ~Fish() = default;

    // Copy Constructor

    Fish(const Fish &a_other) = default;

    // Assignment Operator

    Fish &operator=(const Fish &a_other) = default;

    // Functions

    double GetLowestDepth() const;

protected:
    //  Virtual Functions

    virtual const FishData &GetFishData() const = 0;
};

#endif /* __FISH_HPP__ */
