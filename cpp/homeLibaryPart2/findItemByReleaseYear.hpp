/*****************************************************************************
* File Name: Find Item By Release Year
* Written by: Elior Nataf
* Date: 18/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __FIND_ITEM_BY_RELEASE_YEAR__
#define __FIND_ITEM_BY_RELEASE_YEAR__

/*------------------------------- Header Files ------------------------------*/

#include "searchCriteria.hpp" /* Collection Item Header */

/*-------------------------------- Structure -------------------------------*/

class FindItemByReleaseYear : public SearchCriteria {
public:   
    // Constructor

    FindItemByReleaseYear(const size_t &a_minYearToSearch, const std::string &a_collectionItemType);

    // Destructor

    ~FindItemByReleaseYear();

    // Copy Constructor

    FindItemByReleaseYear(const FindItemByReleaseYear &a_other);

    // Assignment Operator

    FindItemByReleaseYear &operator=(const FindItemByReleaseYear &a_other);

    // Functions

    virtual bool IsPassesCriteria(const CollectionItem &a_item, const std::string &a_collectionItemType) const ;
    
private:
    //  Struct members
    
    size_t m_minYearToSearch;
    std::string m_collectionItemType;
};

#endif /* __FIND_ITEM_BY_RELEASE_YEAR__ */
