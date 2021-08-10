#include <stdlib.h> /* malloc, free */
#include <string.h> /* strcpy, strcmp */
#include "groupData.h" /* Group Data Header */
#include "ipManager.h" /* IP Manager Header */
#include "groupManager.h" /* Group Manager Header */
#include "genericDoublyLinkedList.h" /* Generic Doubly Linked List Header */
#include "listIter.h" /* List Iterator Header */

#define IP_LENGTH (12)
#define PORT (9999)
#define ONE_USER_IN_GROUP (1)

/******************************************************/

struct GroupManager
{
    IPManager_t *m_ipManager;
    List_t *m_listOfGroups;
};

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static GroupData_t *SearchGroup(GroupManager_t *groupManager, byte *groupName);
static Status_t AddGroup(GroupManager_t *groupManager, byte *groupName);
static void DestroyGroup(GroupManager_t *groupManager, GroupData_t **group);
static void DestroyGroupFromList(void *group);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

GroupManager_t *CreateGroupManager(void)
{
    GroupManager_t *groupManager = (GroupManager_t*)malloc(sizeof(GroupManager_t));
    if (!groupManager)
    {
        return NULL;
    }

    groupManager->m_ipManager = CreateIPManager();
    if (!groupManager->m_ipManager)
    {
        free(groupManager);
        return NULL;
    }

    groupManager->m_listOfGroups = ListCreate();
    if (!groupManager->m_listOfGroups)
    {
        DestroyIpManager(&groupManager->m_ipManager);
        free(groupManager);
        return NULL;
    }

    return groupManager;
}

void DestroyGroupManager(GroupManager_t **_groupManager)
{
    if (!_groupManager || !*_groupManager)
    {
        return;
    }

    DestroyIpManager(&((*_groupManager)->m_ipManager));

    ListDestory(&(*_groupManager)->m_listOfGroups, DestroyGroupFromList);

    free(*_groupManager);

    *_groupManager = NULL;
}

groupManagerError_t CreateNewGroup(GroupManager_t *_groupManager, byte *_groupName)
{
    GroupData_t *foundGroup = NULL;
    GroupData_t *newGroup = NULL;
    byte newGroupIP[MAX_LENGTH];

    if (!_groupManager || !_groupName)
    {
        return GROUP_MANAGER_IS_NOT_INITIALIZE;
    }

    foundGroup = SearchGroup(_groupManager, _groupName);
    if (!foundGroup)
    {
        if (SUCCESS != AddGroup(_groupManager, _groupName))
        {
            return GROUP_MANAGER_CREATE_GROUP_FAILED;
        }

        return GROUP_MANAGER_SUCCESS;
    }

    return GROUP_MANAGER_GROUP_IS_ALREADY_EXIST;
}

groupManagerError_t JoinGroup(GroupManager_t *_groupManager, byte *_groupName, byte *_groupIpAddress)
{
    GroupData_t *foundGroup = NULL;

    if (!_groupManager || !_groupName || !_groupIpAddress)
    {
        return GROUP_MANAGER_IS_NOT_INITIALIZE;
    }

    foundGroup = SearchGroup(_groupManager, _groupName);
    if (!foundGroup)
    {
        return GROUP_MANAGER_GROUP_NOT_FOUND;
    }

    strcpy((char*)_groupIpAddress, (char*)foundGroup->m_groupIP);

    return GROUP_MANAGER_SUCCESS;
}

groupManagerError_t IncreaseGroupCounter(GroupManager_t *_groupManager, byte *_groupName)
{
    GroupData_t *foundGroup = NULL;

    if (!_groupManager || !_groupName)
    {
        return GROUP_MANAGER_IS_NOT_INITIALIZE;
    }

    foundGroup = SearchGroup(_groupManager, _groupName);
    if (!foundGroup)
    {
        return GROUP_MANAGER_GROUP_NOT_FOUND;
    }

    ++foundGroup->m_numOfUsers;

    return GROUP_MANAGER_SUCCESS;
}

groupManagerError_t DecreaseGroupCounter(GroupManager_t *_groupManager, byte *_groupName)
{
    GroupData_t *foundGroup = NULL;

    if (!_groupManager || !_groupName)
    {
        return GROUP_MANAGER_IS_NOT_INITIALIZE;
    }

    foundGroup = SearchGroup(_groupManager, _groupName);
    if (!foundGroup)
    {
        return GROUP_MANAGER_GROUP_NOT_FOUND;
    }

    --foundGroup->m_numOfUsers;

    if (!foundGroup->m_numOfUsers)
    {
        DestroyGroup(_groupManager, &foundGroup);
    }

    return GROUP_MANAGER_SUCCESS;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static GroupData_t *SearchGroup(GroupManager_t *_groupManager, byte *_groupName)
{
    ListIter_t iterRunner = NULL;
    ListIter_t iterEnd = NULL;
    GroupData_t *currGroup = NULL;

    iterRunner = ListIterBegin(_groupManager->m_listOfGroups);
    iterEnd = ListIterEnd(_groupManager->m_listOfGroups);

    while (!ListIterEqual(iterRunner, iterEnd))
    {
        currGroup = (GroupData_t*)ListIterGet(iterRunner);

        if (!strcmp((char*)currGroup->m_groupName, (char*)_groupName))
        {
            return currGroup;
        }
    
        iterRunner = ListIterNext(iterRunner);
    }

    return NULL;
}

static Status_t AddGroup(GroupManager_t *_groupManager, byte *_groupName)
{
    GroupData_t *newGroup = NULL;
    byte newGroupIp[MAX_LENGTH];

    newGroup = (GroupData_t*)malloc(sizeof(GroupData_t));
    if (!newGroup)
    {
        return FAILURE;
    }

    if (SUCCESS != GetIpAddress(_groupManager->m_ipManager, newGroupIp))
    {
        return FAILURE;
    }

    strcpy((char*)newGroup->m_groupIP, (char*)newGroupIp);
    strcpy((char*)newGroup->m_groupName, (char*)_groupName);
    
    newGroup->m_groupPort = PORT;
    newGroup->m_numOfUsers = 0;

    if (DLIST_SUCCESS != ListPushTail(_groupManager->m_listOfGroups, newGroup))
    {
        free(newGroup);
        return FAILURE;
    }
        
    return SUCCESS;
}

static void DestroyGroup(GroupManager_t *_groupManager, GroupData_t **_group)
{  
    AddIpAddress(_groupManager->m_ipManager, (*_group)->m_groupIP);

    free(*_group);

    *_group = NULL;
} 

static void DestroyGroupFromList(void *_group)
{
    free(_group);
}