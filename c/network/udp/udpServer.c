#include <arpa/inet.h> /* htons */
#include <stdio.h> /* printf */
#include <stdlib.h> /* exit */
#include <string.h> /* memset, strlen */
#include <sys/types.h> /* bind, sendto, socket, recvfrom */
#include <sys/socket.h> /* bind, sendto, socket, recvfrom */

#define SOCKET_ERROR (-1)
#define BIND_ERROR (-1)
#define RECVFROM_ERROR (-1)

enum Status
{
    SUCCESS = 0,
    FAILURE = 1
};

void SendMessage(int _socket, char *_str, size_t _strLength, struct sockaddr_in _struct)
{
    size_t numOfSendBytes;

    numOfSendBytes = sendto(_socket, _str, _strLength, 0, (struct sockaddr*)&_struct, sizeof(_struct));

    if (numOfSendBytes != _strLength)
    {
        printf("Number of send bytes error\n");
        exit(1);
    }   
}

void ReceiveMessage(int _socket, struct sockaddr_in _struct)
{
    socklen_t socklenLength = sizeof(_struct);
    size_t NumOfReadBytes;
    char buffer[100];

    NumOfReadBytes = recvfrom(_socket, buffer, sizeof(buffer), 0, (struct sockaddr*)&_struct, &socklenLength);

    if (RECVFROM_ERROR == NumOfReadBytes)
    {
        printf("Recvfrom Error\n");
        exit(1);
    }    

    buffer[NumOfReadBytes] = '\0';

    printf("Receive message from client is: %s\n", buffer); 

    sleep(2);
}

int main(void)
{
    int socketServer;
    struct sockaddr_in clientAddress, serverAddress;
    char *sendStr = "Hey, it's udpServer!";
    char *sendStr2 = "How are you?";
    char *sendStr3 = "Amazing, Thanks!";
    socklen_t clientAddressLength;
    size_t NumOfReadBytes;
    char buffer[100];

    socketServer = socket(AF_INET, SOCK_DGRAM, 0);

    if (SOCKET_ERROR == socketServer)
    {
        printf("Socket error\n");
        return FAILURE;
    }

    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8955);

    if (BIND_ERROR == bind(socketServer, (struct sockaddr*)&serverAddress, sizeof(serverAddress)))
    {
        printf("Bind Error\n");
        return FAILURE;
    }

    clientAddressLength = sizeof(clientAddress);

    NumOfReadBytes = recvfrom(socketServer, buffer, sizeof(buffer), 0, (struct sockaddr*)&clientAddress, &clientAddressLength);

    if (RECVFROM_ERROR == NumOfReadBytes)
    {
        printf("Recvfrom Error\n");
        return FAILURE;
    } 

    buffer[NumOfReadBytes] = '\0';

    printf("Receive message from client is: %s\n", buffer);

    sleep(2);

    SendMessage(socketServer, sendStr, strlen(sendStr), clientAddress);
    
    SendMessage(socketServer, sendStr2, strlen(sendStr2), clientAddress);

    ReceiveMessage(socketServer, clientAddress);

    SendMessage(socketServer, sendStr3, strlen(sendStr3), clientAddress);

    close(socket);

    return SUCCESS;
}