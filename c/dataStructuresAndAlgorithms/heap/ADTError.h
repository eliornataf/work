/*****************************************************************************
* File Name: ADT Errors
* Written by: Elior Nataf
* Date: 16/2/21
******************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __ADTERROR_H__
#define __ADTERROR_H__

/*------------------------------- Header Files ------------------------------*/

/*---------------------------------- Typedef --------------------------------*/

/*------------------------------- Enum & Define -----------------------------*/

typedef enum ADTError
{
	OK = 0,
	POINTER_NOT_INITIALIZE = 1,
	REALLOCATION_FAILED = 2,
	OVERFLOW = 3,
	UNDERFLOW = 4
} ADTError_t;

/*-------------------------- Functions declarations -------------------------*/

#endif /* __ADTERROR_H__ */
