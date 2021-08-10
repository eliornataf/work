/*****************************************************************************
* File Name: ADT Errors
* Written by: Elior Nataf
* Date: 16/2/21
******************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __ADT_ERROR_H__
#define __ADT_ERROR_H__

/*------------------------------- Header Files ------------------------------*/

/*---------------------------------- Typedef --------------------------------*/

/*------------------------------- Enum & Define -----------------------------*/

typedef enum ADTError
{
	OK = 0,
	POINTER_NOT_INITIALIZE = 1,
	ALLOCATION_FAILED = 2,
	REALLOCATION_FAILED = 3,
	OVERFLOW = 4,
	UNDERFLOW = 5,
	WRONG_INDEX = 6
} ADTError_t;

/*-------------------------- Functions declarations -------------------------*/

#endif /* __ADT_ERROR_H__ */
