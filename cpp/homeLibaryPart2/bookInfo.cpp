#include "artWork.hpp" /* Art Work Header */
#include "bookInfo.hpp" /* Book Info Header */
#include <string> /* std::string */

BookInfo::BookInfo(const std::string &a_bookName, const std::string &a_authorName, const size_t &a_releaseYear, const size_t &a_addedTimeToCollection) 
: ArtWork(a_bookName, a_authorName, a_releaseYear, std::string("Book"), a_addedTimeToCollection) {
}

BookInfo::~BookInfo() {
}

BookInfo::BookInfo(const BookInfo &a_other) 
: ArtWork(a_other) {
}

BookInfo &BookInfo::operator=(const BookInfo &a_other) {
    this->ArtWork::operator=(a_other);

    return *this;
}
