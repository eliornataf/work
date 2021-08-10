#include <arpa/inet.h>  /* htons */
#include <stdio.h> /* fopen, fclose */
#include <stdlib.h> /* atoi */
#include <string.h>     /* memset, strlen, strcpy, strcat */
#include <sys/types.h>  /*  connect, send, socket, recv */
#include <sys/socket.h> /* connect, send, socket, recv */
#include <unistd.h>     /* close */

#include "utilites.h" /* Utitlites Header */

#define SOCKET_ERROR (-1)
#define BUFFER_LENGTH (4096)

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static Status_t InitSender(int *senderSocket, struct sockaddr_in *senderAddress, char *groupPort, char *groupIp);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

Status_t RunChatSender(char *_groupPort, char *_groupIp, char *_userName)
{
    int senderSocket;
    struct sockaddr_in senderAddress;
    byte senderMessage[BUFFER_LENGTH];
    byte buffer[BUFFER_LENGTH];
    size_t numOfSendBytes, sendMessageLength;

    if(!_groupPort || !_groupIp || !_userName)
    {
        return FAILURE;
    }

    if (SUCCESS != InitSender(&senderSocket, &senderAddress, _groupPort, _groupIp))
    {
        return FAILURE;
    }

    while (1)
    {
        strcpy(senderMessage, _userName);
        strcat(senderMessage, ": ");

        fflush(stdin);
        fgets(buffer ,BUFFER_LENGTH, stdin);
        fflush(stdin);

        strcat(senderMessage, buffer);

        senderMessage[strlen((char*)senderMessage) - 1] = '\0';

        sendMessageLength = strlen(senderMessage);

        numOfSendBytes = sendto(senderSocket, senderMessage, sendMessageLength, 0, (struct sockaddr*)&senderAddress, sizeof(senderAddress));

        if (numOfSendBytes != sendMessageLength)
        {
            close(senderSocket);
            return FAILURE;
        }   
    }
}

/*******************************************************
******************** Main Function *********************
*******************************************************/

int main(int argc, char *argv[])
{
    FILE *senderPidFile = NULL;
    pid_t senderPid;

    if (5 != argc)
    {
        return FAILURE;
    }

    senderPid = getpid();

    senderPidFile = fopen("senderPidFile", "w");
    if (!senderPidFile)
    {
        return FAILURE;
    }

    printf("%s:\n", argv[4]);
    printf("%s:\n", argv[3]);
    fprintf(senderPidFile, "%d\n", senderPid);

    fclose(senderPidFile);

    if (SUCCESS != RunChatSender(argv[1], argv[2], argv[3]))
    {
        printf("Sender had some problems!\n");
    }

    return SUCCESS;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static Status_t InitSender(int *_senderSocket, struct sockaddr_in *_senderAddress, char *_groupPort, char *_groupIp)
{
    *_senderSocket = socket(AF_INET, SOCK_DGRAM, 0);

    if (SOCKET_ERROR == _senderSocket)
    {
        return FAILURE;
    }
    
    memset(_senderAddress, 0, sizeof(*_senderAddress));

    _senderAddress->sin_family = AF_INET;
    _senderAddress->sin_addr.s_addr = inet_addr(_groupIp);
    _senderAddress->sin_port = htons(atoi(_groupPort));

    return SUCCESS;
}