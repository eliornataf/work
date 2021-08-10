/*****************************************************************************
* File Name: UserManager - ADT
* Written by: Eli & Elior & Nuriel
* Date: 26/4/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __USER_MANAGER_H__
#define __USER_MANAGER_H__

/*------------------------------- Header Files ------------------------------*/

#include "utilites.h" /* Utilites Header */

/*----------------------------------- Struct --------------------------------*/

/*---------------------------------- Typedef --------------------------------*/
typedef struct UserManager UserManager_t;

typedef enum UserManagerError
{
    USER_MANAGER_IS_NOT_INITIALIZE,
    USER_MANAGER_USER_ALREADY_EXIST,
    USER_MANAGER_USER_NOT_FOUND,
    USER_MANAGER_ALLOCATION_FAILED,
    USER_MANAGER_USER_CREATION_FAILED,
    USER_MANAGER_INCORRECT_PASSWORD,
    USER_MANAGER_USER_IS_ALREADY_CONNECTED,
    USER_MANAGER_ADD_GROUP_TO_USER_FAILED,
    USER_MANAGER_USER_IS_ALREADY_JOIN_GROUP,
    USER_MANAGER_GROUP_NOT_FOUND,
    USER_MANAGER_SUCCESS
} UserManagerError_t;

/*------------------------------------ Enum ---------------------------------*/

/*------------------------------- --- Define --------------------------------*/

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creates a new available user manager. User manager
 * loads the registered users from the file (in case file is exist) and
 * adds them to the user list. Memory will be specially allocated. 
 *
 * Time Complexity: O(1).
 *
 * Input:
 * None.
 *
 * Output:
 * NULL - memory allocation failed.
 * NULL - create user manager error.
 * userManager - pointer to new created user manager.  
 * 
 * Error: 
 * NULL - memory allocation failed.
 * NULL - create user manager error.
 */
UserManager_t *CreateUserManager(void);

/* Description:
 * A function that destroys a specified user manager. Previously allocated 
 * memory will be free. All remaining data will be lost.
 *
 * Time Complexity: O(n).
 *
 * Input:
 * None.
 *
 * Output:
 * None.  
 * 
 * Error: 
 * userManager pointer is not initialized, destroy is not possible.
 */
void DestroyUserManager(UserManager_t **userManager);

/* Description:
 * A function that creates a new user. If userName is already exist in
 * users list, create is not possible (userName is unique). Memory 
 * will be specially allocated. 
 *
 * Time Complexity: O(n).
 *
 * Input:
 * userManager - pointer to user manager.
 * userName - pointer to user name to create user with.
 * userPassword - pointer to user password to create user with.
 *
 * Output:
 * USER_MANAGER_IS_NOT_INITIALIZE - userManager/userName/userPassword 
 * pointer is not initialize, register is not possible.
 * USER_MANAGER_USER_ALREADY_EXIST - the userName is already exists, register
 * is not possible.
 * USER_MANAGER_ALLOCATION_FAILED - memory allocation failed.
 * USER_MANAGER_USER_CREATION_FAILED - register user function error.
 * USER_MANAGER_SUCCESS - the user register succeeded.
 * 
 * Error: 
 * USER_MANAGER_IS_NOT_INITIALIZE - userManager/userName/ userPassword 
 * pointer is not initialize, register is not possible.
 * USER_MANAGER_USER_ALREADY_EXIST - the userName is already exists, register
 * is not possible.
 * USER_MANAGER_ALLOCATION_FAILED - memory allocation failed.
 * USER_MANAGER_USER_CREATION_FAILED - register user function error.
 */
UserManagerError_t UserRegister(UserManager_t *userManager, byte *userName, byte *userPassword);

/* Description:
 * A function that log in a register user. In case userName or UserPassword
 * is not correct logs in is not possible.
 *
 * Time Complexity: O(n).
 *
 * Input:
 * userManager - pointer to user manager.
 * userName - pointer to user name to log in user with.
 * userPassword - pointer to user password to log in user with.
 *
 * Output:
 * USER_MANAGER_IS_NOT_INITIALIZE - userManager/userName/userPassword 
 * pointer is not initialize, log in is not possible.
 * USER_MANAGER_USER_IS_ALREADY_CONNECTED - the userName is already
 * connected.
 * USER_MANAGER_INCORRECT_PASSWORD - the userPassword is incorrect.
 * USER_MANAGER_USER_NOT_FOUND - the user is not found.
 * USER_MANAGER_SUCCESS - the user log in succeeded.
 * 
 * Error: 
 * USER_MANAGER_IS_NOT_INITIALIZE - userManager/userName/userPassword 
 * pointer is not initialize, log in is not possible.
 * USER_MANAGER_USER_IS_ALREADY_CONNECTED - the userName is already
 * connected.
 * USER_MANAGER_INCORRECT_PASSWORD - the userPassword is incorrect.
 * USER_MANAGER_USER_NOT_FOUND - the user is not found.
 */
UserManagerError_t UserLogin(UserManager_t *userManager, byte *userName, byte *userPassword);

/* Description:
 * A function that add group to specified user group list. Memory will be 
 * specially allocated. 
 *
 * Time Complexity: O(n).
 *
 * Input:
 * userManager - pointer to user manager.
 * userName - pointer to user name to add group with.
 * userPassword - pointer to user password to add group with.
 *
 * Output:
 * USER_MANAGER_IS_NOT_INITIALIZE - userManager/userName/groupName 
 * pointer is not initialize, add group is not possible.
 * USER_MANAGER_USER_NOT_FOUND - the user is not found.
 * USER_MANAGER_USER_IS_ALREADY_JOIN_GROUP - user already join group.
 * USER_MANAGER_ALLOCATION_FAILED - memory allocation failed.
 * USER_MANAGER_ADD_GROUP_TO_USER_FAILED - add group function error. 
 * USER_MANAGER_SUCCESS - add group to user succeeded.
 * 
 * Error: 
 * USER_MANAGER_IS_NOT_INITIALIZE - userManager/userName/groupName 
 * pointer is not initialize, add group is not possible.
 * USER_MANAGER_USER_NOT_FOUND - the user is not found.
 * USER_MANAGER_USER_IS_ALREADY_JOIN_GROUP - user already join group.
 * USER_MANAGER_ALLOCATION_FAILED - memory allocation failed.
 * USER_MANAGER_ADD_GROUP_TO_USER_FAILED - add group function error.  
 */
UserManagerError_t AddGroupToUser(UserManager_t *userManager, byte *userName, byte *groupName);

/* Description:
 * A function that removes group to specified user group list.
 *
 * Time Complexity: O(n).
 *
 * Input:
 * userManager - pointer to user manager.
 * userName - pointer to user name to remove group with.
 * userPassword - pointer to user password to remove group with.
 *
 * Output:
 * USER_MANAGER_IS_NOT_INITIALIZE - userManager/userName/groupName 
 * pointer is not initialize, remove group is not possible.
 * USER_MANAGER_USER_NOT_FOUND - the user is not found.
 * USER_MANAGER_GROUP_NOT_FOUND - the group is not found.
 * USER_MANAGER_SUCCESS - remove group to user succeeded.
 * 
 * Error: 
 * USER_MANAGER_IS_NOT_INITIALIZE - userManager/userName/groupName 
 * pointer is not initialize, remove group is not possible.
 * USER_MANAGER_USER_NOT_FOUND - the user is not found.
 * USER_MANAGER_GROUP_NOT_FOUND - the group is not found.
 */
UserManagerError_t RemoveGroupFromUser(UserManager_t *userManager, byte *userName, byte *groupName);

/* Description:
 * A function that logs out logged in user. the log out disconnected 
 * the user and clear all user groups.
 *
 * Time Complexity: O(n).
 *
 * Input:
 * userManager - pointer to user manager.
 * userName - pointer to user name to log out with.
 *
 * Output:
 * USER_MANAGER_IS_NOT_INITIALIZE - userManager/userName pointer 
 * is not initialize, log out is not possible.
 * USER_MANAGER_USER_NOT_FOUND - the user is not found.
 * USER_MANAGER_SUCCESS - log out succeeded.
 * 
 * Error: 
 * USER_MANAGER_IS_NOT_INITIALIZE - userManager/userName pointer 
 * is not initialize, log out is not possible.
 * USER_MANAGER_USER_NOT_FOUND - the user is not found.
 */
UserManagerError_t LogoutUser(UserManager_t *userManager, byte *userName);

#endif /* __USER_MANAGER_H__ */
