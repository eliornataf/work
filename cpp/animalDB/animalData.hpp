/*****************************************************************************
* File Name: Animal Data
* Written by: Elior Nataf
* Date: 6/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __ANIMAL_DATA_HPP__
#define __ANIMAL_DATA_HPP__

/*------------------------------- Header Files ------------------------------*/

/*-------------------------------- Structure -------------------------------*/

class AnimalData {
public:
    // Constructor

    AnimalData(const double &a_maxSpeed, const double &a_averageWeight, const double a_lifeExpectancy);

    // Destructor

    ~AnimalData() = default;

    // Copy Constructor

    AnimalData(const AnimalData &a_other) = default;

    // Assignment Operator

    AnimalData &operator=(const AnimalData &a_other) = default;
    
    // Functions

    double GetMaxSpeed() const;
    double GetAverageWeight() const;
    double GetLifeExpectancy() const;

private:
    // Class Members

    double m_maxSpeed;
    double m_averageWeight;
    double m_lifeExpectancy;
};

#endif /* __ANIMAL_DATA_HPP__ */
