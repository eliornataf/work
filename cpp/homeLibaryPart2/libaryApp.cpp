#include <cstring> /* strlen, strstr */
#include <list> /* std::list */
#include <stdexcept> /* expection */
#include <stdlib.h> /* atoi */
#include <string> /* std::string */
#include <time.h> /* time_t */
#include "bookInfo.hpp" /* Book Info Header */
#include "collectionItem.hpp" /* Collection Item Header */
#include "findItemByAddedTimeToCollection.hpp" /* Find Item By Added Time To Collection */
#include "findItemByInputStr.hpp" /* Find Item By Input Str */
#include "findItemByReleaseYear.hpp" /* Find Item By Added Time To Collection */
#include "libaryApp.hpp" /* Libary Application Header */
#include "movieInfo.hpp" /* Book Info Header */
#include "tLibary.hpp" /* T Libary header */
#include "ui.hpp" /* UI header */


/******************************************************/

#define USER_INPUT_ACTION (0)
#define USER_INPUT_COMEDY (1)
#define USER_INPUT_DRAMA (2)
#define USER_INPUT_ANIME (3)
#define USER_INPUT_OTHER (4)

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static size_t CountDigits(size_t a_num);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

LibaryApp::LibaryApp()
: m_libary() {
}

LibaryApp::~LibaryApp() {
    std::list<CollectionItem*>::const_iterator currIter = this->m_libary.Begin();
    std::list<CollectionItem*>::const_iterator endIter = this->m_libary.End();

    for (;currIter != endIter;currIter++) {
        delete *currIter;
    }
} 

LibaryApp::LibaryApp(const LibaryApp &a_other)
: m_libary(a_other.m_libary) {
}

LibaryApp &LibaryApp::operator=(const LibaryApp &a_other) {
    std::list<CollectionItem*>::const_iterator currThisIter = this->m_libary.Begin();
    std::list<CollectionItem*>::const_iterator endThisIter = this->m_libary.End();

    for (;currThisIter != endThisIter;currThisIter++) {
        delete *currThisIter;
    }

    std::list<CollectionItem*>::const_iterator currOtherIter = a_other.m_libary.Begin();
    std::list<CollectionItem*>::const_iterator endOtherIter = a_other.m_libary.End();

    for (;currOtherIter != endOtherIter;currOtherIter++) {
        CollectionItem *item = *currOtherIter;

        if ("Book" == (*currOtherIter)->GetCollectionType()) {
            BookInfo *currBook = static_cast<BookInfo*>(*currOtherIter);
            BookInfo *newBook = new BookInfo(*currBook);
            this->m_libary.Add(newBook);
        }
        else {
            MovieInfo *currMovie = static_cast<MovieInfo*>(*currOtherIter);
            MovieInfo *newMovie = new MovieInfo(*currMovie);
            this->m_libary.Add(newMovie);
        }
    }

    return *this;
}

void LibaryApp::RunApp() {
    UI ui;

    ui.PrintWelcomeMessage();

    while (1) {
        ui.PrintMenu();
        int userInput = ui.UserChooseMenuOption();

        switch (userInput) {
            case ADD_NEW_BOOK:
                AddNewItem(&ui, "Book");
                break;

            case ADD_NEW_MOVIE:
                AddNewItem(&ui, "Movie");
                break; 

            case FIND_BOOKS_THAT_RELEASE:
                LibaryForEach(&ui, FindItemByReleaseYear(ChooseNumOfYearsToSearchAndGetMinYearToSearch(&ui), "Book"));
                break;  

            case FIND_MOVIES_THAT_RELEASE:
                LibaryForEach(&ui, FindItemByReleaseYear(ChooseNumOfYearsToSearchAndGetMinYearToSearch(&ui), "Movie"));
                break;  

            case FIND_BOOKS_THAT_PURCHASED:
                LibaryForEach(&ui, FindItemByAddedTimeToCollection(ChooseNumOfYearsToSearchAndGetMinYearToSearch(&ui), "Book"));
                break;

            case FIND_MOVIES_THAT_PURCHASED:
                LibaryForEach(&ui, FindItemByAddedTimeToCollection(ChooseNumOfYearsToSearchAndGetMinYearToSearch(&ui), "Movie"));
                break;

            case FIND_BOOKS_THAT_CONTAINS:
                LibaryForEach(&ui, FindItemByInputStr(ChooseStringToSearch(&ui), "Book"));
                break;

            case FIND_MOVIES_THAT_CONTAINS:
                LibaryForEach(&ui, FindItemByInputStr(ChooseStringToSearch(&ui), "Movie"));
                break;
            
            case EXIT:
                ui.PrintGoodbyeMessage();
                return;

            default: 
                ui.PrintInvalidInput();
                break;
        }
    }
}

/*******************************************************
******************* Private Functions *******************
*******************************************************/

void LibaryApp::AddNewItem(const UI *a_ui, const std::string &a_collectionItemType) {
    a_ui->PrintChooseArtWorkName();
    char artWorkName[STRING_MAX_LENGTH + sizeof('\0')];
    a_ui->UserChooseStringInput(artWorkName);

    while (STRING_MAX_LENGTH < strlen(artWorkName)) {
        a_ui->PrintInvalidInput();
        a_ui->PrintChooseArtWorkName();
        a_ui->UserChooseStringInput(artWorkName);
    }

    a_ui->PrintChooseArtistName();
    char artistName[STRING_MAX_LENGTH + sizeof('\0')];
    a_ui->UserChooseStringInput(artistName);

    while (STRING_MAX_LENGTH < strlen(artistName)) {
        a_ui->PrintInvalidInput();
        a_ui->PrintChooseArtistName();
        a_ui->UserChooseStringInput(artistName);
    }

    a_ui->PrintChooseReleaseYear();
    char releaseYearStr[STRING_MAX_LENGTH + sizeof('\0')];
    a_ui->UserChooseStringInput(releaseYearStr);
    size_t releaseYear = atoi(releaseYearStr);

    while (NUM_OF_DIGITS_IN_YEAR != CountDigits(releaseYear) || MAX_YEAR_OF_ITEM < releaseYear) {
        a_ui->PrintInvalidInput();
        a_ui->PrintChooseReleaseYear();
        a_ui->UserChooseStringInput(releaseYearStr);
        releaseYear = atoi(releaseYearStr);
    }

    a_ui->PrintChooseAddedTimeToCollection();
    char addedTimeToCollectionStr[STRING_MAX_LENGTH + sizeof('\0')];
    a_ui->UserChooseStringInput(addedTimeToCollectionStr);
    size_t  addedTimeToCollection = atoi(addedTimeToCollectionStr);

    while (NUM_OF_DIGITS_IN_YEAR != CountDigits(addedTimeToCollection) || MAX_YEAR_OF_ITEM < releaseYear) {
        a_ui->PrintInvalidInput();
        a_ui->PrintChooseReleaseYear();
        a_ui->UserChooseStringInput(addedTimeToCollectionStr);
        addedTimeToCollection = atoi(addedTimeToCollectionStr);
    }

    if (a_collectionItemType == std::string("Book")) {
        BookInfo *newBook = new BookInfo(artWorkName, artistName, releaseYear, addedTimeToCollection);
        this->m_libary.Add(newBook);
        a_ui->PrintBookSuccessfullyAdded();
        return;
    }

    a_ui->PrintChooseGenre();
    size_t userInput = a_ui->UserChooseIntInput();
    MovieInfo::Genre genre;

    switch (userInput) {
        case USER_INPUT_ACTION:
            genre = MovieInfo::ACTION;
            break;
        
        case USER_INPUT_COMEDY:
            genre = MovieInfo::COMEDY;
            break;

        case USER_INPUT_DRAMA:
            genre = MovieInfo::DRAMA;
            break;

        case USER_INPUT_ANIME:
            genre = MovieInfo::ANIME;
            break;

        case USER_INPUT_OTHER:
            genre = MovieInfo::OTHER;
            break;
    }

    while (genre < MovieInfo::ACTION || MovieInfo::OTHER < genre) {
        a_ui->PrintInvalidInput();
        a_ui->PrintChooseGenre();
        userInput = a_ui->UserChooseIntInput();

        switch (userInput) {
        case USER_INPUT_ACTION:
            genre = MovieInfo::ACTION;
            break;
        
        case USER_INPUT_COMEDY:
            genre = MovieInfo::COMEDY;
            break;

        case USER_INPUT_DRAMA:
            genre = MovieInfo::DRAMA;
            break;

        case USER_INPUT_ANIME:
            genre = MovieInfo::ANIME;
            break;

        case USER_INPUT_OTHER:
            genre = MovieInfo::OTHER;
            break;
        }
    }

    MovieInfo *newMovie = new MovieInfo(artWorkName, artistName, genre, releaseYear, addedTimeToCollection);
    this->m_libary.Add(newMovie);

    a_ui->PrintMovieSuccessfullyAdded();
}

void LibaryApp::LibaryForEach(const UI *a_ui, const SearchCriteria &a_criteria) {  
    std::list<CollectionItem*>::const_iterator currIter = this->m_libary.Begin();
    std::list<CollectionItem*>::const_iterator endIter = this->m_libary.End();

    a_ui->PrintFoundArtWorks();

    for (;currIter != endIter;currIter++) {
        CollectionItem *currItem = *currIter;

        if (a_criteria.IsPassesCriteria(*currItem, currItem->GetCollectionType())) {
            a_ui->PrintFoundArtWorkName(static_cast<ArtWork*>(currItem)->GetArtWorkName());
        }
    }
}

size_t LibaryApp::ChooseNumOfYearsToSearchAndGetMinYearToSearch(const UI *a_ui) const {
    a_ui->PrintChooseNumberOfYearsToSearch();
    size_t numOfYearsToSearch = a_ui->UserChooseSizetInput();

    time_t currTime = time(NULL);
    struct tm *time = localtime(&currTime);
    size_t currYear = time->tm_year + TIME_T_START_YEAR;

    while (currYear - TIME_T_START_YEAR < numOfYearsToSearch) {
        a_ui->PrintInvalidInput();
        a_ui->PrintChooseNumberOfYearsToSearch();
        numOfYearsToSearch = a_ui->UserChooseSizetInput();
    }

    return currYear - numOfYearsToSearch;
}

std::string LibaryApp::ChooseStringToSearch(const UI *a_ui) const {
    char strToSearch[STRING_MAX_LENGTH + sizeof('\0')];
    
    a_ui->PrintChooseStrToSearch();
    a_ui->UserChooseStringInput(strToSearch);

    while (STRING_MAX_LENGTH < strlen(strToSearch) || !strToSearch) {
        a_ui->PrintInvalidInput();
        a_ui->PrintChooseStrToSearch();
        a_ui->UserChooseStringInput(strToSearch);
    }

    return std::string(strToSearch); 
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static size_t CountDigits(size_t a_num) {
    size_t numOfDigits = 0;

    while (a_num) {
        ++numOfDigits;
        a_num /= 10;
    }

    return numOfDigits;
} 

/******************************************************/