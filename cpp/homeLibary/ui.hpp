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
    // Enum

    enum Status {
        SUCCESS = 0,
        FAILURE
    };

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
    void PrintChooseBookName() const;
    void PrintChooseAuthorName() const;
    void PrintChooseReleaseYear() const;
    void PrintChoosePurchasedYear() const;
    void PrintBookSuccessfullyAdded() const;
    void PrintInvalidInput() const;
    void PrintChooseMovieName() const;
    void PrintChooseDirectorName() const;
    void PrintChooseGenre() const;
    void PrintMovieSuccessfullyAdded() const;
    void PrintChooseNumberOfYearsToSearch() const;
    void PrintChooseStrToSearch() const;
    void PrintGoodbyeMessage() const;
    void PrintBooksThatReleasedXYearsFromNow(const size_t a_numOfYearsToSearch) const;
    void PrintMoviesThatReleasedXYearsFromNow(const size_t a_numOfYearsToSearch) const;
    void PrintBooksThatPurchasedXYearsFromNow(const size_t a_numOfYearsToSearch) const;
    void PrintMoviesThatPurchasedXYearsFromNow(const size_t a_numOfYearsToSearch) const;
    void PrintBooksThatContainInputStr(const char *a_str) const;
    void PrintMoviesThatContainInputStr(const char *a_str) const;

    int UserChooseMenuOption() const;
    void UserChooseStringInput(char *a_str) const;
    int UserChooseIntInput() const;
    size_t UserChooseSizetInput() const;

private:
    // Constants

    static const size_t MAX_USER_INPUT = 1;
};

#endif /* __UI_H__ */
