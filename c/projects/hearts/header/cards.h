/*****************************************************************************
* File Name: Cards - ADT
* Written by: Elior Nataf
* Date: 9/3/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __CARDS_H__
#define __CARDS_H__

/*------------------------------- Header Files ------------------------------*/

/*---------------------------------- Typedef --------------------------------*/

/*------------------------------- Enum & Define -----------------------------*/

typedef enum Cards
{
	HEART_2 = 0, 
	HEART_3 = 1, 
	HEART_4 = 2, 
	HEART_5 = 3, 
	HEART_6 = 4, 
	HEART_7 = 5, 
	HEART_8 = 6, 
	HEART_9 = 7, 
	HEART_10 = 8, 
	HEART_J = 9, 
	HEART_Q = 10, 
	HEART_K = 11, 
    HEART_ACE = 12, 

    SPADE_2 = 13,
    SPADE_3 = 14,
    SPADE_4 = 15,
    SPADE_5 = 16,
    SPADE_6 = 17,
    SPADE_7 = 18,
    SPADE_8 = 19,
    SPADE_9 = 20,
    SPADE_10 = 21,
    SPADE_J = 22,
    SPADE_Q = 23,
    SPADE_K = 24,
    SPADE_ACE = 25,

    DIAMOND_2 = 26,
    DIAMOND_3 = 27,
    DIAMOND_4 = 28,
    DIAMOND_5 = 29,
    DIAMOND_6 = 30,
    DIAMOND_7 = 31,
    DIAMOND_8 = 32,
    DIAMOND_9 = 33,
    DIAMOND_10 = 34,
    DIAMOND_J = 35,
    DIAMOND_Q = 36,
    DIAMOND_K = 37,
    DIAMOND_ACE = 38,

    CLUB_2 = 39,
    CLUB_3 = 40,
    CLUB_4 = 41,
    CLUB_5 = 42,
    CLUB_6 = 43,
    CLUB_7 = 44,
    CLUB_8 = 45,
    CLUB_9 = 46,
    CLUB_10 = 47,
    CLUB_J = 48,
    CLUB_Q = 49,
    CLUB_K = 50,
    CLUB_ACE = 51,

    RED_JOKER = 52,
    BLACK_JOKER = 53,

    NUM_OF_CARDS = 54
} Cards_t;

/*-------------------------- Functions declarations -------------------------*/

#endif /* __CARDS_H__ */
