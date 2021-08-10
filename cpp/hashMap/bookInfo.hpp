/*****************************************************************************
* File Name: Book Info 
* Written by: Elior Nataf
* Date: 6/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __BOOK_INFO_H__
#define __BOOK_INFO_H__

/*------------------------------- Header Files ------------------------------*/

#include <cstddef> /* size_t */

/*-------------------------------- Structure -------------------------------*/

class BookInfo {
public:
    // Constructor

    BookInfo(const char *a_name, const char *a_authorName, const size_t a_releaseYear, const char *a_purchasedDate);

    // Destructor

    ~BookInfo();

    // Copy Constructor

    BookInfo(const BookInfo &a_other);

    // Assignment Operator

    BookInfo &operator=(const BookInfo &a_other);

    // Functions

    char *GetName() const;
    char *GetAutourName() const;
    size_t GetReleaseYear() const;
    char *GetPurchasedDate() const;

private:
    //  Constants

    static const size_t MIN_YEAR = 1900;
    static const size_t MAX_YEAR = 2021;

    //  Struct members

    char *m_name;
    char *m_authorName;
    size_t m_releaseYear;
    char *m_purchasedDate;
};

#endif /* __BOOK_INFO_H__ */
