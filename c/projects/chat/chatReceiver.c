#include <arpa/inet.h>  /* htons */
#include <stdio.h> /* fopen, fclose */
#include <stdlib.h> /* atoi */
#include <string.h>     /* memset, strlen, strcpy, strcat */
#include <sys/types.h>  /*  connect, send, socket, recv */
#include <sys/socket.h> /* connect, send, socket, recv */
#include <unistd.h>     /* close */

#include "utilites.h" /* Utitltes Header */

#define SOCKET_ERROR (-1)
#define BIND_ERROR (-1)
#define RECVFROM_ERROR (-1)

#define BUFFER_LENGTH (4096)

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static Status_t InitReceiver(int *receiverSocket, struct sockaddr_in *receiverAddress, char *groupPort, char *groupIp);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

Status_t RunChatReceiver(char *_groupPort, char *_groupIp)
{
    int receiverSocket;
    struct sockaddr_in receiverAddress;
    byte buffer[BUFFER_LENGTH];
    size_t numOfReadBytes, sendMessageLength;
    socklen_t receiverAddressLength;

    if (!_groupPort || !_groupIp)
    {
        return FAILURE;
    }

    if (SUCCESS != InitReceiver(&receiverSocket, &receiverAddress, _groupPort, _groupIp))
    {
        return FAILURE;
    }

    receiverAddressLength = sizeof(receiverAddress);

    while (1)
    {
        numOfReadBytes = recvfrom(receiverSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&receiverAddress, &receiverAddressLength);

        if (RECVFROM_ERROR == numOfReadBytes)
        {
            close(receiverSocket);
            return FAILURE;
        } 

        buffer[numOfReadBytes] = '\0';

        printf("%s\n", buffer);
    }
}

/*******************************************************
******************** Main Function *********************
*******************************************************/

int main(int argc, char *argv[])
{
    FILE *receiverPidFile = NULL;
    pid_t receiverPid;

    if (4 != argc)
    {
        return FAILURE;
    }

    receiverPid = getpid();

    receiverPidFile = fopen("receiverPidFile", "w");
    if (!receiverPidFile)
    {
        return FAILURE;
    }

    printf("%s:\n", argv[3]);
    fprintf(receiverPidFile, "%d\n", receiverPid);

    fclose(receiverPidFile);

    if (SUCCESS != RunChatReceiver(argv[1], argv[2]))
    {
        printf("Receiver had some problems!\n");
    }

    return SUCCESS;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static Status_t InitReceiver(int *_receiverSocket, struct sockaddr_in *_receiverAddress, char *_groupPort, char *_groupIp)
{
    *_receiverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    if (SOCKET_ERROR == *_receiverSocket)
    {
        return FAILURE;
    }

    memset(_receiverAddress, 0, sizeof(*_receiverAddress));

    _receiverAddress->sin_family = AF_INET;
    _receiverAddress->sin_addr.s_addr = inet_addr(_groupIp);
    _receiverAddress->sin_port = htons(atoi(_groupPort));

    if (BIND_ERROR == bind(*_receiverSocket, (struct sockaddr*)_receiverAddress, sizeof(_receiverAddress)))
    {
        return FAILURE;
    }

    return SUCCESS;
}