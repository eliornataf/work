/*****************************************************************************
* File Name: Game - ADT
* Written by: Elior Nataf
* Date: 9/3/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __ROUND_H__
#define __ROUND_H__

/*------------------------------- Header Files ------------------------------*/

#include "player.h" /* Player Header */
#include "enums.h" /* Enums Header */

/*---------------------------------- Typedef --------------------------------*/

typedef struct Round Round_t;

/*------------------------------- Enum & Define -----------------------------*/

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creating a new round. Memory will be specially allocated.
 *
 * Input:
 * numOfPlayers - the number of players.
 * numOfDecks - the number of decks of cards.
 * isJokerInclude - is the decks of cards include jokers.
 * playersArr - pointer to players array.
 * 
 * Output:
 * NULL - playersArr pointer is not initialize, create is not possible.
 * NULL - allocation failed. 
 * game - pointer to new round.
 *
 * Error: 
 * NULL - playersArr pointer is not initialize, create is not possible.
 * NULL - allocation failed. 
 */
Round_t *CreateRound(size_t numOfPlayers, size_t numOfDecks, int isJokerInclude, Player_t **playersArr);

/* Description:
 * A function that destroys a specified round.
 *
 * Input:
 * round - pointer to round.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized, destroy is not possible.
 */
void DestroyRound(Round_t *round);

/* Description:
 * A function that runs a specified round.
 *
 * Input:
 * round - pointer to round.
 * scoreBoard- pointer to score board.
 *
 * Output:
 * FAILURE - pointer is not initialize, round is not possible.
 * FAILURE - create/suffle/draw deck is failed.
 * FAILURE - player get card/sort player card is failed.
 * FAILURE - three card action is failed.
 * FAILURE - put card on table is failed.
 * FAILURE - find loser and calc score is failed.
 * SUCCESS - run is succeeded.
 *
 * Error: 
 * FAILURE - pointer is not initialize, round is not possible.
 * FAILURE - create/suffle/draw deck is failed.
 * FAILURE - player get card/sort player card is failed.
 * FAILURE - three card action is failed.
 * FAILURE - put card on table is failed.
 * FAILURE - find loser and calc score is failed.
 */
int RunRound(Round_t *round, int *scoreBoard);

#endif /* __ROUND_H__ */
