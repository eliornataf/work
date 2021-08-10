/*****************************************************************************
* File Name: Client Manager - ADT
* Written by: Eli & Elior & Nuriel
* Date: 26/4/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __CLIENT_MANAGER_H__
#define __CLIENT_MANAGER_H__

/*------------------------------- Header Files ------------------------------*/

#include "utilites.h" /* Utilites Header */

/*----------------------------------- Struct --------------------------------*/

/*---------------------------------- Typedef --------------------------------*/

typedef struct Client Client_t; 

/*------------------------------------ Enum ---------------------------------*/

typedef enum ClientManagerError
{
    CLIENT_MANAGER_NOT_INITIALIZE,
    CLIENT_MANAGER_ALLOCATION_FAILED,
    CLIENT_MANAGER_ILLEGAL_INPUT,
    CLIENT_MANAGER_PACK_FAILED,
    CLIENT_MANAGER_SEND_MESSAGE_FAILED,
    CLIENT_MANAGER_UNPACK_FAILED,
    CLIENT_MANAGER_RECEIVED_FAILED,
    CLIENT_MANAGER_CRITICAL_ERROR,
    CLIENT_MANAGER_FAILED,
    CLIENT_MANAGER_LOGOUT_FAILED,
    CLIENT_MANAGER_GROUP_JOIN_FAILED,
    CLIENT_MANAGER_SUCCESS
} ClientManagerError_t;

typedef enum MainMenuOptions
{
    MAIN_MENU_OPTION_START_MENU = 0,
    MAIN_MENU_OPTION_REGISTER,
    MAIN_MENU_OPTION_LOGIN,
    MAIN_MENU_OPTION_EXIT = 9
} MainMenuOptions_t;

typedef enum GroupMenuOptions
{
    GROUP_MENU_OPTION_START_MENU = 0,
    GROUP_MENU_OPTION_CREATE_GROUP,
    GROUP_MENU_OPTION_JOIN_GROUP,
    GROUP_MENU_OPTION_LEAVE_GROUP,
    GROUP_MENU_OPTION_LOGOUT = 9
} GroupMenuOptions_t;

/*------------------------------- --- Define --------------------------------*/

/*-------------------------- Functions declarations -------------------------*/

/*
Description: Run client app include of register, login, and chat 
Input: n/a
Output: int - 1 - ran seccuesfully, 0 - run failed
Errror: 0 - if failed
Comment: uses TCP client app to initiate the connection
Comment: server details: IP: 127.0.0.1 (loopback), port: 1025 
*/
Status_t RunClientManager(void);

#endif /* __CLIENT_MANAGER_H__ */
