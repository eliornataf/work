#include <bits/stdc++.h>
#include <iostream> /* cout */
#include <stdexcept> /* expection */
#include <stdlib.h> /* atoi */
#include <string.h> /* strstr */
#include <time.h> /* time_t */
#include "homeLibaryApp.hpp" /* Home Libary Application Header */
#include "bookInfo.hpp" /* Book Info Header */
#include "movieInfo.hpp" /* Movie Info Header */
#include "singlyLinkedListForBooks.hpp" /* Singly Linked List For Books Header */
#include "singlyLinkedListForMovies.hpp" /* Singly Linked List For Movies Header */
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

HomeLibaryApp::HomeLibaryApp() 
: m_singlyLinkedListForBooks()
, m_singlyLinkedListForMovies() {
}

HomeLibaryApp::~HomeLibaryApp() {
}

HomeLibaryApp::HomeLibaryApp(const HomeLibaryApp &a_other) 
: m_singlyLinkedListForBooks(a_other.m_singlyLinkedListForBooks)
, m_singlyLinkedListForMovies(a_other.m_singlyLinkedListForMovies) {        
}

HomeLibaryApp &HomeLibaryApp::operator=(const HomeLibaryApp &a_other) {
    this->m_singlyLinkedListForBooks = a_other.m_singlyLinkedListForBooks;
    this->m_singlyLinkedListForMovies = a_other.m_singlyLinkedListForMovies;

    return *this;
}

void HomeLibaryApp::RunApp() {
    UI ui; 

    ui.PrintWelcomeMessage();

    while (1) {
        ui.PrintMenu();
        int userInput = ui.UserChooseMenuOption();

        switch (userInput) {
            case ADD_NEW_BOOK:
                AddBook(&ui);
                break;

            case ADD_NEW_MOVIE:
                AddMovie(&ui);
                break; 

            case FIND_BOOKS_THAT_RELEASE:
                FindBooksThatReleasedXYearsFromNow(&ui, ChooseNumOfYearsToSearch(&ui));
                break;  

            case FIND_MOVIES_THAT_RELEASE:
                FindMoviesThatReleasedXYearsFromNow(&ui, ChooseNumOfYearsToSearch(&ui));
                break;  

            case FIND_BOOKS_THAT_PURCHASED:
                FindBooksThatPurchasedXYearsFromNow(&ui, ChooseNumOfYearsToSearch(&ui));
                break;

            case FIND_MOVIES_THAT_PURCHASED:
                FindMoviesThatPurchasedXYearsFromNow(&ui, ChooseNumOfYearsToSearch(&ui));
                break;

            case FIND_BOOKS_THAT_CONTAINS:
                char strToSearchBooks[STRING_MAX_LENGTH + sizeof('\0')];
                ChooseStringToSearch(&ui, strToSearchBooks);
                FindBooksThatContainInputStr(&ui, strToSearchBooks);
                break;

            case FIND_MOVIES_THAT_CONTAINS:
                char strToSearchMovies[STRING_MAX_LENGTH + sizeof('\0')];
                ChooseStringToSearch(&ui, strToSearchMovies);
                FindBooksThatContainInputStr(&ui, strToSearchMovies);
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

void HomeLibaryApp::AddBook(const UI *a_ui) {
    a_ui->PrintChooseBookName();
    char bookName[STRING_MAX_LENGTH + sizeof('\0')];
    a_ui->UserChooseStringInput(bookName);

    while (STRING_MAX_LENGTH < strlen(bookName)) {
        a_ui->PrintInvalidInput();
        a_ui->PrintChooseBookName();
        a_ui->UserChooseStringInput(bookName);
    }
    
    a_ui->PrintChooseAuthorName();
    char authorName[STRING_MAX_LENGTH + sizeof('\0')];
    a_ui->UserChooseStringInput(authorName);

    while (STRING_MAX_LENGTH < strlen(authorName)) {
        a_ui->PrintInvalidInput();
        a_ui->PrintChooseAuthorName();
        a_ui->UserChooseStringInput(authorName);
    }

    a_ui->PrintChooseReleaseYear();
    char releaseYearStr[STRING_MAX_LENGTH + sizeof('\0')];
    a_ui->UserChooseStringInput(releaseYearStr);
    size_t releaseYear = atoi(releaseYearStr);

    while (NUM_OF_DIGITS_IN_YEAR != CountDigits(releaseYear)) {
        a_ui->PrintInvalidInput();
        a_ui->PrintChooseReleaseYear();
        a_ui->UserChooseStringInput(releaseYearStr);
        releaseYear = atoi(releaseYearStr);
    }

    a_ui->PrintChoosePurchasedYear();
    char purchasedYear[PURCHASED_YEAR_LENGTH + sizeof('\0')];
    a_ui->UserChooseStringInput(purchasedYear);

    while (PURCHASED_YEAR_LENGTH != strlen(purchasedYear)) {
        a_ui->PrintInvalidInput();
        a_ui->PrintChoosePurchasedYear();
        a_ui->UserChooseStringInput(purchasedYear);
    }

    BookInfo newBook(bookName, authorName, releaseYear, purchasedYear);

    this->m_singlyLinkedListForBooks.PushTail(newBook);

    a_ui->PrintBookSuccessfullyAdded();
}

void HomeLibaryApp::AddMovie(const UI *a_ui) {
    a_ui->PrintChooseMovieName();
    char movieName[STRING_MAX_LENGTH + sizeof('\0')];
    a_ui->UserChooseStringInput(movieName);

    while (STRING_MAX_LENGTH < strlen(movieName)) {
        a_ui->PrintInvalidInput();
        a_ui->PrintChooseMovieName();
        a_ui->UserChooseStringInput(movieName);
    }
    
    a_ui->PrintChooseDirectorName();
    char directorName[STRING_MAX_LENGTH + sizeof('\0')];
    a_ui->UserChooseStringInput(directorName);

    while (STRING_MAX_LENGTH < strlen(directorName)) {
        a_ui->PrintInvalidInput();
        a_ui->PrintChooseDirectorName();
        a_ui->UserChooseStringInput(directorName);
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

    a_ui->PrintChooseReleaseYear();
    char releaseYearStr[STRING_MAX_LENGTH + sizeof('\0')];
    a_ui->UserChooseStringInput(releaseYearStr);
    size_t releaseYear = atoi(releaseYearStr);

    while (NUM_OF_DIGITS_IN_YEAR != CountDigits(releaseYear))
    {
        a_ui->PrintInvalidInput();
        a_ui->PrintChooseReleaseYear();
        a_ui->UserChooseStringInput(releaseYearStr);
        releaseYear = atoi(releaseYearStr);
    }

    a_ui->PrintChoosePurchasedYear();
    char purchasedYear[PURCHASED_YEAR_LENGTH + sizeof('\0')];
    a_ui->UserChooseStringInput(purchasedYear);

    while (PURCHASED_YEAR_LENGTH != strlen(purchasedYear))
    {
        a_ui->PrintInvalidInput();
        a_ui->PrintChoosePurchasedYear();
        a_ui->UserChooseStringInput(purchasedYear);
    }

    MovieInfo newMovie(movieName, directorName, genre ,releaseYear, purchasedYear);

    this->m_singlyLinkedListForMovies.PushTail(newMovie);

    a_ui->PrintMovieSuccessfullyAdded();
}

size_t HomeLibaryApp::ChooseNumOfYearsToSearch(const UI *a_ui) const {   
    a_ui->PrintChooseNumberOfYearsToSearch();
    size_t numOfYearsToSearch = a_ui->UserChooseSizetInput();

    while (MAX_NUM_OF_YEARS_TO_SEARCH < numOfYearsToSearch) {
        a_ui->PrintInvalidInput();
        a_ui->PrintChooseNumberOfYearsToSearch();
        numOfYearsToSearch = a_ui->UserChooseSizetInput();
    }

    return numOfYearsToSearch;
}

void HomeLibaryApp::ChooseStringToSearch(const UI *a_ui, char *a_str) const {
    a_ui->PrintChooseStrToSearch();
    a_ui->UserChooseStringInput(a_str);

    while (STRING_MAX_LENGTH < strlen(a_str)) {
        a_ui->PrintInvalidInput();
        a_ui->PrintChooseStrToSearch();
        a_ui->UserChooseStringInput(a_str);
    }
}

void HomeLibaryApp::FindBooksThatReleasedXYearsFromNow(const UI *a_ui, const size_t a_numOfYearsToSearch) const {
    time_t currTime = time(NULL);
    struct tm *time = localtime(&currTime);
    size_t currYear = time->tm_year + TIME_T_START_YEAR;

    if (currYear - TIME_T_START_YEAR < a_numOfYearsToSearch) {
        throw std::invalid_argument("a_numOfYearsToSearch invalid input");
    }

    a_ui->PrintBooksThatReleasedXYearsFromNow(a_numOfYearsToSearch);

    for (size_t i = 0, listSize = this->m_singlyLinkedListForBooks.Size();i < listSize;++i)
    {
        BookInfo currBook = this->m_singlyLinkedListForBooks.GetBook(i);
        size_t currBookReleaseYear = currBook.GetReleaseYear();

        if ( (currYear - a_numOfYearsToSearch) <= currBookReleaseYear )
        {
            std::cout << std::endl << currBook.GetName() << std::endl;
        }
    }
}

void HomeLibaryApp::FindMoviesThatReleasedXYearsFromNow(const UI *a_ui, const size_t a_numOfYearsToSearch) const {
    time_t currTime = time(NULL);
    struct tm *time = localtime(&currTime);
    size_t currYear = time->tm_year + TIME_T_START_YEAR;

    a_ui->PrintMoviesThatReleasedXYearsFromNow(a_numOfYearsToSearch);

    for (size_t i = 0, listSize = this->m_singlyLinkedListForMovies.Size();i < listSize;++i)
    {
        MovieInfo currMovie = this->m_singlyLinkedListForMovies.GetMovie(i);
        size_t currMovieReleaseYear = currMovie.GetReleaseYear();

        if ( (currYear - a_numOfYearsToSearch) <= currMovieReleaseYear )
        {
            std::cout << std::endl << currMovie.GetName() << std::endl;
        }
    }
}

void HomeLibaryApp::FindBooksThatPurchasedXYearsFromNow(const UI *a_ui, const size_t a_numOfYearsToSearch) const {
    time_t currTime = time(NULL);
    struct tm *time = localtime(&currTime);
    size_t currYear = time->tm_year + TIME_T_START_YEAR;

    for (size_t i = 0, listSize = this->m_singlyLinkedListForBooks.Size(); i < listSize;++i)
    {
        BookInfo currBook = this->m_singlyLinkedListForBooks.GetBook(i);
        char *currBookPurchasedDate = new char[strlen(currBook.GetPurchasedDate()) + sizeof('\0')];
        strcpy(currBookPurchasedDate, currBook.GetPurchasedDate());

        currBookPurchasedDate += STR_POSITION_YEAR_START;
        char purchasedYearStr[NUM_OF_DIGITS_IN_YEAR + sizeof('\0')];
        strncpy(purchasedYearStr, currBookPurchasedDate, NUM_OF_DIGITS_IN_YEAR);
        size_t purchasedYear = atoi(purchasedYearStr);

        a_ui->PrintBooksThatPurchasedXYearsFromNow(a_numOfYearsToSearch);

        if ( (currYear - a_numOfYearsToSearch) <= purchasedYear)
        {
            std::cout << std::endl << currBook.GetName() << std::endl;
        }

        currBookPurchasedDate -= STR_POSITION_YEAR_START;
        delete[] currBookPurchasedDate;
    }
}

void HomeLibaryApp::FindMoviesThatPurchasedXYearsFromNow(const UI *a_ui, const size_t a_numOfYearsToSearch) const {
    time_t currTime = time(NULL);
    struct tm *time = localtime(&currTime);
    size_t currYear = time->tm_year + TIME_T_START_YEAR;

    for (size_t i = 0, listSize = this->m_singlyLinkedListForMovies.Size();i < listSize;++i)
    {
        MovieInfo currMovie = this->m_singlyLinkedListForMovies.GetMovie(i);
        char *currMoviePurchasedDate = new char[strlen(currMovie.GetPurchasedDate()) + sizeof('\0')];
        strcpy(currMoviePurchasedDate, currMovie.GetPurchasedDate());
        
        currMoviePurchasedDate += STR_POSITION_YEAR_START;
        char purchasedYearStr[NUM_OF_DIGITS_IN_YEAR + sizeof('\0')];
        strncpy(purchasedYearStr, currMoviePurchasedDate, NUM_OF_DIGITS_IN_YEAR);
        size_t purchasedYear = atoi(purchasedYearStr);

        a_ui->PrintMoviesThatPurchasedXYearsFromNow(a_numOfYearsToSearch);

        if ( (currYear - a_numOfYearsToSearch) <= purchasedYear )
        {
            std::cout << std::endl << currMovie.GetName() << std::endl;
        }

        currMoviePurchasedDate -= STR_POSITION_YEAR_START;
        delete[] currMoviePurchasedDate;
    }
}

void HomeLibaryApp::FindBooksThatContainInputStr(const UI *a_ui, const char *a_str) const {
    if (!a_str) {
		throw std::invalid_argument("NULL pointer error");
	}

    a_ui->PrintBooksThatContainInputStr(a_str);

    for (size_t i = 0, listSize = this->m_singlyLinkedListForBooks.Size();i < listSize;++i)
    {
        BookInfo currBook = this->m_singlyLinkedListForBooks.GetBook(i);
        char *currBookName = new char[strlen(currBook.GetName()) + sizeof('\0')];
        strcpy(currBookName, currBook.GetName());

        if (strstr(currBookName, a_str))
        {
            std::cout << std::endl << currBookName << std::endl;
        }

        delete[] currBookName;
    }
}

void HomeLibaryApp::FindMoviesThatContainInputStr(const UI *a_ui, const char *a_str) const {
    if (!a_str) {
		throw std::invalid_argument("NULL pointer error");
	}

    a_ui->PrintMoviesThatContainInputStr(a_str);

    for (size_t i = 0, listSize = this->m_singlyLinkedListForMovies.Size(); i < listSize;++i)
    {
        MovieInfo currMovie = this->m_singlyLinkedListForMovies.GetMovie(i);
        char *currMovieName = new char[strlen(currMovie.GetName()) + sizeof('\0')];
        strcpy(currMovieName, currMovie.GetName());
        
        if (strstr(currMovieName, a_str))
        {
            std::cout << std::endl << currMovieName << std::endl;
        }

        delete[] currMovieName;
    }
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