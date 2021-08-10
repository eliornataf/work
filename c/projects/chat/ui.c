#include <stdio.h> /* fgets, fflush, printf */
#include <string.h> /* strlen */
#include "ui.h" /* UI Header */

#define FGETS_MAX_LENGTH (2)
#define USER_NAME_PASSWORD_GROUP_MIN_LENGTH (2)
#define USER_NAME_PASSWORD_GROUP_MAX_LENGTH (256)

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static void PrintUserNameOrPasswordOrGroupTooShortOrLong(void);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

int UIChooseMenuOption(int *_userInput)
{
    byte buffer[FGETS_MAX_LENGTH];
  
    fflush(stdin);
    fgets((char*)buffer, FGETS_MAX_LENGTH, stdin);
    fflush(stdin);

    *_userInput = buffer[0] - '0';
}

Status_t UIinputNameOrPasswordOrGroup(byte *_buffer)
{
    size_t bufferLength;

    fflush(stdin);
    fgets((char*)_buffer, MAX_LENGTH, stdin);
    fflush(stdin);

    _buffer[strlen((char*)_buffer) - 1] = '\0';

    bufferLength = strlen((char*)_buffer);

    if (bufferLength < USER_NAME_PASSWORD_GROUP_MIN_LENGTH || USER_NAME_PASSWORD_GROUP_MAX_LENGTH < bufferLength)
    {
        PrintUserNameOrPasswordOrGroupTooShortOrLong();
        return FAILURE;
    }
    
    return SUCCESS;
}

/****************** Print Functions *******************/

void PrintFailedToConnectServer(void)
{
    printf("**************************************************\n");
    printf("\033[1;31mFailed to connect the server, close connection, Goodbye!\n\033[0m");
    printf("**************************************************\n\n");
}

void PrintMainMenu(void)
{
    printf("\033[1;34m**************************************************\n\033[0m");
    printf("\033[1;34mWelcome to our chat. Please choose your next step:\n\033[0m");
    printf("\033[1;34mType '1' to register new user\n\033[0m");
    printf("\033[1;34mType '2' to login user\n\033[0m");
    printf("\033[1;34mType '9' to exit app\n\033[0m");
    printf("\033[1;34m**************************************************\n\n\033[0m");
}

void PrintChooseUserName(void)
{
    printf("\033[1;34m**************************************************\n\033[0m");
    printf("\033[1;34mPlease enter user name [2 to 256 characters]:\n\033[0m");
    printf("\033[1;34m**************************************************\n\n\033[0m");
}

void PrintChooseUserPassword(void)
{
    printf("\033[1;34m**************************************************\n\033[0m");
    printf("\033[1;34mPlease enter password (between 2 to 256 characters):\n\033[0m");
    printf("\033[1;34m**************************************************\n\n\033[0m");
}

void PrintRegisterUserExists(void)
{
    printf("**************************************************\n");
    printf("\033[1;31mFailed to register! User already exists!\n\033[0m");
    printf("**************************************************\n");
    putchar('\n');
}

void PrintRegisterCreationError(void)
{
    printf("****************************************************\n");
    printf("\033[1;31mRegister encountered some problems. Closing client, Goodbye!\n\033[0m");
    printf("****************************************************\n\n");
}

void PrintRegisterSuccess(void)
{
    printf("**************************************************\n");
    printf("\033[1;32mUser registered successfully. Welcome aboard!\n\033[0m");
    printf("**************************************************\n\n");
}

void PrintLoginUserNotFound(void)
{
    printf("**************************************************\n");
    printf("\033[1;31mFailed to Login! User not found\n\033[0m");
    printf("**************************************************\n\n");
}

void PrintLoginWrongPassword(void)
{
    printf("**************************************************\n");
    printf("\033[1;31mFailed to Login! Password is incorrect!\n\033[0m");
    printf("**************************************************\n\n");
}

void PrintLoginUserAlreadyConnected(void)
{
    printf("**************************************************\n");
    printf("\033[1;31mFailed to Login. User already connected!\n\033[0m");
    printf("**************************************************\n\n");
}

void PrintLoginUserLoginSuccess(void)
{
    printf("**************************************************\n");
    printf("\033[1;32mLogin succeeded!\n\033[0m");
    printf("**************************************************\n\n");
}

void PrintUserChooseIllegalInput(void)
{
    printf("\033[1;32m**************************************************\n\033[0m");
    printf("\033[1;31mYou choose invalid key!\n\033[0m");
    printf("\033[1;32m**************************************************\n\n\033[0m");
}

void PrintExitingApp(void)
{
    printf("\033[1;34m**************************************************\n\033[0m");
    printf("\033[1;34mExiting App, Goodbye!\n\033[0m");
    printf("\033[1;34m**************************************************\n\n\033[0m");
}

void PrintGroupMenuGroup(void)
{
    printf("\033[1;34m**************************************************\n\033[0m");
    printf("\033[1;34mWelcome. Please choose your next step:\n\033[0m");
    printf("\033[1;34mType '1' to create group\n\033[0m");
    printf("\033[1;34mType '2' to join group\n\033[0m");
    printf("\033[1;34mType '3' to leave group\n\033[0m");
    printf("\033[1;34mType '9' to logout\n\033[0m");
    printf("\033[1;34m**************************************************\n\n\033[0m");
}

void PrintChooseGroupName(void)
{
    printf("\033[1;34m**************************************************\n\033[0m");
    printf("\033[1;34mPlease enter group name [2 to 256 characters]:\n\033[0m");
    printf("\033[1;34m**************************************************\n\n\033[0m");
}

void PrintCreateGroupGroupAlreadyExist(void)
{
    printf("**************************************************\n");
    printf("\033[1;31mFailed to create group. Group already exist!\n\033[0m");
    printf("**************************************************\n");
    putchar('\n');
}

void PrintCreateGroupCreateError(void)
{
    printf("****************************************************\n");
    printf("\033[1;31mCreate group encountered some problems. Closing client, Goodbye!\n\033[0m");
    printf("****************************************************\n\n");
}

void PrintCreateGroupSuccess(void)
{
    printf("**************************************************\n");
    printf("\033[1;34mGroup created successfully!\n\033[0m");
    printf("**************************************************\n\n");
}

void PrintJoinGroupGroupNotFound(void)
{
    printf("**************************************************\n");
    printf("\033[1;31mFailed to Join Group! Group not found\n\033[0m");
    printf("**************************************************\n\n");
}

void PrintJoinGroupCreateError(void)
{
    printf("****************************************************\n");
    printf("\033[1;31mJoin group encountered some problems. Closing client, Goodbye!\n\033[0m");
    printf("****************************************************\n\n");
}

void PrintJoinGroupUserNotFound(void)
{
    printf("**************************************************\n");
    printf("\033[1;31mFailed to Join Group! User not found\n\033[0m");
    printf("**************************************************\n\n");
}

void PrintJoinGroupSuccess(void)
{
    printf("**************************************************\n");
    printf("\033[1;34mConenction Succeeded! Welcome to the group!\n\033[0m");
    printf("**************************************************\n\n");
}

void PrintLeaveGroupNotFound(void)
{
    printf("**************************************************\n");
    printf("\033[1;31mFailed to leave group! Group or user not found!\n\033[0m");
    printf("**************************************************\n\n");
}

void PrintLeaveGroupError(void)
{
    printf("**************************************************\n");
    printf("\033[1;31mLeave group encountered some problems. Closing client, Goodbye!\n\033[0m");
     printf("**************************************************\n\n");
}

void PrintJoinUserIsAlreadyJoinGroup(void)
{
    printf("**************************************************\n");
    printf("\033[1;31mFailed to Join Group! User already join group\n\033[0m");
    printf("**************************************************\n\n");
}

void PrintLeaveGroupSuccess(void)
{
    printf("**************************************************\n");
    printf("\033[1;33mGroup closed successfully\n\033[0m");
    printf("**************************************************\n\n");
}

void PrintLogOutNotFound(void)
{
    printf("**************************************************\n");
    printf("\033[1;31mFailed to logout! Group or not found!\n\033[0m");
    printf("**************************************************\n\n");
}

void PrintLogOutError(void)
{
    printf("**************************************************\n");
    printf("\033[1;31mLogout encountered some problems. Closing client, Goodbye!\n\033[0m");
    printf("**************************************************\n\n");
}

void PrintLogoutSuccess(void)
{
    printf("**************************************************\n");
    printf("\033[1;33mThe user log out successfully\n\033[0m");
    printf("**************************************************\n\n");
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static void PrintUserNameOrPasswordOrGroupTooShortOrLong(void)
{
    printf("\033[1;32m**************************************************\n\033[0m");
    printf("\033[1;32mUser name or password or group is too short or long [please choose parameters between 2 to 256 characters]\n\033[0m");
    printf("\033[1;32m**************************************************\n\n\033[0m");
}