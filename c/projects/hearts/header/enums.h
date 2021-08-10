/*****************************************************************************
* File Name: Enums
* Written by: Elior Nataf
* Date: 16/2/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __ENUMS_H__
#define __ENUMS_H__

/*------------------------------- Header Files ------------------------------*/

/*---------------------------------- Typedef --------------------------------*/

/*------------------------------- Enum & Define -----------------------------*/

typedef enum status
{
    SUCCESS = 0,
    FAILURE = 1
} status_t;

typedef enum CardSuit
{
    HEART = 0,
    SPADE = 1,
    DIAMOND = 2,
    CLUB = 3,
    JOKER = 4,
    SUIT_ERROR = 5,
    CARD_SUIT_NUM_OF_OPTIONS = 6
} CardSuit_t;

typedef enum ADTError
{
	OK = 0,
	POINTER_NOT_INITIALIZE = 1,
	REALLOCATION_FAILED = 2,
	OVERFLOW = 3,
	UNDERFLOW = 4,
	WRONG_INDEX = 5
} ADTError_t;

/*-------------------------- Functions declarations -------------------------*/

#endif /* __ENUMS_H__ */
