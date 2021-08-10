#include <iostream> /* cout */
#include <stdio.h> /* fflush, fgets */
#include "ui.hpp" /* UI Header */

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

UI::UI() {
}

UI::~UI() {
}

UI::UI(const UI &a_other) {
}

UI &UI::operator=(const UI &a_other) {
    return *this;
}

void UI::PrintWelcomeMessage() const {
    std::cout << "\033[1;35m" << "Welcome to Home Libary Application!" << "\033[0m" << std::endl;
}

void UI::PrintMenu() const {
    std::cout << "\033[1;33m" <<std::endl << "Please choose an action:" << std::endl;
    std::cout << std::endl << "Press 1 to add new Book";
    std::cout << std::endl << "Press 2 to add new Movie";
    std::cout << std::endl << "Press 3 to find books that released X years from now";
    std::cout << std::endl << "Press 4 to find movies that released X years from now";
    std::cout << std::endl << "Press 5 to find books that added to collection X years from now";
    std::cout << std::endl << "Press 6 to find movies that added to collection X years from now";
    std::cout << std::endl << "Press 7 to find books that contain your input string";
    std::cout << std::endl << "Press 8 to find movies that contain your input string";
    std::cout << std::endl << "Press 9 to exit Home Libary Application" << "\033[0m" << std::endl << std::endl;
}

void UI::PrintInvalidInput() const {
    std::cout << "\033[1;31m" << std::endl << "Invalid input, please try again" << "\033[0m" << std::endl;
}

void UI::PrintChooseArtWorkName() const {
    std::cout << "\033[1;34m" << std::endl << "Please choose Art Work Name (between 1 to 256 characters) [in order to insert more than one word use '_']:" << "\033[0m" << std::endl << std::endl;
}

void UI::PrintChooseArtistName() const {
    std::cout << "\033[1;34m" << std::endl << "Please choose artist name (between 1 to 256 characters) [in order to insert more than one word use '_']:" << "\033[0m" << std::endl << std::endl;
}

void UI::PrintChooseReleaseYear() const {
    std::cout << "\033[1;34m" << std::endl << "Please choose release year (4 digit number) [0-2021]:" << "\033[0m" << std::endl << std::endl;
}

void UI::PrintChooseAddedTimeToCollection() const {
    std::cout << "\033[1;34m" << std::endl << "Please choose added time to collection (4 digit number) [0-2021]:" << "\033[0m" << std::endl << std::endl;
}

void UI::PrintGoodbyeMessage() const {
    std::cout << "\033[1;35m" << std::endl << "Closing Application.. Goodbye!" << "\033[0m" << std::endl;
}

void UI::PrintChooseGenre() const {
    std::cout << "\033[1;34m" << std::endl << "Please choose genre (press 0 for 'Action', press 1 for 'Comedy', press 2 for 'Drama', press 3 for 'Anime', or press 4 for 'Other'):" << "\033[0m" << std::endl << std::endl;
}

void UI::PrintBookSuccessfullyAdded() const {
    std::cout << "\033[1;32m" << std::endl << "Book successfully added!" << "\033[0m" << std::endl;
}

void UI::PrintMovieSuccessfullyAdded() const {
    std::cout << "\033[1;32m" << std::endl << "Movie successfully added!" << "\033[0m" << std::endl;
}

void UI::PrintChooseNumberOfYearsToSearch() const {
    std::cout << "\033[1;34m" << std::endl << "Please choose number of years to search (between 1 to 121):" << "\033[0m" << std::endl << std::endl;
}

void UI::PrintFoundArtWorks() const {
    std::cout << "\033[1;36m" << std::endl << "The found artWorks are:" << "\033[0m" << std::endl;
}

void UI::PrintChooseStrToSearch() const {
    std::cout << "\033[1;34m" << std::endl << "Please choose string to search (between 1 to 256 characters): [in order to insert more than one word use '_']" << "\033[0m" << std::endl << std::endl;
}

void UI::PrintFoundArtWorkName(std::string a_artWorkName) const {
    std::cout << std::endl << a_artWorkName << std::endl;
}

int UI::UserChooseMenuOption() const {
    int userInput;
    
    fflush(stdin);
    scanf("%d", &userInput);
    fflush(stdin);

    return userInput;
}

void UI::UserChooseStringInput(char *a_str) const {
    fflush(stdin);
    scanf("%s", a_str);
    fflush(stdin);
}

int UI::UserChooseIntInput() const {
    int userInput;
    
    fflush(stdin);
    scanf("%d", &userInput);
    fflush(stdin);

    return userInput;
}

size_t UI::UserChooseSizetInput() const {
    size_t userInput;
    
    fflush(stdin);
    scanf("%lu", &userInput);
    fflush(stdin);

    return userInput;
}