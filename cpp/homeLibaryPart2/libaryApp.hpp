/*****************************************************************************
* File Name: Libary Application
* Written by: Elior Nataf
* Date: 13/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __T_LIBARY_APP_H__
#define __T_LIBARY_APP_H__

/*------------------------------- Header Files ------------------------------*/

#include <string> /* std::string */
#include "collectionItem.hpp" /* Collection Item Header */
#include "searchCriteria.hpp" /* Search Criteria Header */
#include "tLibary_inline.hpp" /* T Libary Header */
#include "ui.hpp" /* UI Header */

/*-------------------------------- Structure -------------------------------*/

class LibaryApp {
public:   
    // Enum

    enum UserChosenOption {
        ADD_NEW_BOOK = 1,
        ADD_NEW_MOVIE,
        FIND_BOOKS_THAT_RELEASE,
        FIND_MOVIES_THAT_RELEASE,
        FIND_BOOKS_THAT_PURCHASED,
        FIND_MOVIES_THAT_PURCHASED,
        FIND_BOOKS_THAT_CONTAINS,
        FIND_MOVIES_THAT_CONTAINS,
        EXIT
    };

    // Constructor

    LibaryApp();

    // Destructor

    ~LibaryApp();

    // Copy Constructor

    LibaryApp(const LibaryApp &a_other);

    // Assignment Operator

    LibaryApp &operator=(const LibaryApp &a_other);

    // Functions

    void RunApp();

private:
    //  Constants

    static const size_t TIME_T_START_YEAR = 1900;
    static const size_t STR_POSITION_YEAR_START = 6;
    static const size_t NUM_OF_DIGITS_IN_YEAR = 4;
    static const size_t STRING_MAX_LENGTH = 256;
    static const size_t PURCHASED_YEAR_LENGTH = 10;
    static const size_t MAX_YEAR_OF_ITEM = 2021;

    // Private Functions

    void AddNewItem(const UI *a_ui, const std::string &a_collectionItemType);
    void LibaryForEach(const UI *a_ui, const SearchCriteria &a_criteria);

    size_t ChooseNumOfYearsToSearchAndGetMinYearToSearch(const UI *a_ui) const;
    std::string ChooseStringToSearch(const UI *a_ui) const ;
    
    //  Struct members

    TLibary<CollectionItem*> m_libary;    
};

#endif /* __T_LIBARY_H__ */
