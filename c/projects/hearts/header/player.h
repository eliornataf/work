/*****************************************************************************
* File Name: Player - ADT
* Written by: Elior Nataf
* Date: 9/3/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __PLAYER_H__
#define __PLAYER_H__

/*------------------------------- Header Files ------------------------------*/

#include "enums.h" /* Enums Header */
#include "dynamicVector.h" /* Dynamic Vector header */

/*---------------------------------- Typedef --------------------------------*/

typedef struct Player Player_t;
typedef int (*Strategy_t)(Vector_t **arrOfVectors, CardSuit_t cardSuit, int *isHeartCardPresented, size_t numOfTrick);

/*------------------------------- Enum & Define -----------------------------*/

#define IS_NOT_FOUND (-1)
#define IS_FOUND (1)
#define ERROR_GIVE_CARD (-1)

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creating a new player. Memory will be specially allocated.
 *
 * Input:
 * playerName - the name of the player.
 * isHuman - is the player human or computer.
 * numOfDecks - the number of decks of cards.
 * isJokerInclude - is the decks of cards include jokers.
 * 
 * Output:
 * NULL - playerName pointer is not initialize.
 * NULL - isHuman invalid input (0 !=_isJokerInclude && 1 != _isJokerInclude). 
 * NULL - numOfDecks invalid input (numOfDecks = 0).
 * NULL - isJokerInclude invalid input (0 !=_isJokerInclude && 1 != _isJokerInclude). 
 * NULL - allocation failed. 
 * player - pointer to new player.
 *
 * Error: 
 * NULL - playerName pointer is not initialize.
 * NULL - isHuman invalid input (0 !=_isJokerInclude && 1 != _isJokerInclude). 
 * NULL - numOfDecks invalid input (numOfDecks = 0).
 * NULL - isJokerInclude invalid input (0 !=_isJokerInclude && 1 != _isJokerInclude). 
 * NULL - allocation failed.
 */
Player_t *CreatePlayer(char *playerName, int isHuman, size_t numOfDecks, int isJokerInclude);

/* Description:
 * A function that destroys a specified player.
 *
 * Input:
 * player - pointer to player.
 *
 * Output:
 * None.
 *
 * Error: 
 * player pointer is not initialized, destroy is not possible.
 */
void DestroyPlayer(Player_t *player);

/* Description:
 * A function that check if player is human or computer.
 *
 * Input:
 * player - pointer to player.
 *
 * Output:
 * IS_NOT_HUMAN - player pointer is not initialized, check is not possible.
 * IS_HUMAN if player is human, IS_NOT_HUMAN if player is not human.
 *
 * Error: 
 * IS_NOT_HUMAN - player pointer is not initialized, check is not possible.
 */
int PlayerIsHuman(Player_t *player);

/* Description:
 * A function that get a card for a specified player.
 *
 * Input:
 * player - pointer to player.
 * drawCardData - the data of the draw card.
 * 
 * Output:
 * FAILURE - player pointer is not initialized., get card is not possible.
 * FAILURE - card data is not familiar.
 * FAILURE - get player card failed.
 * SUCCESS - get card to player is succeeded.
 *
 * Error: 
 * FAILURE - player pointer is not initialized., get card is not possible.
 * FAILURE - card data is not familiar.
 * FAILURE - get player card failed.
 */
int PlayerGetCard(Player_t *_player, int _drawCardData);

/* Description:
 * A function that sorts the players cards by rank.
 *
 * Input:
 * player - pointer to player.
 * 
 * Output:
 * FAILURE - player pointer is not initialized, sort is not possible.
 * SUCCESS - sort is succeeded.
 *
 * Error: 
 * FAILURE - player pointer is not initialized, sort is not possible.
 */
int SortPlayerCardsByRank(Player_t *player);

/* Description:
 * A function that search if a card is exists in a specified player.
 *
 * Input:
 * player - pointer to player.
 * searchCardData - the data of the search card.
 * 
 * Output:
 * IS_NOT_FOUND - player pointer is not initialized, search card is not possible.
 * IS_NOT_FOUND - data card error (BLACK_JOKER < cardData).
 * IS_NOT_FOUND if the card is not found, IS_FOUND if the card is found.
 *
 * Error: 
 * IS_NOT_FOUND - player pointer is not initialized, search card is not possible.
 * IS_NOT_FOUND - data card error (BLACK_JOKER < cardData).
 */
int PlayerSearchCardByIndex(Player_t *player, int searchCardData);

/* Description:
 * A function that gives a card.
 *
 * Input:
 * player - pointer to player.
 * searchCardData - the data of the search card.
 * 
 * Output:
 * ERROR_GIVE_CARD - the pointer is not initialized.
 * ERROR_GIVE_CARD - data card error (BLACK_JOKER < cardData).
 * ERROR_GIVE_CARD - error output card data.
 * IS_FOUND - the card is found.
 *
 * Error: 
 * ERROR_GIVE_CARD - the pointer is not initialized.
 * ERROR_GIVE_CARD - data card error (BLACK_JOKER < cardData).
 * ERROR_GIVE_CARD - error output card data.
 */
int PlayerGiveCard(Player_t *_player, int _cardData, int *_isHeartCardPresented, size_t _numOfTrick, Strategy_t _strategyFunc);

#endif /* __PLAYER_H__ */
