/*****************************************************************************
* File Name: Find Item by Added Time To Collection
* Written by: Elior Nataf
* Date: 18/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __FIND_ITEM_BY_ADDED_TIME_TO_COLLECTION__
#define __FIND_ITEM_BY_ADDED_TIME_TO_COLLECTION__

/*------------------------------- Header Files ------------------------------*/

#include <string> /* string */
#include "searchCriteria.hpp" /* Collection Item Header */

/*-------------------------------- Structure -------------------------------*/

class FindItemByAddedTimeToCollection : public SearchCriteria {
public:   
    // Constructor

    FindItemByAddedTimeToCollection(const size_t &a_minYearToSearch, const std::string &a_collectionItemType);

    // Destructor

    ~FindItemByAddedTimeToCollection();

    // Copy Constructor

    FindItemByAddedTimeToCollection(const FindItemByAddedTimeToCollection &a_other);

    // Assignment Operator

    FindItemByAddedTimeToCollection &operator=(const FindItemByAddedTimeToCollection &a_other);

    // Functions

    virtual bool IsPassesCriteria(const CollectionItem &a_item, const std::string &a_collectionItemType) const;
    
private:
    //  Struct members
    
    size_t m_minYearToSearch;
    std::string m_collectionItemType;
};

#endif /* __FIND_ITEM_BY_ADDED_TIME_TO_COLLECTION__ */
