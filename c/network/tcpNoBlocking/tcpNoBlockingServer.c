#include <arpa/inet.h> /* htons */
#include <errno.h> /* errno */
#include <fcntl.h> /* fcntl */
#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc, free */
#include <string.h> /* memset, strlen */
#include <sys/types.h> /*  accept, bind, listen, send, setsockopt, socket, recv */
#include <sys/socket.h> /* accept, bind, listen, send, setsockopt, socket, recv */
#include <unistd.h> /* close, fcntl */

#include "tcpNoBlockingServer.h" /* TCP No Blocking Server Header */
#include "genericDoublyLinkedList.h" /* Generic Doubly Linked List Header */
#include "listIter.h" /* List Iterator Header */

#define SOCKET_ERROR (-1)
#define SETSOCKOPT_ERROR (-1)
#define BIND_ERROR (-1)
#define LISTEN_ERROR (-1)
#define FCNTL_ERROR (-1)
#define ACCEPT_ERROR (-1)
#define ENABLE_OPTVAL (1)
#define RECV_ERROR (-1)
#define CONNECTION_IS_CLOSED (0)
#define QUEUE_SIZE (1020)
#define BUFFER_LENGTH (1024)
#define PORT (1854)

/************************************************/

struct TCPServer
{
    int m_serverSocket;
    struct sockaddr_in m_serverAddress;
    List_t *m_serverClients;
};

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static void CreateSocket(int *_socket);
static int SetServerSocketOptval(int _serverSocket);
static int BindAndListenServer(struct sockaddr_in *_serverAddress, int _serverSocket);
static int ChangeSocketToNoBlockingMode(int _serverSocket);
static void ClientDestroy(void *_clientSocket);
static int AddNewClient(TCPServer_t *_tcpServer, int _newClientSocket);
static TCPServerError_t ClientReceiveMessage(TCPServer_t *_tcpServer, int _clientSocket);
static int ClientSendMessage(TCPServer_t *_tcpServer, int _clientSocket);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

TCPServer_t *InitServer(void)
{
    int serverSocket;
    struct sockaddr_in serverAddress;

    TCPServer_t *tcpServer = (TCPServer_t*)malloc(sizeof(TCPServer_t));
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

    if (FAILURE == BindAndListenServer(&serverAddress, tcpServer->m_serverSocket))
    {
        DestroyServer(&tcpServer);
        return NULL;
    }

    tcpServer->m_serverAddress = serverAddress;

    if (FAILURE == ChangeSocketToNoBlockingMode(tcpServer->m_serverSocket))
    {
        DestroyServer(&tcpServer);
        return NULL;
    }

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

TCPServerError_t CheckNewClients(TCPServer_t *_tcpServer)
{
    int newClientSocket;
    socklen_t serverAddressLength = sizeof(_tcpServer->m_serverAddress);

    if (!_tcpServer)
    {
        return TCP_SERVER_NOT_INITIALIZE;
    }

    newClientSocket = accept(_tcpServer->m_serverSocket, (struct sockaddr*)&_tcpServer->m_serverAddress, &serverAddressLength);

    if ( (ACCEPT_ERROR == newClientSocket) && (EAGAIN != errno) && (EWOULDBLOCK != errno) )
    {
        return TCP_SERVER_ACCEPT_FAILED;
    }
    else if (0 < newClientSocket)
    {
        if (SUCCESS != AddNewClient(_tcpServer, newClientSocket))
        {
            return TCP_SERVER_ADD_NEW_CLIENT_FAILED;
        }
    }

    return TCP_SERVER_SUCCESS;
}

TCPServerError_t CheckCurrClients(TCPServer_t *_tcpServer)
{
    ListIter_t iterRunner, iterEnd, iterRemove;
    void *currClient = NULL;
    TCPServerError_t recvStatus;

    if (!_tcpServer)
    {
        return TCP_SERVER_NOT_INITIALIZE;
    }

    iterRunner = ListIterBegin(_tcpServer->m_serverClients);
    iterEnd = ListIterEnd(_tcpServer->m_serverClients);

    while (!ListIterEqual(iterRunner, iterEnd))
    {
        currClient = ListIterGet(iterRunner);

        recvStatus = ClientReceiveMessage(_tcpServer, *(int*)currClient);

        if ( (TCP_SERVER_RECV_CONNECTION_CLOSED == recvStatus) || 
        (TCP_SERVER_RECV_FAILED == recvStatus) || 
        (recvStatus == TCP_SERVER_RECV_MESSAGE_RECEIVED && FAILURE == ClientSendMessage(_tcpServer, *(int*)currClient)) )
        {
            iterRemove = iterRunner;
            iterRunner = ListIterNext(iterRunner);
            ListIterRemove(iterRemove);
            ClientDestroy(currClient);
        }

        iterRunner = ListIterNext(iterRunner);
    }
    
    return TCP_SERVER_SUCCESS;
}

int RunServer(TCPServer_t *_tcpServer)
{
    if (!_tcpServer)
    {
        return FAILURE;
    }

    while (1)
    {
        if (TCP_SERVER_SUCCESS != CheckNewClients(_tcpServer))
        {
            return FAILURE;
        }
    
        if (TCP_SERVER_SUCCESS != CheckCurrClients(_tcpServer))
        {
            return FAILURE;
        }
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

static int SetServerSocketOptval(int _serverSocket)
{
    int optval = ENABLE_OPTVAL;

    if (SETSOCKOPT_ERROR == setsockopt(_serverSocket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)))
    {
        return FAILURE;
    }

    return SUCCESS;
}

static int BindAndListenServer(struct sockaddr_in *_serverAddress, int _serverSocket)
{
    memset(_serverAddress, 0, sizeof(*_serverAddress));

    _serverAddress->sin_family = AF_INET;
    _serverAddress->sin_addr.s_addr = INADDR_ANY;
    _serverAddress->sin_port = htons(PORT);

    if (BIND_ERROR == bind(_serverSocket, (struct sockaddr*)_serverAddress, sizeof(*_serverAddress)))
    {
        return FAILURE;
    }

    if (LISTEN_ERROR == listen(_serverSocket, QUEUE_SIZE))
    {
        return FAILURE;
    }

    return SUCCESS;
}

static int ChangeSocketToNoBlockingMode(int _serverSocket)
{
    int serverSocketStatus = fcntl(_serverSocket, F_GETFL);
    if (FCNTL_ERROR == serverSocketStatus)
    {
        return FAILURE;
    }

    if (FCNTL_ERROR == fcntl(_serverSocket, F_SETFL, serverSocketStatus | O_NONBLOCK))
    {
        return FAILURE;
    }

    return SUCCESS;
}

static void ClientDestroy(void *_clientSocket)
{
    close(*(int*)_clientSocket);
    free(_clientSocket);
}

static int AddNewClient(TCPServer_t *_tcpServer, int _newClientSocket)
{
    int *newClient = NULL;
    
    (void)_tcpServer;

    if (FAILURE == ChangeSocketToNoBlockingMode(_newClientSocket))
    {
        return FAILURE;
    }

    newClient = (int*)malloc(sizeof(int));
    if (!newClient)
    {
        return FAILURE;
    }

    *newClient = _newClientSocket;

    if (DLIST_SUCCESS != ListPushTail(_tcpServer->m_serverClients, newClient))
    {
        ClientDestroy(newClient);
        return FAILURE;
    }

    return SUCCESS;
}

static TCPServerError_t ClientReceiveMessage(TCPServer_t *_tcpServer, int _clientSocket)
{
    char buffer[BUFFER_LENGTH];

    size_t NumOfReadBytes = recv(_clientSocket, buffer, sizeof(buffer), 0);

    (void)_tcpServer;

    if (CONNECTION_IS_CLOSED == NumOfReadBytes)
    {
        return TCP_SERVER_RECV_CONNECTION_CLOSED;
    }
    else if ((size_t)RECV_ERROR == NumOfReadBytes)
    {
        if ( (EAGAIN != errno) && (EWOULDBLOCK != errno) )
        {
            return TCP_SERVER_RECV_FAILED;
        }

        return TCP_SERVER_RECV_NO_MESSAGE_AVAILABLE;
    }

    buffer[NumOfReadBytes] = '\0';

    printf("Receive message from client is: %s\n", buffer); 

    return TCP_SERVER_RECV_MESSAGE_RECEIVED;
}

static int ClientSendMessage(TCPServer_t *_tcpServer, int _clientSocket)
{
    char *sendStr = "Pong!";
    size_t numOfSendBytes = send(_clientSocket, sendStr, strlen(sendStr), 0);

    (void)_tcpServer;

    if (numOfSendBytes != strlen(sendStr))
    {
        return FAILURE; 
    }

    return SUCCESS;
}