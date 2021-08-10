/*****************************************************************************
* File Name: Protocol - ADT
* Written by: Eli & Elior & Nuriel
* Date: 26/4/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

/*------------------------------- Header Files ------------------------------*/

#include <limits.h> /* INT_MAX */
#include "utilites.h" /* Utilites Header */

/*---------------------------------- Typedef --------------------------------*/
typedef struct Message Message_t;

/*------------------------------- --- Define --------------------------------*/

#define FUNCTION_ERROR (INT_MAX)

/*------------------------------------ Enum ---------------------------------*/

typedef enum TagMessage
{
    TAG_RESPONSE_MESSAGE = 0,
    TAG_USER_REGISTER,
    TAG_USER_LOGIN,
    TAG_CREATE_GROUP,
    TAG_USER_JOIN_GROUP,
    TAG_USER_JOIN_GROUP_RESPONSE,
    TAG_USER_LEAVE_GROUP,
    TAG_USER_LOGOUT
} TagMessage_t;

typedef enum Reponse
{
    REGISTER_USER_ALREADY_EXIST = 0,
    REGISTER_USER_CREATE_ERROR,
    REGISTER_USER_SUCCESS,

    LOGIN_USER_NOT_FOUND,
    LOGIN_USER_INCORRECT_PASSWORD,
    LOGIN_USER_ALREADY_CONNECTED,
    LOGIN_USER_SUCCESS,

    GROUP_CREATE_GROUP_ALREADY_EXIST,
    GROUP_CREATE_CREATE_ERROR,
    GROUP_CREATE_SUCCESS,

    JOIN_GROUP_GROUP_NOT_FOUND,
    JOIN_GROUP_USER_IS_ALREADY_JOIN,
    JOIN_GROUP_JOIN_ERROR,
    JOIN_GROUP_USER_NOT_FOUND,
    JOIN_GROUP_SUCCESS,

    LEAVE_GROUP_NOT_FOUND,
    LEAVE_GROUP_ERROR,
    LEAVE_GROUP_SUCCESS,

    LOGOUT_FAILED,
    LOGOUT_SUCCESS
} Reponse_t;

/*----------------------------------- Struct --------------------------------*/

typedef struct UserData
{  
    byte m_userName[MAX_LENGTH];
    byte m_userPassword[MAX_LENGTH];
} UserData_t;

typedef struct ResponseMessage
{
    Reponse_t m_responeMessage;
} ResponseMessage_t;

typedef struct CreateGroup
{
    byte m_groupIPAddress[MAX_LENGTH];
    byte m_groupPort[MAX_LENGTH];
} CreateGroup_t;

typedef struct GroupData
{
    byte m_userName[MAX_LENGTH];
    byte m_groupName[MAX_LENGTH];
} GroupData_t;

typedef struct JoinGroupResponse
{
    byte m_groupIPAddress[MAX_LENGTH];
    byte m_groupPort[MAX_LENGTH];
    Reponse_t m_responeMessage;
} JoinGroupResponse_t;

typedef struct UserLogout
{  
    byte m_userName[MAX_LENGTH];
} UserLogout_t;

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that pack a new available message according to several parameters.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * messageTag - message tag (message type).
 * objectToPackMessageFrom - the object to pack message from.
 * buffer - the buffer to pack message to.
 *
 * Output:
 * FUNCTION_ERROR - messageTag invalid input (messageTag < 0), pack is not possible.
 * FUNCTION_ERROR - objectToPackMessageFrom pointer is not initialize, pack is not
 * possible.
 * The message length in byte (buffer length).
 * 
 * Error: 
 * FUNCTION_ERROR - messageTag invalid input (messageTag < 0), pack is not possible.
 * FUNCTION_ERROR - objectToPackMessageFrom pointer is not initialize, pack is not
 * possible.
 */
size_t PackMessage(TagMessage_t messageTag, void *objectToPackMessageFrom, byte *buffer);

/* Description:
 * A function that unpack a new available message according to several parameters.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * buffer - the buffer to unpack message from.
 * objectToUnPackMessage - the object to unpack message to.
 *
 * Output:
 * FUNCTION_ERROR - buffer/objectToUnPackMessage pointer is not initialize, unpack is 
 * not possible.
 * The message length in byte (buffer length).
 * 
 * Error: 
 * FUNCTION_ERROR - buffer/objectToUnPackMessage pointer is not initialize, unpack is 
 * not possible.
 */
size_t UnPackMessage(byte *buffer, void *objectToUnPackMessage);

/* Description:
 * A function that get message and returns message tag (message type).
 *
 * Time Complexity: O(1).
 *
 * Input:
 * message - the message to get tag from.
 *
 * Output:
 * FUNCTION_ERROR - message pointer is not initialize, get is not possible.
 * The message tag.  
 * 
 * Error: 
 * FUNCTION_ERROR - message pointer is not initialize, get is not possible.
 */
TagMessage_t GetMessageTag(byte *message);

/* Description:
 * A function that get message and checks if the message is complete.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * message - the message to check from.
 * givenMessageLength - the given message length to check with.
 *
 * Output:
 * ERROR - message pointer is not initialize, check is not possible.
 * ERROR - userGivenMessageLength invalid input (!userGivenMessageLength), 
 * check is not possible.
 * return 1 if message is complete (realMessageLength == userGivenMessageLength),
 * or zero if not.
 * 
 * Error: 
 * ERROR - message pointer is not initialize, check is not possible.
 * ERROR - userGivenMessageLength invalid input (!userGivenMessageLength), 
 * check is not possible.
 */
int IsCompleteMassage(byte *message, size_t givenMessageLength);

#endif /* __PROTOCOL_H__ */