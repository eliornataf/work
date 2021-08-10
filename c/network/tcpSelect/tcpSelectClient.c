#include <arpa/inet.h> /* htons */
#include <stdio.h> /* printf */
#include <string.h> /* memset, strlen */
#include <sys/types.h> /*  connect, send, socket, recv */
#include <sys/socket.h> /* connect, send, socket, recv */
#include <unistd.h> /* close */

#include "tcpSelectClient.h" /* TCP Select Client Header */

#define SOCKET_ERROR (-1)
#define CONNECT_ERROR (-1)
#define RECV_ERROR (-1)
#define PORT (4465)

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static void CreateSocket(int *_socket);
static int ConnectToServer(struct sockaddr_in *_serverAddress, int _clientSocket);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

int InitClient(void)
{
    int clientSocket;
    struct sockaddr_in serverAddress;

    CreateSocket(&clientSocket);

    if (SOCKET_ERROR == clientSocket)
    {
        return TCP_CLIENT_INIT_FAILED;
    }

    if (FAILURE == ConnectToServer(&serverAddress, clientSocket))
    {
        close(clientSocket);
        return TCP_CLIENT_INIT_FAILED;
    }

    return clientSocket;
}

void DestroyClient(int _clientSocket)
{
    if (_clientSocket < 0)
    {
        return;
    }

    close(_clientSocket);
}

int SendMessageToServer(int _clientSocket)
{
    char *sendStr = "Ping!";
    size_t numOfSendBytes;

    if (_clientSocket < 0)
    {
        return FAILURE;
    }

    numOfSendBytes = send(_clientSocket, sendStr, strlen(sendStr), 0);
    if (numOfSendBytes != strlen(sendStr))
    {
        return FAILURE; 
    }

    return SUCCESS;
}

int ReceiveMessageFromServer(int _clientSocket, char *_buffer)
{
    size_t NumOfReadBytes;

    if (!_buffer || _clientSocket < 0)
    {
        return FAILURE;
    }

    NumOfReadBytes = recv(_clientSocket, _buffer, sizeof(_buffer), 0);

    if (RECV_ERROR == NumOfReadBytes)
    {
        return FAILURE;
    }

    _buffer[NumOfReadBytes] = '\0';

    printf("Receive message from server is: %s\n", _buffer); 

    return SUCCESS;
}

void SendClientIsDone(int _clientSocket)
{
    if (_clientSocket < 0)
    {
        return;
    }

    send(_clientSocket, NULL, 0, 0);
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static void CreateSocket(int *_socket)
{
    *_socket = socket(AF_INET, SOCK_STREAM, 0);
}

static int ConnectToServer(struct sockaddr_in *_serverAddress, int _clientSocket)
{
     memset(_serverAddress, 0, sizeof(*_serverAddress));

    _serverAddress->sin_family = AF_INET;
    _serverAddress->sin_addr.s_addr = inet_addr("127.0.0.1");
    _serverAddress->sin_port = htons(PORT);

    if (CONNECT_ERROR == connect(_clientSocket, (struct sockaddr*)_serverAddress, sizeof(*_serverAddress)))
    {
        return FAILURE;
    }

    return SUCCESS;
}