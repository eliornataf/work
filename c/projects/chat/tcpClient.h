/*****************************************************************************
* File Name: TCP Client - ADT
* Written by: Eli & Elior & Nuriel
* Date: 26/4/21
/*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __TCP_CLIENT_H__
#define __TCP_CLIENT_H__

/*------------------------------- Header Files ------------------------------*/

#include "utilites.h" /* Utilites Header */

/*---------------------------------- Typedef --------------------------------*/

/*----------------------------------- Define --------------------------------*/

#define ERROR (-1)

/*------------------------------------ Enum  --------------------------------*/

/*-------------------------- Functions declarations -------------------------*/

/* Description:
 * A function that creating a new available tcp client, creates new
 * available socket and connect him to server.
 *
 * Time Complexity: O(1).
 *
 * Input:
 * serverIp - the IPV4 IP address.
 * serverPort - the server port.
 *
 * Output:
 * ERROR - serverIp is not initialize, init is not possible.
 * ERROR - serverPort invalid input (serverPort < MIN_PORT_NUM [1025] 
 * || MAX_PORT_NUM [65535] < serverPort), init is not possible.
 * ERROR - init function error.
 * clientSocket - the client socket.
 * 
 * Error: 
 * ERROR - serverIp is not initialize, init is not possible.
 * ERROR - serverPort invalid input (serverPort < MIN_PORT_NUM [1025] 
 * || MAX_PORT_NUM [65535] < serverPort), init is not possible.
 * ERROR - init error.
 */
int ClientInit(char *serverIp, int serverPort);

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
 * message - the message to send.
 * messageLength - the message length.
 *
 * Output:
 * ERROR - client socket invalid input (clientSocket < 0), send is not possible.
 * ERROR - message is not initialize, send is not possible.
 * ERROR - messageLength invalid input (messageLength < 1), send is not possible.
 * ERROR - send function error.
 * numOfSendBytes - the number of send bytes.
 *
 * Error: 
 * ERROR - client socket invalid input (clientSocket < 0), send is not possible.
 * ERROR - message is not initialize, send is not possible.
 * ERROR - messageLength invalid input (messageLength < 1), send is not possible.
 * ERROR - send function error.
 */
int SendMessageToServer(int clientSocket, unsigned char *message, size_t messageLength);

/* Description:
 * A function that receive message from tcp server to tcp client.
 * 
 * Time Complexity: O(1).
 *
 * Input:
 * clientSocket - tcp client socket to receive to.
 * buffer - buffer to get message to.
 * expectedLength - message expected length.
 *
 * Output:
 * ERROR - client socket invalid input (clientSocket < 0), receive is not possible.
 * ERROR - buffer is not initialize, receive is not possible.
 * ERROR - expectedLength invalid input (expectedLength < 1), receive is not possible.
 * ERROR - receive function error.
 * NumOfReadBytes - number of read bytes.
 *
 * Error: 
 * ERROR - client socket invalid input (clientSocket < 0), receive is not possible.
 * ERROR - buffer is not initialize, receive is not possible.
 * ERROR - expectedLength invalid input (expectedLength < 1), receive is not possible.
 * ERROR - receive function error.
 */
int ReceiveMessageFromServer(int clientSocket, unsigned char *buffer, size_t expectedLength);

#endif /* __TCP_CLIENT_H__ */