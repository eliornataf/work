#include <arpa/inet.h>  /* htons */
#include <string.h>     /* memset, strlen */
#include <sys/types.h>  /*  connect, send, socket, recv */
#include <sys/socket.h> /* connect, send, socket, recv */
#include <unistd.h>     /* close */

#include "tcpClient.h" /* TCP Client Header */

#define MIN_PORT_NUM (1025)
#define MAX_PORT_NUM (65535)

#define SOCKET_ERROR (-1)
#define CONNECT_ERROR (-1)
#define RECV_ERROR (-1)

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static void CreateSocket(int *socket);
static int ConnectToServer(struct sockaddr_in *serverAddress, int clientSocket, char *serverIp, int serverPort);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

int ClientInit(char *_serverIp, int _serverPort)
{
    int clientSocket;
    struct sockaddr_in serverAddress;

    if(!_serverIp || (_serverPort < MIN_PORT_NUM || MAX_PORT_NUM < _serverPort))
    {
        return ERROR;
    }

    CreateSocket(&clientSocket);

    if (SOCKET_ERROR == clientSocket)
    {
        return ERROR;
    }

    if (FAILURE == ConnectToServer(&serverAddress, clientSocket, _serverIp, _serverPort))
    {
        close(clientSocket);
        return ERROR;
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

int SendMessageToServer(int _clientSocket, unsigned char *_message, size_t _messageLength)
{
    size_t numOfSendBytes;

    if (_clientSocket < 0 || !_message || _messageLength < 1)
    {
        return ERROR;
    }

    numOfSendBytes = send(_clientSocket, _message, _messageLength, 0);
    if (numOfSendBytes != _messageLength)
    {
        return ERROR; 
    }

    return numOfSendBytes;
}

int ReceiveMessageFromServer(int _clientSocket, unsigned char *_buffer, size_t _expectedLength)
{
    size_t NumOfReadBytes;

    if (_clientSocket < 0 || !_buffer || _expectedLength < 1)
    {
        return ERROR;
    }

    NumOfReadBytes = recv(_clientSocket, _buffer, _expectedLength, 0);

    if (RECV_ERROR == NumOfReadBytes)
    {
        return ERROR;
    }

    return NumOfReadBytes;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static void CreateSocket(int *_socket)
{
    *_socket = socket(AF_INET, SOCK_STREAM, 0);
}

static int ConnectToServer(struct sockaddr_in *_serverAddress, int _clientSocket, char *_serverIp, int _serverPort)
{
     memset(_serverAddress, 0, sizeof(*_serverAddress));

    _serverAddress->sin_family = AF_INET;
    _serverAddress->sin_addr.s_addr = inet_addr(_serverIp);
    _serverAddress->sin_port = htons(_serverPort);

    if (CONNECT_ERROR == connect(_clientSocket, (struct sockaddr*)_serverAddress, sizeof(*_serverAddress)))
    {
        return FAILURE;
    }

    return SUCCESS;
}

/******************************************************/