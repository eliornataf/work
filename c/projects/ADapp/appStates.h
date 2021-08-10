/*****************************************************************************
* File Name: APP States
* Written by: Elior Nataf
* Date: 19/2/21
******************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __APPSTATES_H__
#define __APPSTATES_H__

/*------------------------------- Header Files ------------------------------*/

/*---------------------------------- Typedef --------------------------------*/

/*------------------------------- Enum & Define -----------------------------*/

typedef enum app_states
{
	APP_IS_RUNNING = 0,
	
	OK = 1,
	POINTER_NOT_INITIALIZE = 2,

	ALLOCATION_FAILED = 3,
	APPOINTMENT_DAIRY_IS_ALREADY_INITIALIZED = 4,
	INCREASE_CAPACITY_AND_BLOCK_SIZE_ZERO = 4,

	APPOINTMENT_IS_ALREADY_INITIALIZED = 5,
	APPOINTMENT_START_TIME_ERROR = 6,
	APPOINTMENT_END_TIME_ERROR = 7,
	
	APPOINTMENT_DAIRY_IS_NOT_INITIALIZED = 8,
	APPOINTMENT_IS_NOT_INITIALIZED = 9,
	
	OVERFLOW = 10,
	REALLOCATION_FAILED = 11,
	
	UNDERFLOW = 12,
	THE_APPOINTMENT_IS_NOT_FOUND = 13,
	
	FILE_CREATE_FAILED = 14,
	FILE_OPEN_FAILED = 15, 
	
	USER_CHOOSES_TO_EXIT_LOAD_FILE = 16,
	
	STOP_APP_RUNNING
} app_states_t;

/*-------------------------- Functions declarations -------------------------*/

#endif /* __APPSTATES_H__ */
