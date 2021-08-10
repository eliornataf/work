/*****************************************************************************
* File Name: UserInfo - ADT
* Written by: Eli & Elior & Nuriel
* Date: 26/4/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __USER_INFO_H__
#define __USER_INFO_H__

/*------------------------------- Header Files ------------------------------*/

#include "genericDoublyLinkedList.h" /* Generic Dobuly Linked */
#include "utilites.h" /* Utilites Header */

/*---------------------------------- Typedef --------------------------------*/

/*------------------------------- --- Define --------------------------------*/

#define MAX_LENGTH (256)

/*----------------------------------- Struct --------------------------------*/

typedef struct UserInfo
{
    byte m_userName[MAX_LENGTH];
    byte m_userPassword[MAX_LENGTH];
    int m_isConnect;
    List_t *m_userGroups;
} UserInfo_t;

/*------------------------------------ Enum ---------------------------------*/

/*-------------------------- Functions declarations -------------------------*/

#endif /* __USER_INFO_H__ */
