/*****************************************************************************
* File Name: Deck - ADT
* Written by: Elior Nataf
* Date: 9/3/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __DECK_H__
#define __DECK_H__

/*------------------------------- Header Files ------------------------------*/

#include "enums.h" /* Enums Header */
#include <stddef.h> /* size_t */

/*---------------------------------- Typedef --------------------------------*/

typedef struct Deck Deck_t;

/*------------------------------------ Enum ---------------------------------*/

/*---------------------------------- Define ---------------------------------*/

#define DRAW_CARD_FAILED (-1)

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creating a new deck. Memory will be specially allocated.
 *
 * Input:
 * numOfDecks - the number of decks of cards.
 * isJokerInclude - is the decks of cards include jokers.
 * 
 * Output: 
 * NULL - numOfDecks invalid input (numOfDecks = 0).
 * NULL - isJokerInclude invalid input (0 !=_isJokerInclude && 1 != _isJokerInclude). 
 * NULL - allocation failed. 
 * NULL - push cards to deck failed.
 * deck - pointer to new deck.
 *
 * Error: 
 * NULL - numOfDecks invalid input (numOfDecks = 0).
 * NULL - isJokerInclude invalid input (1 < isJokerInclude). 
 * NULL - allocation failed. 
 * NULL - push cards to deck failed.
 */
Deck_t *CreateDeck(size_t numOfDecks, int isJokerInclude);

/* Description:
 * A function that destroys a specified deck.
 *
 * Input:
 * deck - pointer to deck.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized, destroy is not possible.
 */
void DestroyDeck(Deck_t *deck);

/* Description:
 * A function that shuffle a specified deck.
 *
 * Input:
 * deck - pointer to deck.
 * 
 * Output:
 * FAILURE - deck pointer is not initialize, shuffle is not possible. 
 * SUCCESS - shuffle is succeeded.
 *
 * Error: 
 * FAILURE - deck pointer is not initialize, shuffle is not possible. 
 */
int ShuffleDeck(Deck_t *deck); 

/* Description:
 * A function that draw card from a specified deck.
 *
 * Input:
 * deck - pointer to deck.
 * 
 * Output:
 * DRAW_CARD_FAILED - deck pointer is not initialize, draw is not possible. 
 * DRAW_CARD_FAILED - draw card from deck is failed. 
 * draw card data.
 *
 * Error: 
 * DRAW_CARD_FAILED - deck pointer is not initialize, draw is not possible. 
 * DRAW_CARD_FAILED - draw card from deck is failed. 
 */
int DrawCardFromDeck(Deck_t *deck); 

#endif /* __DECK_H__ */
