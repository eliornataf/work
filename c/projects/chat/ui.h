/*****************************************************************************
* File Name: UI - ADT
* Written by: Eli & Elior & Nuriel
* Date: 26/4/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __UI_H__
#define __UI_H__

/*------------------------------- Header Files ------------------------------*/

#include "utilites.h" /* Utilites Header */

/*----------------------------------- Struct --------------------------------*/

/*---------------------------------- Typedef --------------------------------*/

/*------------------------------------ Enum ---------------------------------*/

/*------------------------------- --- Define --------------------------------*/

/*-------------------------- Functions declarations -------------------------*/

int UIChooseMenuOption(int *userInput);

Status_t UIinputNameOrPasswordOrGroup(byte *buffer);

void PrintFailedToConnectServer(void);

void PrintMainMenu(void);

void PrintChooseUserName(void);

void PrintChooseUserPassword(void);

void PrintRegisterUserExists(void);

void PrintRegisterCreationError(void);

void PrintRegisterSuccess(void);

void PrintLoginUserNotFound(void);

void PrintLoginWrongPassword(void);

void PrintLoginUserAlreadyConnected(void);

void PrintLoginUserLoginSuccess(void);

void PrintUserChooseIllegalInput(void);

void PrintExitingApp(void);

void PrintGroupMenuGroup(void);

void PrintChooseGroupName(void);

void PrintCreateGroupGroupAlreadyExist(void);

void PrintCreateGroupCreateError(void);

void PrintCreateGroupSuccess(void);

void PrintJoinGroupGroupNotFound(void);

void PrintJoinGroupCreateError(void);

void PrintJoinGroupUserNotFound(void);

void PrintJoinUserIsAlreadyJoinGroup(void);

void PrintJoinGroupSuccess(void);

void PrintLeaveGroupNotFound(void);

void PrintLeaveGroupError(void);

void PrintLeaveGroupSuccess(void);

void PrintLogOutNotFound(void);

void PrintLogOutError(void);

void PrintLogoutSuccess(void);

#endif /* __UI_H__ */
