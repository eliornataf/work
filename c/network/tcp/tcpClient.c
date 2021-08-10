#include <arpa/inet.h> /* htons */
#include <stdio.h> /* printf */
#include <string.h> /* memset, strlen */
#include <sys/types.h> /*  connect, send, socket, recv */
#include <sys/socket.h> /* connect, send, socket, recv */

#define SOCKET_ERROR (-1)
#define CONNECT_ERROR (-1)
#define RECV_ERROR (-1)
#define CONNECTION_IS_CLOSED (0)

enum Status
{
    SUCCESS = 0,
    FAILURE = 1
};

int main(void)
{
    int socketClient;
    struct sockaddr_in serverAddress;
    char *sendStr = "Hey, it's tcpClient!";
    size_t numOfSendBytes, NumOfReadBytes;
    char buffer[100];

    socketClient = socket(AF_INET, SOCK_STREAM, 0);

    if (SOCKET_ERROR == socketClient)
    {
        printf("Socket error\n");
        return FAILURE;
    }

    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(9978);

    if (CONNECT_ERROR == connect(socketClient, (struct sockaddr*)&serverAddress, sizeof(serverAddress)))
    {
        printf("Connect Error\n");
        return FAILURE;
    }

    numOfSendBytes = send(socketClient, sendStr, strlen(sendStr), 0);
    if (numOfSendBytes != strlen(sendStr))
    {
        printf("Send Error\n");
        return FAILURE; 
    }

    NumOfReadBytes = recv(socketClient, buffer, sizeof(buffer), 0);

    if (RECV_ERROR == NumOfReadBytes)
    {
        printf("Recv Error\n");
        return FAILURE;
    }
    else if (CONNECTION_IS_CLOSED == NumOfReadBytes)
    {
        close(socketClient);
        return SUCCESS;
    }

    buffer[NumOfReadBytes] = '\0';

    printf("Receive message from client is: %s\n", buffer); 

    close(socketClient);

    return SUCCESS;
}