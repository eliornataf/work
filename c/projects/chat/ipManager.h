/*****************************************************************************
* File Name: IP Manager - ADT
* Written by: Eli & Elior & Nuriel
* Date: 26/4/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __IP_MANAGER_H__
#define __IP_MANAGER_H__

/*------------------------------- Header Files ------------------------------*/

#include "utilites.h" /* Utilites Header */

/*---------------------------------- Typedef --------------------------------*/

typedef struct IPManager IPManager_t;

/*------------------------------- --- Define --------------------------------*/

/*------------------------------------ Enum ---------------------------------*/

/*----------------------------------- Struct --------------------------------*/

typedef enum IpManagerError
{
    IP_MANAGER_IS_NOT_INITIALIZE,
    IP_MANAGER_NOT_AVAILABLE_IP,
    IP_MANAGER_GET_IP_FAILED,
    IP_MANAGER_FULL_AVAILABLE_IP,
    IP_MANAGER_ALLOCATION_FAILED,
    IP_MANAGER_ADD_IP_FAILED,
    IP_MANAGER_SUCCESS
} IpManagerError_t;

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creates a new available IP manager. IP manager contains available
 * IPV4 Address from multicast. Memory will be specially allocated. 
 *
 * Time Complexity: O(1).
 *
 * Input:
 * None.
 *
 * Output:
 * NULL - memory allocation failed, create is not possible.
 * NULL - create ip manager error.
 * ipManager - pointer to new ip manager.  
 * 
 * Error: 
 * NULL - memory allocation failed, create is not possible.
 * NULL - create ip manager error.
 */
IPManager_t *CreateIPManager(void);

/* Description:
 * A function that destroys a specified ip manager and set him to null. 
 * Previously allocated memory will be free. All remaining data will be lost.
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
 * ipManager pointer is not initialized, destroy is not possible.
 */
void DestroyIpManager(IPManager_t **ipManager);

/* Description:
 * A function that returns IPV4 multicast address from available IPs.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * ipManager - pointer to ip manager to get IP from.
 * ipAddress - pointer to IP Address that will contains the get IP Address.
 *
 * Output:
 * IP_MANAGER_IS_NOT_INITIALIZE - ipManager/ipAddress pointer is not initialize, get 
 * is not possible.
 * IP_MANAGER_NOT_AVAILABLE_IP - no available IP, get is not possible.
 * IP_MANAGER_GET_IP_FAILED - get ip function error.
 * IP_MANAGER_SUCCESS - IP Address get succeeded.
 * 
 * Error: 
 * IP_MANAGER_IS_NOT_INITIALIZE - ipManager/ipAddress pointer is not initialize, get 
 * is not possible.
 * IP_MANAGER_NOT_AVAILABLE_IP - no available IP, get is not possible.
 * IP_MANAGER_GET_IP_FAILED - get ip function error.
 */
IpManagerError_t GetIpAddress(IPManager_t *ipManager, byte *ipAddress);

/* Description:
 * A function that adds IPV4 multicast address to available IPs.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * ipManager - pointer to ip manager to add IP to.
 * ipAddress - the IP address to add.
 *
 * Output:
 * IP_MANAGER_IS_NOT_INITIALIZE - ipManager/ipAddress pointer is not initialize, add is
 * not possible.
 * IP_MANAGER_FULL_AVAILABLE_IP - available IP is full, add is not possible.
 * IP_MANAGER_ALLOCATION_FAILED - memory allocation failed.
 * IP_MANAGER_ADD_IP_FAILED - add ip function error.
 * IP_MANAGER_SUCCESS - IP Address add succeeded.
 * 
 * Error: 
 * IP_MANAGER_IS_NOT_INITIALIZE - ipManager/ipAddress pointer is not initialize, add is
 * not possible.
 * IP_MANAGER_FULL_AVAILABLE_IP - available IP is full, add is not possible.
 * IP_MANAGER_ALLOCATION_FAILED - memory allocation failed.
 * IP_MANAGER_ADD_IP_FAILED - add ip function error.
 * IP_MANAGER_SUCCESS - IP Address add succeeded.
 */
IpManagerError_t AddIpAddress(IPManager_t *ipManager, byte *ipAddress);

#endif /* __IP_MANAGER_H__ */