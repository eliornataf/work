/*****************************************************************************
* File Name: Book Info 
* Written by: Elior Nataf
* Date: 13/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __BOOK_INFO_H__
#define __BOOK_INFO_H__

/*------------------------------- Header Files ------------------------------*/

#include <cstddef> /* size_t */
#include <string> /* std::string */
#include "artWork.hpp" /* Art Work Header */

/*-------------------------------- Structure -------------------------------*/

class BookInfo : public ArtWork {
public:
    // Constructor

    BookInfo(const std::string &a_bookName, const std::string &a_authorName, const size_t &a_releaseYear, const size_t &a_addedTimeToCollection);

    // Destructor

    ~BookInfo();

    // Copy Constructor

    BookInfo(const BookInfo &a_other);

    // Assignment Operator

    BookInfo &operator=(const BookInfo &a_other);
    
private:
    //  Constants

    static const size_t MIN_YEAR = 1900;
    static const size_t MAX_YEAR = 2021;
};

#endif /* __BOOK_INFO_H__ */
