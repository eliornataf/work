/*****************************************************************************
* File Name: TCP Generic Server - ADT
* Written by: Elior Nataf
* Date: 22/4/21
/*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __TCP_GENERIC_SERVER_H__
#define __TCP_GENERIC_SERVER_H__

/*------------------------------- Header Files ------------------------------*/

#include "utilites.h" /* Utilites Header */

/*----------------------------------- Define --------------------------------*/

/*----------------------------------- Struct  -------------------------------*/

typedef struct TCPClient
{
    int m_clientID;
    char *m_clientIPAddress;
    int m_clientPort;
} TCPClient_t;

/*------------------------------------ Enum  --------------------------------*/

typedef enum TCPServerError
{
    TCP_SERVER_SUCCESS = 0,
    TCP_SERVER_NOT_INITIALIZE,
    TCP_SERVER_MAX_CONNECT_CLIENTS,
    TCP_SERVER_ALLOCATION_FAILED,
    TCP_SERVER_CRITICAL_ERROR,
    TCP_SERVER_SEND_MESSAGE_FAILED
} TCPServerError_t;

/*---------------------------------- Typedef --------------------------------*/

typedef struct TCPServer TCPServer_t;

/* Description:
 * A function that notifies the application when a new client is
 * connected to the server. tcpClient is stack allocated variable, copy
 * his content.
 *
 * Time Complexity: O(1). 
 *
 * Input:
 * tcpServer - pointer to tcp server that notifies the application.
 * tcpClient - the new client info (client ID, client IP address and 
 * client port).
 * appContext - app context, specified by user demand.
 *
 * Output:
 * None.
 *
 * Error: 
 * None.
 */
typedef void (*NewClientFunc_t)(TCPServer_t *tcpServer, TCPClient_t *tcpClient, void *appContext); 

/* Description:
 * A function that notifies the application when a server client closed his 
 * connection with the server, or the server had to close the client connection with the server.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * tcpServer - pointer to tcp server that notifies the application.
 * clientID - the ID of the client that was closed.
 * appContext - app context, specified by user demand.
 * 
 * Output:
 * None.
 *
 * Error: 
 * None.
 */
typedef void (*CloseClientFunc_t)(TCPServer_t *tcpServer, int clientID, void *appContext); 

/* Description:
 * A function that notifies the application when the server has received 
 * a message from a client.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * tcpServer - pointer to tcp server that notifies the application.
 * clientID - the ID of the client that sent a message to the server.
 * message - the received message from the client.
 * appContext - app context, specified by user demand.
 * 
 * Output:
 * None.
 *
 * Error: 
 * None.
 */
typedef void (*ClientMessageFunc_t)(TCPServer_t *tcpServer, int clientID, void *message, void *appContext); 

/* Description:
 * A function that notifies the application when an error has 
 * occurred in the server.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * tcpServer - pointer to tcp server that notifies the application.
 * errorCode - the server error code.
 * appContext - app context, specified by user demand.
 *
 * Output:
 * return 1 to continue server run or zero to stop it.
 *
 * Error: 
 * None.
 */
typedef int (*ErrorFunc_t)(TCPServer_t *tcpServer, TCPServerError_t errorCode, void *appContext); 

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creates a new available tcp server according to 
 * several parameters that the application provided: serverIPAddress, serverPort,
 * queueLength, maxConnectClients, and 4 handling functions pointer.
 * Memory will be specially allocated. 
 *
 * Time Complexity: O(1).
 *
 * Input:
 * serverIPAddress - server IPV4 IP address.
 * serverPort - server using port. 
 * queueLength - server max clients queue size.
 * maxConnectClients - server max clients connections.
 * newClientFunc - pointer to the function that notifies the application
 * when a new client was connected to the server. pointer can be NULL. 
 * closeClientFunc - pointer to function that notifies the application
 * when a server client closed his connection to the server, or the
 * server had to close the connection with the client. pointer 
 * can be NULL. 
 * clientMessageFunc - pointer to the function that notifies the 
 * application when the server received a message from client. pointer 
 * cannot be NULL. 
 * errorFunc - pointer to the function that notifies the application
 * when an error has occurred in the server. pointer can be NULL. 
 * appContext - app context, specified by user demand.
 *
 * Output:
 * NULL - serverIPAddress pointer is NULL, create is not possible.
 * NULL - serverPort invalid input (_serverPort < MIN_PORT_NUM [1025] || 
 * MAX_PORT_NUM [65535] < _serverPort), create is not possible.
 * NULL - queueLength invalid input (!queueLength), create is not 
 * possible.
 * NULL - maxConnectClients invalid input (DESCRIPTORS_LIMIT [1020] < 
 * maxConnectClients), create is not possible.
 * NULL - clientMessageFunc pointer is NULL, create is not possible.
 * NULL - memory allocation failed.
 * NULL - create internal functions error.
 * tcpServer - pointer to the new created tcp server. 
 * 
 * Error: 
 * NULL - serverIPAddress pointer is NULL, create is not possible.
 * NULL - serverPort invalid input (_serverPort < MIN_PORT_NUM [1025] || 
 * MAX_PORT_NUM [65535] < _serverPort), create is not possible.
 * NULL - queueLength invalid input (!queueLength), create is not 
 * possible.
 * NULL - maxConnectClients invalid input (DESCRIPTORS_LIMIT [1020] < 
 * maxConnectClients), create is not possible.
 * NULL - clientMessageFunc pointer is NULL, create is not possible.
 * NULL - memory allocation failed.
 * NULL - create internal functions error.
 */
TCPServer_t *CreateServer(char *serverIPAddress, size_t serverPort, size_t queueLength, size_t maxConnectClients, NewClientFunc_t newClientFunc, CloseClientFunc_t closeClientFunc, ClientMessageFunc_t clientMessageFunc, ErrorFunc_t errorFunc, void *appContext);

/* Description:
 * A function that destroys a specified tcp server and sets him to null.
 * Previously allocated memory will be free. All remaining data will be
 * lost.
 *
 * Time Complexity: O(n).
 *
 * Input:
 * tcpServer - pointer to tcp server to be deallocated.
 *
 * Output:
 * None.
 *
 * Error: 
 * tcpServer pointer is not initialized, destroy is not possible.
 */
void DestroyServer(TCPServer_t **tcpServer);

/* Description:
 * A function that runs specified tcp server.
 * 
 * Time Complexity: O(1)...o(n).
 *
 * Input:
 * tcpServer - pointer to tcp server to run.
 *
 * Output:
 * None.
 * 
 * Error: 
 * tcpServer pointer is not initialized, run is not possible.
 */
void RunServer(TCPServer_t *tcpServer);

/* Description:
 * A function that sends a message from specified tcp server to the client.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * tcpServer - pointer to tcp server to send from.
 *
 * Output:
 * FAILURE - tcpServer pointer is not initialized, send is not possible.
 * FAILURE - clientID invalid input (clientID < 0), send is not possible.
 * FAILURE - message pointer is not initialized, send is not possible.
 * FAILURE - messageSize invalid input (!messageSize), send is not
 * possible.
 * FAILURE - send function error.
 * SUCCESS - the message has sended.
 * 
 * Error: 
 * FAILURE - tcpServer pointer is not initialized, send is not possible.
 * FAILURE - clientID invalid input (clientID < 0), send is not possible.
 * FAILURE - message pointer is not initialized, send is not possible.
 * FAILURE - messageSize invalid input (!messageSize), send is not
 * possible.
 * FAILURE - sends function error.
 */
int ServerSendMessage(TCPServer_t *tcpServer, int clientID, void *message, size_t messageSize);

#endif /* __TCP_GENERIC_SERVER_H__ */