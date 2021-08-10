#include <arpa/inet.h> /* htons */
#include <errno.h> /* errno */
#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc, free */
#include <string.h> /* memset, strlen */
#include <sys/types.h> /*  accept, bind, listen, send, setsockopt, socket, recv */
#include <sys/select.h> /* fd_set, select, FD_ZERO, FD_SET, FD_ISSET */
#include <sys/socket.h> /* accept, bind, listen, send, setsockopt, socket, recv */
#include <unistd.h> /* close */

#include "tcpGenericServer.h" /* TCP Generic Server Header */
#include "genericDoublyLinkedList.h" /* Generic Doubly Linked List Header */
#include "listIter.h" /* List Iterator Header */

/************************************************/

#define SOCKET_ERROR (-1)
#define SETSOCKOPT_ERROR (-1)
#define BIND_ERROR (-1)
#define LISTEN_ERROR (-1)
#define ACCEPT_ERROR (-1)
#define ENABLE_OPTVAL (1)
#define RECV_ERROR (-1)
#define SELECT_ERROR (-1)
#define CONNECTION_IS_CLOSED (0)
#define MIN_PORT_NUM (1025)
#define MAX_PORT_NUM (65535)
#define DESCRIPTORS_LIMIT (1020)
#define IS_RUNNING (1)
#define MAX_DESCRIPTOR_NUM (1024)
#define CLIENT_ERROR (-1)
#define CLIENT_FINISH (0)
#define KEEP_CLIENT (1)
#define BUFFER_LENGTH (1024)

/************************************************/

struct TCPServer
{
    int m_serverSocket;
    struct sockaddr_in m_serverAddress;
    List_t *m_serverClients;
    fd_set m_masterMonitorDescriptor;
    size_t m_currConnectClients;
    size_t m_maxConnectClients;
    NewClientFunc_t m_newClientFunc;
    CloseClientFunc_t m_closeClientFunc;
    ClientMessageFunc_t m_clientMessageFunc;
    ErrorFunc_t m_errorFunc;
};

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static void CreateSocket(int *_socket);
static Status_t SetServerSocketOptval(int _serverSocket);
static Status_t BindAndListenServer(struct sockaddr_in *_serverAddress, int _serverSocket, char *_serverIPAddress, size_t _serverPort, size_t _queueLength);
static void SetMasterMonitorDescriptor(fd_set *_masterMonitorDescriptor, int _serverSocket);
static void ClientDestroy(void *_clientSocket);
static Status_t AddNewClient(TCPServer_t *_tcpServer, int _newClientSocket);
static TCPServerError_t CheckNewClients(TCPServer_t *_tcpServer);
static int ClientReceiveMessage(TCPServer_t *_tcpServer, int _clientSocket, void *_buffer, size_t *_numOfReadBytes);
static void CheckCurrClients(TCPServer_t *_tcpServer, fd_set _tempMonitorDescriptor, int _numOfSignalSockets);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

TCPServer_t *CreateServer(char *_serverIPAddress, size_t _serverPort, size_t _queueLength, size_t _maxConnectClients, NewClientFunc_t _newClientFunc, CloseClientFunc_t _closeClientFunc, ClientMessageFunc_t _clientMessageFunc, ErrorFunc_t _errorFunc)
{
    int serverSocket;
    struct sockaddr_in serverAddress;
    fd_set masterMonitorDescriptor;

    TCPServer_t *tcpServer = NULL;

    if (!_serverIPAddress || (_serverPort < MIN_PORT_NUM || MAX_PORT_NUM < _serverPort) || !_queueLength ||  DESCRIPTORS_LIMIT < _maxConnectClients || !_clientMessageFunc || !_errorFunc)
    {
        return NULL;
    }

    tcpServer = (TCPServer_t*)malloc(sizeof(TCPServer_t));
    if (!tcpServer)
    {
        return NULL;
    }

    tcpServer->m_serverClients = ListCreate();
    if (!tcpServer->m_serverClients)
    {
        free(tcpServer);
        return NULL;
    }

    CreateSocket(&serverSocket);
    if (SOCKET_ERROR == serverSocket)
    {
        ListDestory(&tcpServer->m_serverClients, ClientDestroy);
        free(tcpServer);
        return NULL;
    }

    tcpServer->m_serverSocket = serverSocket;

    if (FAILURE == SetServerSocketOptval(tcpServer->m_serverSocket))
    {
        DestroyServer(&tcpServer);
        return NULL;
    }

    if (FAILURE == BindAndListenServer(&serverAddress, tcpServer->m_serverSocket, _serverIPAddress, _serverPort, _queueLength))
    {
        DestroyServer(&tcpServer);
        return NULL;
    }

    tcpServer->m_serverAddress = serverAddress;

    SetMasterMonitorDescriptor(&masterMonitorDescriptor, tcpServer->m_serverSocket);

    tcpServer->m_masterMonitorDescriptor = masterMonitorDescriptor;

    tcpServer->m_currConnectClients = 0;
    tcpServer->m_maxConnectClients = _maxConnectClients;

    tcpServer->m_newClientFunc = _newClientFunc;
    tcpServer->m_closeClientFunc = _closeClientFunc;
    tcpServer->m_clientMessageFunc = _clientMessageFunc;
    tcpServer->m_errorFunc = _errorFunc;

    return tcpServer;
}

void DestroyServer(TCPServer_t **_tcpServer)
{
    if (!_tcpServer || !*_tcpServer)
    {
        return;
    }

    ListDestory(&(*_tcpServer)->m_serverClients, ClientDestroy);

    close((*_tcpServer)->m_serverSocket);

    free(*_tcpServer);

    *_tcpServer = NULL; 
}

void RunServer(TCPServer_t *_tcpServer)
{
    fd_set tempMonitorDescriptor;
    int numOfSignalSockets, statusCode;

    if (!_tcpServer)
    {
        return;
    }

    while (1)
    {
        tempMonitorDescriptor = _tcpServer->m_masterMonitorDescriptor;

        numOfSignalSockets = select(MAX_DESCRIPTOR_NUM, &tempMonitorDescriptor, NULL, NULL, NULL);

        if (SELECT_ERROR == numOfSignalSockets)
        {
            if (!_tcpServer->m_errorFunc(_tcpServer, TCP_SERVER_CRITICAL_ERROR))
            {
                break;
            }
        }

        if (FD_ISSET(_tcpServer->m_serverSocket, &tempMonitorDescriptor))
        {
            statusCode = CheckNewClients(_tcpServer);

            if (TCP_SERVER_SUCCESS != statusCode) 
            {
                if (!_tcpServer->m_errorFunc(_tcpServer, statusCode))
                {
                    break;
                }
            }

            --numOfSignalSockets;
        }
    
        if (numOfSignalSockets)
        {
            CheckCurrClients(_tcpServer, tempMonitorDescriptor, numOfSignalSockets);
        }
    }
}

int ServerSendMessage(TCPServer_t *_tcpServer, int _clientID, void *_message, size_t _messageSize)
{
    size_t numOfSendBytes;

    if (!_tcpServer || _clientID < 0 || !_message || !_messageSize)
    {
        return FAILURE;
    }

    numOfSendBytes = send(_clientID, _message, _messageSize, 0);
    if (numOfSendBytes != _messageSize)
    {
        _tcpServer->m_errorFunc(_tcpServer, TCP_SERVER_SEND_MESSAGE_FAILED);

        return FAILURE;
    }

    return SUCCESS;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static void CreateSocket(int *_socket)
{
    *_socket = socket(AF_INET, SOCK_STREAM, 0);
}

static Status_t SetServerSocketOptval(int _serverSocket)
{
    int optval = ENABLE_OPTVAL;

    if (SETSOCKOPT_ERROR == setsockopt(_serverSocket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)))
    {
        return FAILURE;
    }

    return SUCCESS;
}

static Status_t BindAndListenServer(struct sockaddr_in *_serverAddress, int _serverSocket, char *_serverIPAddress, size_t _serverPort, size_t _queueLength)
{
    memset(_serverAddress, 0, sizeof(*_serverAddress));

    _serverAddress->sin_family = AF_INET;
    _serverAddress->sin_addr.s_addr = inet_addr(_serverIPAddress);
    _serverAddress->sin_port = htons(_serverPort);

    if (BIND_ERROR == bind(_serverSocket, (struct sockaddr*)_serverAddress, sizeof(*_serverAddress)))
    {
        return FAILURE;
    }

    if (LISTEN_ERROR == listen(_serverSocket, _queueLength))
    {
        return FAILURE;
    }

    return SUCCESS;
}

static void SetMasterMonitorDescriptor(fd_set *_masterMonitorDescriptor, int _serverSocket)
{
    FD_ZERO(_masterMonitorDescriptor);
    FD_SET(_serverSocket, _masterMonitorDescriptor);
}

static void ClientDestroy(void *_clientSocket)
{
    close(*(int*)_clientSocket);
    free(_clientSocket);
}

static Status_t AddNewClient(TCPServer_t *_tcpServer, int _newClientSocket)
{
    int *newClient = NULL;

    if (_tcpServer->m_currConnectClients == _tcpServer->m_maxConnectClients)
    {
        close(_newClientSocket);
        return TCP_SERVER_MAX_CONNECT_CLIENTS;
    }

    newClient = (int*)malloc(sizeof(int));
    if (!newClient)
    {
        close(_newClientSocket);
        return TCP_SERVER_ALLOCATION_FAILED;
    }

    *newClient = _newClientSocket;

    if (DLIST_SUCCESS != ListPushTail(_tcpServer->m_serverClients, newClient))
    {
        ClientDestroy(newClient);
        return TCP_SERVER_ALLOCATION_FAILED;
    }

    return TCP_SERVER_SUCCESS;
}

static TCPServerError_t CheckNewClients(TCPServer_t *_tcpServer)
{
    int newClientSocket, statusCode;
    TCPClient_t tcpClient;
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLength = sizeof(clientAddress);

    newClientSocket = accept(_tcpServer->m_serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLength);

    if (ACCEPT_ERROR == newClientSocket)
    {
        return TCP_SERVER_CRITICAL_ERROR;
    }
    else if (0 < newClientSocket)
    {
        statusCode = AddNewClient(_tcpServer, newClientSocket);
        if (TCP_SERVER_SUCCESS != statusCode)
        {
            return statusCode;
        }
    }

    FD_SET(newClientSocket, &_tcpServer->m_masterMonitorDescriptor);

    ++_tcpServer->m_currConnectClients;

    if (_tcpServer->m_newClientFunc)
    {
        tcpClient.m_clientID = newClientSocket;
        tcpClient.m_clientIPAddress = inet_ntoa(clientAddress.sin_addr);
        tcpClient.m_clientPort = ntohs(clientAddress.sin_port);

        _tcpServer->m_newClientFunc(_tcpServer, &tcpClient);
    }

    return TCP_SERVER_SUCCESS;
}

static int ClientReceiveMessage(TCPServer_t *_tcpServer, int _clientSocket, void *_buffer, size_t *_numOfReadBytes)
{
    *_numOfReadBytes = recv(_clientSocket, _buffer, sizeof(_buffer), 0);

    (void)_tcpServer;

    if ((size_t)RECV_ERROR == *_numOfReadBytes)
    {
        return CLIENT_ERROR;
    }
    else if (CONNECTION_IS_CLOSED == *_numOfReadBytes)
    {
        return CLIENT_FINISH;
    }

    return KEEP_CLIENT;
}

static void CheckCurrClients(TCPServer_t *_tcpServer, fd_set _tempMonitorDescriptor, int _numOfSignalSockets)
{
    ListIter_t iterRunner, iterEnd, iterRemove;
    char buffer[BUFFER_LENGTH];
    size_t numOfReadBytes;
    void *currClient = NULL;
    TCPServerError_t recvStatus;

    iterRunner = ListIterBegin(_tcpServer->m_serverClients);
    iterEnd = ListIterEnd(_tcpServer->m_serverClients);

    while (!ListIterEqual(iterRunner, iterEnd))
    {
        currClient = ListIterGet(iterRunner);

        if (FD_ISSET(*(int*)currClient, &_tempMonitorDescriptor))
        {
            recvStatus = ClientReceiveMessage(_tcpServer, *(int*)currClient, buffer, &numOfReadBytes);

            if ( (CLIENT_ERROR == (int)recvStatus) || (CLIENT_FINISH == recvStatus) )
            {
                iterRemove = iterRunner;
                iterRunner = ListIterNext(iterRunner);
                ListIterRemove(iterRemove);
                
                if (_tcpServer->m_closeClientFunc)
                {
                    _tcpServer->m_closeClientFunc(_tcpServer, *(int*)currClient);
                }

                FD_CLR(*(int*)currClient, &_tcpServer->m_masterMonitorDescriptor);
                ClientDestroy(currClient);
            }
            else
            {
                _tcpServer->m_clientMessageFunc(_tcpServer, *(int*)currClient, buffer, numOfReadBytes);

                if (!(--_numOfSignalSockets))
                {
                    break;
                }
            }
        }

        iterRunner = ListIterNext(iterRunner);
    }
}