/*****************************************************************************
* File Name: Collection Item
* Written by: Elior Nataf
* Date: 13/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __COLLECTION_ITEM_H__
#define __COLLECTION_ITEM_H__

/*------------------------------- Header Files ------------------------------*/

#include <cstddef> /* size_t */
#include <string> /* std::string */

/*-------------------------------- Structure -------------------------------*/

class CollectionItem {
public:   
    // Constructor

    CollectionItem(const std::string &a_collectionItemType, const size_t &a_timeAddedToCollection);

    // Destructor

    ~CollectionItem();

    // Copy Constructor

    CollectionItem(const CollectionItem &a_other);

    // Assignment Operator

    CollectionItem &operator=(const CollectionItem &a_other);

    // Functions

    const std::string &GetCollectionType() const;
    const size_t &GetAddedTimeToCollection() const;
    
private:
    //  Struct members
    
    std::string m_collectionItemType;
    size_t m_addedTimeToCollection;
};

#endif /* __COLLECTION_ITEM_H__ */
