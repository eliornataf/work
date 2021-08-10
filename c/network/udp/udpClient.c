#include <arpa/inet.h> /* htons */
#include <stdio.h> /* printf */
#include <stdlib.h> /* exit */
#include <string.h> /* memset, strlen */
#include <sys/types.h> /* sendto, socket, recvfrom */
#include <sys/socket.h> /* sendto, socket, recvfrom */

#define SOCKET_ERROR (-1)
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
;
    NumOfReadBytes = recvfrom(_socket, buffer, sizeof(buffer), 0, (struct sockaddr*)&_struct, &socklenLength);

    if (RECVFROM_ERROR == NumOfReadBytes)
    {
        printf("Recvfrom Error\n");
        exit(1);
    }    

    buffer[NumOfReadBytes] = '\0';

    printf("Receive message from server is: %s\n", buffer);

    sleep(2);
}

int main(void)
{
    int socketClient;
    struct sockaddr_in serverAddress;
    char *sendStr = "Hey, it's udpClient!";
    char *sendStr2 = "Good and you?";

    socketClient = socket(AF_INET, SOCK_DGRAM, 0);

    if (SOCKET_ERROR == socketClient)
    {
        printf("Socket error\n");
        return FAILURE;
    }
    
    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(8955);

    SendMessage(socketClient, sendStr, strlen(sendStr), serverAddress);

    ReceiveMessage(socketClient, serverAddress);

    ReceiveMessage(socketClient, serverAddress);

    SendMessage(socketClient, sendStr2, strlen(sendStr2), serverAddress);

    ReceiveMessage(socketClient, serverAddress);

    close(socket);

    return SUCCESS;
}