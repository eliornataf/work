/*****************************************************************************
* File Name: TCP Select Server - ADT
* Written by: Elior Nataf
* Date: 22/4/21
******************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __TCP_SELECT_SERVER_H__
#define __TCP_SELECT_SERVER_H__

/*------------------------------- Header Files ------------------------------*/

#include <sys/select.h> /* fd_set */

/*---------------------------------- Typedef --------------------------------*/

typedef struct TCPServer TCPServer_t;

/*----------------------------------- Define --------------------------------*/

/*------------------------------------ Enum  --------------------------------*/

typedef enum Status
{
    SUCCESS = 0,
    FAILURE = 1
} Status_t; 

typedef enum TCPServerError
{
    TCP_SERVER_SUCCESS = 0,
    TCP_SERVER_NOT_INITIALIZE,
    TCP_SERVER_ACCEPT_FAILED,
    TCP_SERVER_ADD_NEW_CLIENT_FAILED,
    TCP_SERVER_RECV_CONNECTION_CLOSED,
    TCP_SERVER_RECV_FAILED,
    TCP_SERVER_RECV_MESSAGE_RECEIVED
} TCPServerError_t;

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creating a new available tcp server. Memory will be specially 
 * allocated.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * None.
 *
 * Output:
 * NULL - allocation failed.
 * NULL - server client error.
 * NULL - create socket/setsockpot/bind/listen failed.
 * tcpServer - pointer to new created tcp server. 
 * 
 * Error: 
 * NULL - allocation failed.
 * NULL - server client error.
 * NULL - create socket/setsockpot/bind/listen failed.
 */
TCPServer_t *InitServer(void);

/* Description:
 * A function that destroys a specified tcp server.
 *
 * Time Complexity: O(n).
 *
 * Input:
 * tcpServer - pointer to tcp server.
 *
 * Output:
 * None.
 *
 * Error: 
 * the pointer is not initialized, destroy is not possible.
 */
void DestroyServer(TCPServer_t **tcpServer);

/* Description:
 * A function that checks new clients to tcp server. if new client was found
 * proper he will add to server list (for each client memory will be specially
 * allocated). 
 *
 * Time Complexity: O(1).
 *
 * Input:
 * tcpServer - pointer to tcp server.
 *
 * Output:
 * TCP_SERVER_NOT_INITIALIZE - tcpServer pointer is not initialized, check new client
 * is not possible.
 * TCP_SERVER_ACCEPT_FAILED - accpet function is failed.
 * TCP_SERVER_ADD_NEW_CLIENT_FAILED - add new client to server list failed.
 * TCP_SERVER_SUCCESS - a new client is succeeded added to list.
 *
 * Error: 
 * TCP_SERVER_NOT_INITIALIZE - tcpServer pointer is not initialized, check new client
 * is not possible.
 * TCP_SERVER_ACCEPT_FAILED - accpet function is failed.
 * TCP_SERVER_ADD_NEW_CLIENT_FAILED - add new client to server list failed.
 */
TCPServerError_t CheckNewClients(TCPServer_t *tcpServer);

/* Description:
 * A function that Iterate over all elements in the tcp server client list, 
 * and checks if server clients are available or not. if client is available 
 * he will send back message to server and if his connection is closed he will 
 * removed from list.
 * 
 * Time Complexity: O(n).
 *
 * Input:
 * tcpServer - pointer to tcp server to check current clients.
 * tempMonitorDescriptor - fd_set struct member, contain data about sockets 
 * who sended request to server. 
 * 
 * Output:
 * TCP_SERVER_NOT_INITIALIZE - tcpServer pointer is not initialized, check current
 * client is not possible.
 * TCP_SERVER_SUCCESS - tcp server client iterate over all elements in the 
 * tcp server client list.
 *
 * Error: 
 * TCP_SERVER_NOT_INITIALIZE - tcpServer pointer is not initialized, check current
 * client is not possible.
 */
TCPServerError_t CheckCurrClients(TCPServer_t *tcpServer, fd_set tempMonitorDescriptor);

/* Description:
 * A function that run specified tcp server.
 * 
 * Time Complexity: O(n).
 *
 * Input:
 * tcpServer - pointer to tcp server to run.
 *
 * Output:
 * FAILURE - tcpServer pointer is not initialized, run server is not possible.
 * FAILURE - select function is failed.
 * FAILURE - run server error.
 * SUCCESS - server run succeeded.
 * 
 * Error: 
 * FAILURE - tcpServer pointer is not initialized, run server is not possible.
 * FAILURE - select function is failed.
 * FAILURE - run server error.
 */
int RunServer(TCPServer_t *tcpServer);

#endif /* __TCP_SELECT_SERVER_H__ */
