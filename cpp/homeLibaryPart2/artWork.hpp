/*****************************************************************************
* File Name: Art Work
* Written by: Elior Nataf
* Date: 13/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __ART_WORK_H__
#define __ART_WORK_H__

/*------------------------------- Header Files ------------------------------*/

#include <cstddef> /* size_t */
#include <string> /* std::string */
#include "collectionItem.hpp" /* Collection Item Header */

/*-------------------------------- Structure -------------------------------*/

class ArtWork : public CollectionItem {
public:   
    // Constructor

    ArtWork(const std::string &a_artWorkName, const std::string &a_artistName, const size_t &a_releaseYear, const std::string &a_artWorkType, const size_t &a_addedTimeToCollection);

    // Destructor

    ~ArtWork();

    // Copy Constructor

    ArtWork(const ArtWork &a_other);

    // Assignment Operator

    ArtWork &operator=(const ArtWork &a_other);

    // Functions

    const std::string &GetArtWorkName() const;
    const std::string &GetArtistName() const;
    const size_t &GetReleaseYear() const;
    
private:
    //  Struct members
    
    std::string m_artWorkName;
    std::string m_artistName;
    size_t m_releaseYear;
};

#endif /* __ART_WORK_H__ */
