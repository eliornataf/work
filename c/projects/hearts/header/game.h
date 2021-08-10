/*****************************************************************************
* File Name: Game - ADT
* Written by: Elior Nataf
* Date: 9/3/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __GAME_H__
#define __GAME_H__

/*------------------------------- Header Files ------------------------------*/

#include "enums.h" /* Enums Header */

/*---------------------------------- Typedef --------------------------------*/

typedef struct Game Game_t;

/*------------------------------- Enum & Define -----------------------------*/

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creating a new game. Memory will be specially allocated.
 *
 * Input:
 * numOfPlayers - the number of players.
 * numOfDecks - the number of decks of cards.
 * isJokerInclude - is the decks of cards include jokers.
 * scoreToEnd - the number of points to end the game.
 * numOfHumanPlayers - the number of human players.
 * 
 * Output:
 * NULL - numOfPlayers invalid input (numOfPlayers = 0 || numOfPlayers = 1). 
 * NULL - numOfDecks invalid input (numOfDecks = 0).
 * NULL - isJokerInclude invalid input (0 !=_isJokerInclude && 1 != _isJokerInclude). 
 * NULL - scoreToEnd invalid input (scoreToEnd = 0). 
 * NULL - numOfHumanPlayers invalid input (_numOfPlayers <= _numOfHumanPlayers). 
 * NULL - allocation failed. 
 * game - pointer to new game.
 *
 * Error: 
 * NULL - numOfPlayers invalid input (numOfPlayers = 0). 
 * NULL - numOfDecks invalid input (numOfDecks = 0).
 * NULL - isJokerInclude invalid input (0 !=_isJokerInclude && 1 != _isJokerInclude). 
 * NULL - scoreToEnd invalid input (scoreToEnd = 0). 
 * NULL - _numOfHumanPlayers invalid input (_numOfPlayers <= _numOfHumanPlayers). 
 * NULL - allocation failed.
 */
Game_t *CreateGame(size_t numOfPlayers, size_t numOfDecks, int isJokerInclude, size_t scoreToEnd, size_t numOfHumanPlayers);

/* Description:
 * A function that destroys a specified game.
 *
 * Input:
 * game - pointer to game.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized, destroy is not possible.
 */
void DestroyGame(Game_t *game);

/* Description:
 * A function that runs a specified game. the function create a new
 * round, run it and destroy the round and the game in the end of the function.
 * the game ends then a one of the players receives the score to end or in failure.
 *
 * Input:
 * game - pointer to game.
 * 
 * Output:
 * FAILURE - game pointer is not initialize.
 * FAILURE - create/run round failed.
 * SUCCESS - run game is succeeded.
 *
 * Error: 
 * FAILURE - game pointer is not initialize.
 * FAILURE - create/run round failed.
 */
int RunGame(Game_t *game); 

#endif /* __GAME_H__ */
