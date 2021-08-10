/*****************************************************************************
* File Name: Mammal Data
* Written by: Elior Nataf
* Date: 6/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __MAMMAL_DATA_HPP__
#define __MAMMAL_DATA_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <string> /* std::string */

/*-------------------------------- Structure -------------------------------*/

class MammalData {
public:
    // Constructor

    MammalData(const size_t &a_numberOfTeeth, const std::string &a_favoriteSeason);

    // Destructor

    ~MammalData() = default;

    // Copy Constructor

    MammalData(const MammalData &a_other) = default;

    // Assignment Operator

    MammalData &operator=(const MammalData &a_other) = default;
    
    // Functions

    size_t GetNumberOfTeeth() const;
    std::string GetFavoriteSeason() const;

private:
    // Class Members

    size_t m_numberOfTeeth;
    std::string m_favoriteSeason;
};

#endif /* __MAMMAL_DATA_HPP__ */
