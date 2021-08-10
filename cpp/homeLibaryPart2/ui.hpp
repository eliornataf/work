/*****************************************************************************
* File Name: UI
* Written by: Elior Nataf
* Date: 6/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __UI_H__
#define __UI_H__

/*------------------------------- Header Files ------------------------------*/

/*-------------------------------- Structure -------------------------------*/

class UI {
public:
    // Constructor

    UI();

    // Destructor

    ~UI();

    // Copy Constructor

    UI(const UI &a_other);

    // Assignment Operator

    UI &operator=(const UI &a_other);

    // Functions

    void PrintWelcomeMessage() const;
    void PrintMenu() const;
    void PrintInvalidInput() const;
    void PrintChooseArtWorkName() const;
    void PrintChooseArtistName() const ;
    void PrintChooseReleaseYear() const;
    void PrintChooseAddedTimeToCollection() const; 
    void PrintChooseGenre() const;
    void PrintBookSuccessfullyAdded() const;
    void PrintMovieSuccessfullyAdded() const;
    void PrintChooseNumberOfYearsToSearch() const;
    void PrintFoundArtWorks() const;
    void PrintChooseStrToSearch() const;
    void PrintFoundArtWorkName(std::string a_artWorkName) const;
    void PrintGoodbyeMessage() const;

    int UserChooseMenuOption() const;
    void UserChooseStringInput(char *a_str) const;
    int UserChooseIntInput() const;
    size_t UserChooseSizetInput() const;

private:
    // Constants

    static const size_t MAX_USER_INPUT = 1;
};

#endif /* __UI_H__ */
