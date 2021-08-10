/*****************************************************************************
* File Name: Find Item By Input String
* Written by: Elior Nataf
* Date: 18/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __FIND_ITEM_BY_INPUT_STR__
#define __FIND_ITEM_BY_INPUT_STR__

/*------------------------------- Header Files ------------------------------*/

#include <string> /* string */
#include "searchCriteria.hpp" /* Collection Item Header */

/*-------------------------------- Structure -------------------------------*/

class FindItemByInputStr : public SearchCriteria {
public:   
    // Constructor

    FindItemByInputStr(const std::string &a_inputStr, const std::string &a_collectionItemType);

    // Destructor

    ~FindItemByInputStr();

    // Copy Constructor

    FindItemByInputStr(const FindItemByInputStr &a_other);

    // Assignment Operator

    FindItemByInputStr &operator=(const FindItemByInputStr &a_other);

    // Functions

    virtual bool IsPassesCriteria(const CollectionItem &a_item, const std::string &a_collectionItemType) const;
    
private:
    //  Struct members
    
    std::string m_inputStr;
    std::string m_collectionItemType;
};

#endif /* __FIND_ITEM_BY_INPUT_STR__ */
