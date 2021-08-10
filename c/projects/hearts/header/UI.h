/*****************************************************************************
* File Name: UI - ADT
* Written by: Elior Nataf
* Date: 9/3/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __UI_H__
#define __UI_H__

/*------------------------------- Header Files ------------------------------*/

#include "dynamicVector.h" /* Dynamic Vector header */

/*---------------------------------- Typedef --------------------------------*/

/*------------------------------- Enum & Define -----------------------------*/

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that prints a message welcome to the players of the game.
 *
 * Input:
 * None.
 * 
 * Output:
 * None.
 *
 * Error: 
 * None.
 */
void PrintWelcomeToTheGame(void);

/* Description:
 * A function that prints a message to the player to choose 3 cards to rotate.
 *
 * Input:
 * None.
 * 
 * Output:
 * None.
 *
 * Error: 
 * None.
 */
void PrintThreeCardToRotateMessage(void);

/* Description:
 * A function that prints the current trick number.
 *
 * Input:
 * numOfPlayers - the number of trick.
 * 
 * Output:
 * None.
 *
 * Error: 
 * None.
 */
void PrintNumOfTrick(size_t numOfTrick);

/* Description:
 * A function that prints message to the starting player of the round.
 *
 * Input:
 * numOfPlayers - the number of trick.
 * 
 * Output:
 * None.
 *
 * Error: 
 * None.
 */
void PrintYouAreTheStartingPlayerOfTheRound(void);

/* Description:
 * A function that prints message to the starting player of the trick.
 *
 * Input:
 * numOfPlayers - the number of trick.
 * 
 * Output:
 * None.
 *
 * Error: 
 * None.
 */
void PrintYouAreTheStartingPlayerOfTheTrick(void);

/* Description:
 * A function that prints message to player to choose card.
 *
 * Input:
 * numOfPlayers - the number of trick.
 * 
 * Output:
 * None.
 *
 * Error: 
 * None.
 */
void PrintPleaseChooseCardToPlay(void);

/* Description:
 * A function that prints a message after a round.
 *
 * Input:
 * numOfPlayers - the number of trick.
 * 
 * Output:
 * None.
 *
 * Error: 
 * None.
 */
void PrintMessageScoreTableAfterRound(size_t _roundNum);

/* Description:
 * A function that prints a message after error input, the card is not available.
 *
 * Input:
 * None.
 * 
 * Output:
 * None.
 *
 * Error: 
 * None.
 */
void PrintMessageTheCardIsNotAvailable(void);

/* Description:
 * A function that prints a message after error input.
 *
 * Input:
 * None.
 * 
 * Output:
 * None.
 *
 * Error: 
 * None.
 */
void PrintGoodByeMessage(void);

/* Description:
 * A function that find the suit of specified card.
 *
 * Input:
 * cardValue - the card value.
 *
 * Output:
 * SUIT_ERROR - card value error (BLACK_JOKER < cardValue).
 * card right suit.
 *
 * Error: 
 * SUIT_ERROR - card value error (BLACK_JOKER < cardValue).
 */
CardSuit_t FindCardSuit(int cardValue);

/* Description:
 * A function that prints the cards of a specified player.
 *
 * Input:
 * arrOfVectors - pointer to the player cards vectors.
 * 
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized, print player hands is not possible.
 */
void PrintPlayerHand(Vector_t **_arrOfVectors, size_t isJokerInclude);

/* Description:
 * A function that checks the input of a human player and print error of it is invalid.
 *
 * Input:
 * printErrorMessage - the parameter to check with if the input is invalid. if 
 * printErrorMessage is 1 the input is invalid, and if it is zero the input is ok.  
 * 
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized, check the player input is not possible.
 */
void CheckPlayerInvalidInput(int *printErrorMessage);

/* Description:
 * A function that gets card input from player.
 *
 * Input:
 * None.
 * 
 * Output:
 * choosen card value.
 *
 * Error: 
 * None.
 */
size_t GetCardFromHumanPlayer(void);

/* Description:
 * A function that prints the current play board.
 *
 * Input:
 * playBoard - pointer to play board.
 * numOfPlayers - the number of players.
 * 
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized, print table is not possible.
 * VectorGetElement WRONG_INDEX, print table is not possible.
 */
void PrintTable(Vector_t *playBoard, size_t numOfPlayers);

/* Description:
 * A function that prints the current score board.
 *
 * Input:
 * scoreBoard - pointer to score board.
 * numOfPlayers - the number of players.
 * startingPlayerIndex - the index of the starting player.
 * 
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized, print board is not possible.
 */
void PrintScoreBoard(int *scoreBoard, size_t numOfPlayers, size_t startingPlayerIndex);

/* Description:
 * A function that prints the current deck of cards.
 *
 * Input:
 * deckVector - pointer to deck of cards vector.
 * numOfDecks - the number of decks of cards in one deck.
 * isJokerInclude - is joker include in deck of cards.
 * 
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized - print deck of cards failed.
 */
void PrintDeckOfCards(Vector_t *deckVector, size_t numOfDecks, size_t isJokerInclude);

/* Description:
 * A function that prints the trick calculate, who start, who loose and the loser score.
 *
 * Input:
 * startingPlayer - the starting player of the trick.
 * loserIndex - the loser player index.
 * loserScore - the loser player score to get.
 * 
 * Output:
 * None.
 *
 * Error: 
 * None.
 */
void PrintTrickCalc(size_t startingPlayer, size_t loserIndex, size_t loserScore);

/* Description:
 * A function that prints the final score board of the game, who is the loser and his score.
 *
 * Input:
 * scoreBoard - pointer to score board.
 * numOfPlayers - the number of the players.
 * 
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized, print final score board is not possible.
 */
void PrintFinalScoreBoard(int *scoreBoard, size_t numOfPlayers);

#endif /* __UI_H__ */
