#include <arpa/inet.h> /* htons */
#include <stdio.h> /* printf */
#include <string.h> /* memset, strlen */
#include <sys/types.h> /*  accept, bind, listen, send, setsockopt, socket, recv */
#include <sys/socket.h> /* accept, bind, listen, send, setsockopt, socket, recv */

#define SOCKET_ERROR (-1)
#define SETSOCKOPT_ERROR (-1)
#define BIND_ERROR (-1)
#define LISTEN_ERROR (-1)
#define ACCEPT_ERROR (-1)
#define ENABLE_OPTVAL (1)
#define RECV_ERROR (-1)
#define CONNECTION_IS_CLOSED (0)
#define QUEUE_SIZE (32)

enum Status
{
    SUCCESS = 0,
    FAILURE = 1
};

int main(void)
{
    int socketServer, acceptSocket;
    int optval = ENABLE_OPTVAL;
    struct sockaddr_in serverAddress;
    socklen_t serverAddressLength = sizeof(serverAddress);
    size_t NumOfReadBytes, numOfSendBytes;
    char *sendStr = "Hey, it's tcpServer!";
    char buffer[100];

    socketServer = socket(AF_INET, SOCK_STREAM, 0);

    if (SOCKET_ERROR == socketServer)
    {
        printf("Socket error\n");
        return FAILURE;
    }

    if (SETSOCKOPT_ERROR == setsockopt(socketServer, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)))
    {
        printf("Setsockopt error\n");
        return FAILURE;
    }

    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(9978);

    if (BIND_ERROR == bind(socketServer, (struct sockaddr*)&serverAddress, sizeof(serverAddress)))
    {
        printf("Bind Error\n");
        return FAILURE;
    }

    if (LISTEN_ERROR == listen(socketServer, QUEUE_SIZE))
    {
        printf("Listen Error\n");
        return FAILURE;
    }

    acceptSocket = accept(socketServer, (struct sockaddr*)&serverAddress, &serverAddressLength);

    if (ACCEPT_ERROR == acceptSocket)
    {
        printf("Accept Error\n");
        return FAILURE;
    }

    NumOfReadBytes = recv(acceptSocket, buffer, sizeof(buffer), 0);

    if (RECV_ERROR == NumOfReadBytes)
    {
        printf("Recv Error\n");
        return FAILURE;
    }
    else if (CONNECTION_IS_CLOSED == NumOfReadBytes)
    {
        close(socketServer);
        return SUCCESS;
    }

    buffer[NumOfReadBytes] = '\0';

    printf("Receive message from client is: %s\n", buffer); 

    numOfSendBytes = send(acceptSocket, sendStr, strlen(sendStr), 0);
    if (numOfSendBytes != strlen(sendStr))
    {
        printf("Send Error\n");
        return FAILURE; 
    }

    close(socketServer);
    
    return SUCCESS;   
}