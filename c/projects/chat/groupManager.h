/*****************************************************************************
* File Name: GroupManager - ADT
* Written by: Eli & Elior & Nuriel
* Date: 26/4/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __GROUP_MANAGER_H__
#define __GROUP_MANAGER_H__

/*------------------------------- Header Files ------------------------------*/

#include "utilites.h" /* Utilites Header */

/*----------------------------------- Struct --------------------------------*/

/*---------------------------------- Typedef --------------------------------*/

typedef struct GroupManager GroupManager_t;

/*------------------------------------ Enum ---------------------------------*/

typedef enum groupManagerError
{
    GROUP_MANAGER_IS_NOT_INITIALIZE = 0,
    GROUP_MANAGER_CREATE_GROUP_FAILED,
    GROUP_MANAGER_GROUP_IS_ALREADY_EXIST,
    GROUP_MANAGER_GROUP_NOT_FOUND,
    GROUP_MANAGER_SUCCESS
} groupManagerError_t; 

/*------------------------------- --- Define --------------------------------*/

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creates a new available group manager. The group manager
 * contains list of groups and avaliable IPV4 IPs addresses for group use.
 * Memory will be specially allocated. 
 *
 * Time Complexity: O(1).
 *
 * Input:
 * None.
 *
 * Output:
 * NULL - memory allocation failed.
 * NULL - create group manager error.
 * groupManager - pointer to new created group manager.  
 * 
 * Error: 
 * NULL - memory allocation failed.
 * NULL - create group manager error.
 */
GroupManager_t *CreateGroupManager(void);

/* Description:
 * A function that destroys a specified group manager. Previously allocated 
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
 * groupManager pointer is not initialized, destroy is not possible.
 */
void DestroyGroupManager(GroupManager_t **groupManager);

/* Description:
 * A function that creates a new available group. If groupName is already 
 * exist in group list, create is not possible (groupName is unique). Memory 
 * will be specially allocated. 
 *
 * Time Complexity: O(n).
 *
 * Input:
 * groupManager - pointer to group manager.
 * groupName - pointer to group name to create group with.
 *
 * Output:
 * GROUP_MANAGER_IS_NOT_INITIALIZE - groupManager/groupName pointer is not initialize, 
 * create is not possible.
 * GROUP_MANAGER_GROUP_IS_ALREADY_EXIST - the groupName is already exists, create is not
 * possible.
 * GROUP_MANAGER_CREATE_GROUP_FAILED - create group manager error.
 * GROUP_MANAGER_SUCCESS - IP Address create succeeded.
 * 
 * Error: 
 * GROUP_MANAGER_IS_NOT_INITIALIZE - groupManager/groupName pointer is not initialize, 
 * create is not possible.
 * GROUP_MANAGER_GROUP_IS_ALREADY_EXIST - the groupName is already exists, create is not
 * possible.
 * GROUP_MANAGER_CREATE_GROUP_FAILED - create group manager error.
 */
groupManagerError_t CreateNewGroup(GroupManager_t *groupManager, byte *groupName);

/* Description:
 * A function that joins user to specified group. 
 *
 * Time Complexity: O(n).
 *
 * Input:
 * groupManager - pointer to group manager.
 * groupName - pointer to group name to join user.
 * groupIpAddress - the group IP address, if found.
 *
 * Output:
 * GROUP_MANAGER_IS_NOT_INITIALIZE - groupManager/groupName/groupIpAddress pointer is not
 * initialize, join is not possible.
 * GROUP_MANAGER_GROUP_NOT_FOUND - the group is not found (groupName is not exists), join
 * is not possible.
 * GROUP_MANAGER_SUCCESS - join group is succeeded.
 * 
 * Error: 
 * GROUP_MANAGER_IS_NOT_INITIALIZE - groupManager/groupName/groupIpAddress pointer is not
 * initialize, join is not possible.
 * GROUP_MANAGER_GROUP_NOT_FOUND - the group is not found (groupName is not exists), join
 * is not possible.
 */
groupManagerError_t JoinGroup(GroupManager_t *groupManager, byte *groupName, byte *groupIpAddress);

/* Description:
 * A function that increases group number of users.
 *
 * Time Complexity: O(n).
 *
 * Input:
 * groupManager - pointer to group manager.
 * groupName - pointer to group manager to increase group number of users.
 *
 * Output:
 * GROUP_MANAGER_IS_NOT_INITIALIZE - groupManager/groupName pointer is not initialize,
 * increase is not possible.
 * GROUP_MANAGER_GROUP_NOT_FOUND - the group is not found (groupName is not exists),
 * incrase is not possible.
 * GROUP_MANAGER_SUCCESS - increase group number of users is succeeded.
 * 
 * Error: 
 * GROUP_MANAGER_IS_NOT_INITIALIZE - groupManager/groupName pointer is not initialize,
 * increase is not possible.
 * GROUP_MANAGER_GROUP_NOT_FOUND - the group is not found (groupName is not exists),
 * incrase is not possible.
 */
groupManagerError_t IncreaseGroupCounter(GroupManager_t *groupManager, byte *groupName);

/* Description:
 * A function that decreases group number of users. In case after decrease number of
 * users in group is zero, the function will destroyed the group.
 *
 * Time Complexity: O(n).
 *
 * Input:
 * groupManager - pointer to group manager.
 * groupName - pointer to group manager to decreases group number of users.
 *
 * Output:
 * GROUP_MANAGER_IS_NOT_INITIALIZE - groupManager/groupName pointer is not initialize,
 * decrease is not possible.
 * GROUP_MANAGER_GROUP_NOT_FOUND - the group is not found (groupName is not exists),
 * decrease is not possible.
 * GROUP_MANAGER_SUCCESS - decrease group number of users is succeeded.
 * 
 * Error: 
 * GROUP_MANAGER_IS_NOT_INITIALIZE - groupManager/groupName pointer is not initialize,
 * decrease is not possible.
 * GROUP_MANAGER_GROUP_NOT_FOUND - the group is not found (groupName is not exists),
 * decrease is not possible.
 */
groupManagerError_t DecreaseGroupCounter(GroupManager_t *groupManager, byte *groupName);

#endif /* __GROUP_MANAGER_H__ */
