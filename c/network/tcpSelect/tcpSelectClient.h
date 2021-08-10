/*****************************************************************************
* File Name: TCP Select Client - ADT
* Written by: Elior Nataf
* Date: 22/4/21
******************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __TCP_SELECT_CLIENT_H__
#define __TCP_SELECT_CLIENT_H__

/*------------------------------- Header Files ------------------------------*/

/*---------------------------------- Typedef --------------------------------*/

/*----------------------------------- Define --------------------------------*/

#define TCP_CLIENT_INIT_FAILED (-1)

/*------------------------------------ Enum  --------------------------------*/

typedef enum Status
{
    SUCCESS = 0,
    FAILURE = 1
} Status_t; 

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creating a new available tcp client, creates new available socket
 * and connect him to server.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * None.
 *
 * Output:
 * TCP_CLIENT_INIT_FAILED - new socket/connect to server error.
 * clientSocket - a new created connected tcp client socket. 
 * 
 * Error: 
 * TCP_CLIENT_INIT_FAILED - new socket/connect to server error.
 */
int InitClient(void);

/* Description:
 * A function that destroys a specified tcp client socket.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * clientSocket - client socket to destroy.
 *
 * Output:
 * None.
 *
 * Error: 
 * client socket is invalid input (clientSocket < 0), destroy is not possible.
 */
void DestroyClient(int clientSocket);

/* Description:
 * A function that sends message from tcp client to tcp server.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * clientSocket - tcp client socket to send from.
 *
 * Output:
 * FAILURE - client socket invalid input (clientSocket < 0), send is not possible.
 * FAILURE - send function error.
 * SUCCESS - the message send succeeded.
 *
 * Error: 
 * FAILURE - client socket invalid input (clientSocket < 0), send is not possible.
 * FAILURE - send function error.
 */
int SendMessageToServer(int clientSocket);

/* Description:
 * A function that receive message from tcp server to tcp client.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * clientSocket - tcp client socket to receive to.
 *
 * Output:
 * FAILURE - buffer pointer is not initialize, receive is not possible.
 * FAILURE - client socket invalid input (clientSocket < 0), receive is not possible.
 * FAILURE - recv function is failed.
 * SUCCESS - the message receive succeeded.
 *
 * Error: 
 * FAILURE - buffer pointer is not initialize, receive is not possible.
 * FAILURE - client socket invalid input (clientSocket < 0), receive is not possible.
 * FAILURE - recv function is failed.
 */
int ReceiveMessageFromServer(int _clientSocket, char *_buffer);

/* Description:
 * A function that sends to tcp server that tcp client is done.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * clientSocket - tcp client socket to send with.
 *
 * Output:
 * None.
 * 
 * Error: 
 * client socket is invalid input (clientSocket < 0), send client is done is 
 * not possible.
 */
void SendClientIsDone(int clientSocket);

#endif /* __TCP_SELECT_CLIENT_H__ */
