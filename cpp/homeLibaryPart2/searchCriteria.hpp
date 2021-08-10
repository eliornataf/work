/*****************************************************************************
* File Name: Search Criteria 
* Written by: Elior Nataf
* Date: 18/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __SEARCH_CRITERIA__
#define __SEARCH_CRITERIA__

/*------------------------------- Header Files ------------------------------*/

#include "collectionItem.hpp" /* Collection Item Header */

/*-------------------------------- Structure -------------------------------*/

class SearchCriteria {
public:
    // Functions

    virtual bool IsPassesCriteria(const CollectionItem &a_item, const std::string &a_collectionItemType) const;    
};

#endif /* __SEARCH_CRITERIA__ */
