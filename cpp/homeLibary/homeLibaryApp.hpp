/*****************************************************************************
* File Name: Home Libary Application 
* Written by: Elior Nataf
* Date: 6/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __HOME_LIBARY_APPLICATION_H__
#define __HOME_LIBARY_APPLICATION_H__

/*------------------------------- Header Files ------------------------------*/

#include <cstddef> /* size_t */
#include "singlyLinkedListForBooks.hpp" /* Singly Linked List For Books Header */
#include "singlyLinkedListForMovies.hpp" /* Singly Linked List For Movies Header */
#include "ui.hpp" /* UI header */

/*-------------------------------- Structure -------------------------------*/

class HomeLibaryApp {
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

    HomeLibaryApp();

    // Destructor

    ~HomeLibaryApp();

    // Copy Constructor

    HomeLibaryApp(const HomeLibaryApp &a_other);

    // Assignment Operator

    HomeLibaryApp &operator=(const HomeLibaryApp &a_other);

    // Functions

    void RunApp();

private:
    //  Constants

    static const size_t TIME_T_START_YEAR = 1900;
    static const size_t STR_POSITION_YEAR_START = 6;
    static const size_t NUM_OF_DIGITS_IN_YEAR = 4;
    static const size_t STRING_MAX_LENGTH = 256;
    static const size_t PURCHASED_YEAR_LENGTH = 10;
    static const size_t MAX_NUM_OF_YEARS_TO_SEARCH = 121;

    // Private Functions

    void AddBook(const UI *a_ui);
    void AddMovie(const UI *a_ui);
    size_t ChooseNumOfYearsToSearch(const UI *a_ui) const;
    void ChooseStringToSearch(const UI *a_ui, char *a_str) const;

    void FindBooksThatReleasedXYearsFromNow(const UI *a_ui, const size_t a_numOfYearsToSearch) const;
    void FindMoviesThatReleasedXYearsFromNow(const UI *a_ui, const size_t a_numOfYearsToSearch) const;

    void FindBooksThatPurchasedXYearsFromNow(const UI *a_ui, const size_t a_numOfYearsToSearch) const;
    void FindMoviesThatPurchasedXYearsFromNow(const UI *a_ui, const size_t a_numOfYearsToSearch) const;

    void FindBooksThatContainInputStr(const UI *a_ui, const char *a_str) const;
    void FindMoviesThatContainInputStr(const UI *a_ui, const char *a_str) const;

    //  Struct members

    SinglyLinkedListForBooks m_singlyLinkedListForBooks;
    SinglyLinkedListForMovies m_singlyLinkedListForMovies;
};

#endif /* __HOME_LIBARY_APPLICATION_H__ */
