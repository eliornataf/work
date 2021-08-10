/*****************************************************************************
* File Name: Fish Data
* Written by: Elior Nataf
* Date: 6/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __FISH_DATA_HPP__
#define __FISH_DATA_HPP__

/*------------------------------- Header Files ------------------------------*/

/*-------------------------------- Structure -------------------------------*/

class FishData {
public:
    // Constructor

    FishData(const double &a_lowestDepth);

    // Destructor

    ~FishData() = default;

    // Copy Constructor

    FishData(const FishData &a_other) = default;

    // Assignment Operator

    FishData &operator=(const FishData &a_other) = default;
    
    // Functions

    double GetLowestDepth() const;

private:
    // Class Members

    double m_lowestDepth;
};

#endif /* __ANIMAL_DATA_HPP__ */
