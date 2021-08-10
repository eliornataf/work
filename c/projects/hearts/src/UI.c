#include <stdio.h> /* printf, putchar */
#include "enums.h" /* Enums Header */
#include "dynamicVector.h" /* Dynamic Vector header */
#include "cards.h" /* Cards Header */
#include "UI.h" /* UI Header */

#define TEN_VALUE (10)
#define J_VALUE (11)
#define Q_VALUE (12)
#define K_VALUE (13)
#define A_VALUE (14)

#define CARDS_ON_SUIT (13)
#define NUM_OF_SUITS (4)
#define NUM_OF_JOKERS (2)
#define MAX_CARD_VALUE (15)

#define NOT_PRINT (0)
#define PRINT (1)

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static void PrintCardsWithSuitAndColors(int _currDataElement);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

void PrintWelcomeToTheGame(void)
{
    printf("\033[1;32m\n\n*******Welcome To The Game:*******\n\n\033[0m");
}

void PrintThreeCardToRotateMessage(void)
{
    printf("\033[1;37mPlease choose three card to rotate:\n\033[0m");
}

void PrintNumOfTrick(size_t _numOfTrick)
{
    printf("\033[1;34m\n*******Trick Number %ld:*******\n\n\033[0m", _numOfTrick + 1);
}

void PrintYouAreTheStartingPlayerOfTheRound(void)
{
    printf("\033[1;37m\nYour are the statring player of the round, please choose a card:\n\n\033[0m");
}

void PrintYouAreTheStartingPlayerOfTheTrick(void) 
{
    printf("\033[1;37m\nYour are the statring player of the trick, please choose a card:\n\033[0m");
}

void PrintPleaseChooseCardToPlay(void)
{
    printf("\033[1;37mplease choose a card:\n\033[0m");
}

void PrintMessageScoreTableAfterRound(size_t _roundNum)
{
    printf("\033[1;33m\n*******Score Table - after round %ld:*******\n\n\033[0m", _roundNum + 1);
}

void PrintMessageTheCardIsNotAvailable(void)
{
    printf("\033[1;31m\nThe card is not available, Please Choose other card\n\033[0m");
}

void PrintGoodByeMessage(void)
{
    printf("\033[1;32m\nThe Game End, Goodbye!\n\n\033[0m");
}

CardSuit_t FindCardSuit(int _cardValue)
{
    if (HEART_2 <= _cardValue && _cardValue <= HEART_ACE)
    {
        return HEART;
    }
    
    if (SPADE_2 <= _cardValue && _cardValue <= SPADE_ACE)
    {
        return SPADE;
    }
    
    if (DIAMOND_2 <= _cardValue && _cardValue <= DIAMOND_ACE)
    {
        return DIAMOND;
    }
    
    if (CLUB_2 <= _cardValue && _cardValue <= CLUB_ACE)
    {
        return CLUB;
    }

    if (RED_JOKER <= _cardValue && _cardValue <= BLACK_JOKER)
    {
        return JOKER;
    }

    return SUIT_ERROR;
}

void PrintPlayerHand(Vector_t **_arrOfVectors, size_t _isJokerInclude)
{
    size_t i, j, vecNumOfElements;
    int currElementData;

    if (NULL == _arrOfVectors)
    {
        return;
    }

    printf("\033[1;39m\nPlayer Hand:\n\n\033[0m");

    for (i = 0;i < NUM_OF_SUITS + _isJokerInclude;++i)
    {
        VectorNumOfElements(_arrOfVectors[i], &vecNumOfElements);

        for (j = 0;j < vecNumOfElements;++j)
        {
            VectorGetElement(_arrOfVectors[i], j, &currElementData);

            PrintCardsWithSuitAndColors(currElementData);   
        }
    }

    putchar('\n');
}

void CheckPlayerInvalidInput(int *_printErrorMessage) /* doc */
{
    if (NULL == _printErrorMessage)
    {
        return;
    }

    if (PRINT == *_printErrorMessage)
    {
        PrintMessageTheCardIsNotAvailable();
    }

    *_printErrorMessage = PRINT;

    return;
}

size_t GetCardFromHumanPlayer(void)
{
    size_t cardSuit, cardValue;
    int printErrorMessage = NOT_PRINT;

    do
    {
        CheckPlayerInvalidInput(&printErrorMessage);        

        printf("\nPlease enter card suit [ 0(\033[1;31m\xE2\x99\xA5\033[0m) ,1(\033[1;30m\xE2\x99\xA0\033[0m) ,2(\033[1;31m\xE2\x99\xA6\033[0m) ,3(\033[1;30m\xE2\x99\xA3\033[0m) ]: ");
        scanf("%lu", &cardSuit);
    } 
    while (NUM_OF_SUITS <= cardSuit);
    
    printErrorMessage = NOT_PRINT;

    do
    {
        CheckPlayerInvalidInput(&printErrorMessage);        

        printf("\nPlease enter card value [2, 3, 4, 5, 6, 7, 8, 9, 10, 11(J), 12(Q), 13(K), 14(A)]: ");
        scanf("%lu", &cardValue);
    } 
    while (MAX_CARD_VALUE <= cardValue);

    return (cardSuit * 13 + cardValue - 2);
}

void PrintTable(Vector_t *_playBoard, size_t numOfPlayers)
{
    int currDataElement;
    size_t i;

    if (NULL == _playBoard)
    {
        return;
    }

    printf("\033[1;32mPlay Board:\n\n\033[0m");

    for (i = 0;i < numOfPlayers;++i)
    {
        if (WRONG_INDEX == VectorGetElement(_playBoard, i, &currDataElement))
        {
            break;
        }

        PrintCardsWithSuitAndColors(currDataElement);
    }

    printf("\n\n");
}

void PrintScoreBoard(int *_scoreBoard, size_t _numOfPlayers, size_t _startingPlayerIndex)
{
    size_t i, j;

    if (NULL == _scoreBoard)
    {
        return;
    }

    for (i = 0, j = _startingPlayerIndex;i < _numOfPlayers;++i, j = (j + 1) % _numOfPlayers)
    {
        printf("\033[1;35mP%ld: \t\033[0m",j);
    }

    printf("\n");

    for (i = 0, j = _startingPlayerIndex;i < _numOfPlayers;++i, j = (j + 1) % _numOfPlayers)
    {
        printf("\033[1;35m%d\t\033[0m", _scoreBoard[j]);
    }

    printf("\n\n");
}

void PrintDeckOfCards(Vector_t *_deckVector, size_t _numOfDecks, size_t _isJokerInclude)
{
    int currElementData;
    size_t i;
    
    if (NULL == _deckVector)
    {
        return;
    }

    for (i = 0;i < ((CARDS_ON_SUIT * NUM_OF_SUITS + NUM_OF_JOKERS * _isJokerInclude) * _numOfDecks);++i)
    {
        VectorGetElement(_deckVector, i, &currElementData);

        PrintCardsWithSuitAndColors(currElementData);
    }

    printf("\n\n");
}

void PrintTrickCalc(size_t _startingPlayer, size_t _loserIndex, size_t _loserScore)
{
    printf("\033[1;39mPlayer number %ld start the round\nPlayer number %ld lose the round and get %ld points\n\033[0m", _startingPlayer, _loserIndex, _loserScore);
}

void PrintFinalScoreBoard(int *_scoreBoard, size_t _numOfPlayers)
{
    size_t i, maxScorePlayerIndex;
    int maxScoreData;

    if (NULL == _scoreBoard)
    {
        return;
    }

    for (i = 0;i < _numOfPlayers;++i)
    {
        if (i == 0 || maxScoreData < _scoreBoard[i])
        {
            maxScoreData = _scoreBoard[i];
            maxScorePlayerIndex = i;
        }

        printf("\033[1;39mPlayer number %ld score is %d\n\033[0m", i, _scoreBoard[i]);
    }

    printf("\033[1;31m\nThe loser of the game is player number %ld and his score is %d\n\033[0m", maxScorePlayerIndex, _scoreBoard[maxScorePlayerIndex]);
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static void PrintCardsWithSuitAndColors(int _currDataElement)
{
    int cardValue;
    CardSuit_t cardSuit;
    char firstDigitNum = '0';
    char lastDigitNum = '\0';

    cardSuit = FindCardSuit(_currDataElement);
    cardValue = (_currDataElement % 13) + 2;
    
    if (TEN_VALUE == cardValue)
    {
        cardValue = 1;
        lastDigitNum = '0';
    }

    if (J_VALUE == cardValue)
    {
            cardValue = 26;
    }

    if (Q_VALUE == cardValue)
    {
        cardValue = 33;
    }

    if (K_VALUE == cardValue)
    {
        cardValue = 27;
    }

    if (A_VALUE == cardValue)
    {
        cardValue = 17;
    }

    firstDigitNum += cardValue;

    if (HEART == cardSuit)
    {
        printf("\033[1;31m%c%c\xE2\x99\xA5\t\033[0m", firstDigitNum, lastDigitNum);
    }

    else if (SPADE == cardSuit)
    {
        printf("\033[1;30m%c%c\xE2\x99\xA0\t\033[0m", firstDigitNum, lastDigitNum);
    }

    else if (DIAMOND == cardSuit)
    {
        printf("\033[1;31m%c%c\xE2\x99\xA6\t\033[0m", firstDigitNum, lastDigitNum);
    }

    else if (CLUB == cardSuit)
    {
        printf("\033[1;30m%c%c\xE2\x99\xA3\t\033[0m", firstDigitNum, lastDigitNum);
    }
}