#include <stdio.h> /* fopen, fscanf, fclose */
#include <stdlib.h> /* malloc, free */
#include <string.h> /* strcpy, strcmp */
#include "userManager.h" /* User Manager Header */
#include "userInfo.h" /* User Data Header */
#include "genericDoublyLinkedList.h" /* Generic Dobuly Linked */
#include "listIter.h"

#define IS_NOT_CONNECT (0)
#define STR_LENGTH (100)
#define IS_CONNECT (1)
#define IS_NOT_EXIST (0)
#define IS_EXIST (1)
#define IS_NOT_CONNECTED (0)

/******************************************************/

struct UserManager
{
    List_t *m_userList;
    size_t m_numOfUsers;
};

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static Status_t AddUsersFromFile(UserManager_t *_userManager);
static Status_t InitUserInfo(UserInfo_t *_newUser, byte *_userName, byte *_userPassword);
static void DestroyUser(void *_user);
static UserManagerError_t IsUserExist(UserManager_t *userManager, byte *userName, UserInfo_t **foundUser);
static UserManagerError_t IsUserExistAndPasswordValid(UserManager_t *userManager, byte *userName, byte *userPassword);
static UserManagerError_t IfGroupExistRemove(UserInfo_t *foundUser, byte *groupName);
static void FreeGroup(void *group);
static UserManagerError_t IsUserJoinGroup(UserInfo_t *foundUser, byte *groupName);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

UserManager_t *CreateUserManager(void)
{
    UserManager_t *userManager = (UserManager_t*)malloc(sizeof(UserManager_t));
    if (!userManager)
    {
        return NULL;
    }
    
    userManager->m_userList = ListCreate();
    if (!userManager->m_userList)
    {
        free(userManager);
        return NULL;
    }

    if (FAILURE == AddUsersFromFile(userManager))
    {
        ListDestory(&userManager->m_userList, DestroyUser); 
        free(userManager);
        return NULL;
    }

    userManager->m_numOfUsers = ListSize(userManager->m_userList);

    return userManager;
}

void DestroyUserManager(UserManager_t **_userManager)
{
    if (!_userManager || *_userManager)
    {
        return;
    }

    ListDestory(&((*_userManager)->m_userList), DestroyUser); 

    free(_userManager);

    *_userManager = NULL;
}

UserManagerError_t UserRegister(UserManager_t *_userManager, byte *_userName, byte *_userPassword)
{
    UserInfo_t *newUser = NULL;
    UserInfo_t *foundUser = NULL;
    UserManagerError_t status;

    if (!_userManager || !_userName || !_userPassword)
    {
        return USER_MANAGER_IS_NOT_INITIALIZE;
    }

    if (USER_MANAGER_USER_NOT_FOUND != IsUserExist(_userManager, _userName, &foundUser))
    {
        return USER_MANAGER_USER_ALREADY_EXIST;
    }

    newUser = (UserInfo_t*)malloc(sizeof(UserInfo_t));
    if (!newUser)
    {
        return USER_MANAGER_ALLOCATION_FAILED;
    }

    if (SUCCESS != InitUserInfo(newUser, _userName, _userPassword))
    {
        free(newUser);
        return USER_MANAGER_USER_CREATION_FAILED;
    }

    if (DLIST_SUCCESS != ListPushTail(_userManager->m_userList, newUser))
    {
        free(newUser);
        return USER_MANAGER_USER_CREATION_FAILED;
    }

    return USER_MANAGER_SUCCESS;
}

UserManagerError_t UserLogin(UserManager_t *_userManager, byte *_userName, byte *_userPassword)
{
    if (!_userManager || !_userName || !_userPassword)
    {
        return USER_MANAGER_IS_NOT_INITIALIZE;
    }

    return IsUserExistAndPasswordValid(_userManager, _userName, _userPassword);
}

UserManagerError_t AddGroupToUser(UserManager_t *_userManager, byte *_userName, byte *_groupName)
{
    UserInfo_t *foundUser = NULL;
    byte *newGroupForUser = NULL;

    if (!_userManager || !_userName || !_groupName)
    {
        return USER_MANAGER_IS_NOT_INITIALIZE;
    }

    if (USER_MANAGER_USER_ALREADY_EXIST != IsUserExist(_userManager, _userName, &foundUser))
    {
        return USER_MANAGER_USER_NOT_FOUND;
    }

    if (USER_MANAGER_USER_IS_ALREADY_JOIN_GROUP == IsUserJoinGroup(foundUser, _groupName))
    {
        return USER_MANAGER_USER_IS_ALREADY_JOIN_GROUP;
    }

    newGroupForUser = (byte*)malloc((strlen((char*)_groupName) + 1) * sizeof(byte));
    if (!newGroupForUser)
    {
        return USER_MANAGER_ALLOCATION_FAILED;
    }

    strcpy((char*)newGroupForUser, (char*)_groupName);

    if (DLIST_SUCCESS != ListPushTail(foundUser->m_userGroups, newGroupForUser))
    {
        free(newGroupForUser);
        return USER_MANAGER_ADD_GROUP_TO_USER_FAILED;
    }

    return USER_MANAGER_SUCCESS;
}

UserManagerError_t RemoveGroupFromUser(UserManager_t *_userManager, byte *_userName, byte *_groupName)
{
    UserInfo_t *foundUser = NULL;

    if (!_userManager || !_userName || !_groupName)
    {
        return USER_MANAGER_IS_NOT_INITIALIZE;
    }

    if (USER_MANAGER_USER_ALREADY_EXIST != IsUserExist(_userManager, _userName, &foundUser))
    {
        return USER_MANAGER_USER_NOT_FOUND;
    }

    return IfGroupExistRemove(foundUser, _groupName);
}

UserManagerError_t LogoutUser(UserManager_t *_userManager, byte *_userName)
{
    UserInfo_t *foundUser = NULL;

    if (!_userManager || !_userName)
    {
        return USER_MANAGER_IS_NOT_INITIALIZE;
    }

    if (USER_MANAGER_USER_ALREADY_EXIST != IsUserExist(_userManager, _userName, &foundUser))
    {
        return USER_MANAGER_USER_NOT_FOUND;
    }

    ListDestory(&foundUser->m_userGroups, FreeGroup);
    foundUser->m_isConnect = IS_NOT_CONNECTED;

    return USER_MANAGER_SUCCESS;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static Status_t AddUsersFromFile(UserManager_t *_userManager)
{
    FILE *registerUserFile = NULL;
    UserInfo_t *newUser = NULL;
    byte userName[STR_LENGTH];
    byte userPassword[STR_LENGTH];

    registerUserFile = fopen("registerUserFile.txt", "a+");
	if (NULL == registerUserFile)
	{
		return FAILURE;
	}

    fscanf(registerUserFile, "%s %s", userName, userPassword); 

    while (!feof(registerUserFile))
	{
        newUser = (UserInfo_t*)malloc(sizeof(UserInfo_t));
        if (!newUser)
        {
            return FAILURE;
        }

        if (FAILURE == InitUserInfo(newUser, userName, userPassword))
        {
            free(newUser);
            return FAILURE;
        }

		if (DLIST_SUCCESS != ListPushTail(_userManager->m_userList, newUser))
        {
            free(newUser);
            return FAILURE;
        }

        fscanf(registerUserFile, "%s %s", userName, userPassword);                                                  
	}

    fclose(registerUserFile);

    return SUCCESS;
}

static Status_t InitUserInfo(UserInfo_t *_newUser, byte *_userName, byte *_userPassword)
{
    strcpy((char*)_newUser->m_userName, (char*)_userName);
    strcpy((char*)_newUser->m_userPassword, (char*)_userPassword);
    _newUser->m_isConnect = IS_NOT_CONNECT;
    _newUser->m_userGroups = ListCreate();
    if (!_newUser->m_userGroups)
    {
        return FAILURE;
    }

    return SUCCESS;
}

static void DestroyUser(void *_user)
{
    ListDestory(&((UserInfo_t*)_user)->m_userGroups, FreeGroup);
    free(_user);
}

static void FreeGroup(void *_group)
{
    free(_group);
}

static UserManagerError_t IsUserExist(UserManager_t *_userManager, byte *_userName, UserInfo_t **_foundUser)
{
    ListIter_t iterRunner = NULL;
    ListIter_t iterEnd = NULL;
    UserInfo_t *currUser = NULL;

    iterRunner = ListIterBegin(_userManager->m_userList);
    iterEnd = ListIterEnd(_userManager->m_userList);

    while (!ListIterEqual(iterRunner, iterEnd))
    {
        currUser = (UserInfo_t*)ListIterGet(iterRunner);

        if (!(strcmp((char*)currUser->m_userName, (char*)_userName)))
        {
            *_foundUser = currUser;
            return USER_MANAGER_USER_ALREADY_EXIST;
        }

        iterRunner = ListIterNext(iterRunner);
    }

    return USER_MANAGER_USER_NOT_FOUND;
}

static UserManagerError_t IsUserExistAndPasswordValid(UserManager_t *_userManager, byte *_userName, byte *_userPassword)
{
    ListIter_t iterRunner = NULL;
    ListIter_t iterEnd = NULL;
    UserInfo_t *currUser = NULL;

    iterRunner = ListIterBegin(_userManager->m_userList);
    iterEnd = ListIterEnd(_userManager->m_userList);

    while (!ListIterEqual(iterRunner, iterEnd))
    {
        currUser = (UserInfo_t*)ListIterGet(iterRunner);

        if (!(strcmp((char*)currUser->m_userName, (char*)_userName)))
        {
            if (!(strcmp((char*)currUser->m_userPassword, (char*)_userPassword)))
            {  
                if (currUser->m_isConnect)
                {
                    return USER_MANAGER_USER_IS_ALREADY_CONNECTED;
                }
                
                currUser->m_isConnect = IS_CONNECT;

                return USER_MANAGER_SUCCESS;
            }

            return USER_MANAGER_INCORRECT_PASSWORD;
        }
        
        iterRunner = ListIterNext(iterRunner);
    }

    return USER_MANAGER_USER_NOT_FOUND;
}

static UserManagerError_t IfGroupExistRemove(UserInfo_t *_foundUser, byte *_groupName)
{
    ListIter_t iterRunner = NULL;
    ListIter_t iterEnd = NULL;
    byte *currGroup = NULL;

    iterRunner = ListIterBegin(_foundUser->m_userGroups);
    iterEnd = ListIterEnd(_foundUser->m_userGroups);

    while (!ListIterEqual(iterRunner, iterEnd))
    {
        currGroup = (byte*)ListIterGet(iterRunner);

        if (!(strcmp((char*)currGroup, (char*)_groupName)))
        {
            ListIterRemove((void*)currGroup);
            free(currGroup);

            return USER_MANAGER_SUCCESS;
        }

        iterRunner = ListIterNext(iterRunner);
    }

    return USER_MANAGER_GROUP_NOT_FOUND;
}

static UserManagerError_t IsUserJoinGroup(UserInfo_t *_foundUser, byte *_groupName)
{
    ListIter_t iterRunner = NULL;
    ListIter_t iterEnd = NULL;
    void *currGroup = NULL;

    iterRunner = ListIterBegin(_foundUser->m_userGroups);
    iterEnd = ListIterEnd(_foundUser->m_userGroups);

    while (!ListIterEqual(iterRunner, iterEnd))
    {
        currGroup = ListIterGet(iterRunner);

        if (!(strcmp((char*)currGroup, (char*)_groupName)))
        {
            return USER_MANAGER_USER_IS_ALREADY_JOIN_GROUP;
        }

        iterRunner = ListIterNext(iterRunner);
    }

    return USER_MANAGER_GROUP_NOT_FOUND;
}