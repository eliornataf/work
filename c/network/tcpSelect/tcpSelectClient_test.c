#include <stdio.h> /* printf */
#include <time.h> /* time */
#include "tcpSelectClient.h" /* TCP Select Client Header */

#define NUM_OF_CLIENTS (1000)
#define BUFFER_LENGTH (100) 
#define HOUNDARD_PRESENT (100)

#define INIT_NEW_CLIENT (30)
#define DISCONNECT_CLIENT (5)
#define SEND_OR_RECEIVE_CLIENT (35)

#define SUCCEEDED ("\033[1;32mSuccess\033[0m") 
#define FAILED ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCEEDED : FAILED ))

void RunClient(void)
{
    int clientArr[NUM_OF_CLIENTS] = {0};
    char buffer[BUFFER_LENGTH];
    size_t i, randNum;
    
    srand(time(NULL));
    
    printf("Run TCP Client Func Test:\n\n");

    for (i = 0;;i = (i + 1) % NUM_OF_CLIENTS)
    {
        randNum = (rand() % HOUNDARD_PRESENT) + 1;

        if (!clientArr[i])
        {
            if (randNum <= INIT_NEW_CLIENT)
            {
                clientArr[i] = InitClient();

                printf("Client with Socket %d is Created\n", clientArr[i]);
            }
        }
        else
        {
            if (randNum <= DISCONNECT_CLIENT)
            {
                SendClientIsDone(clientArr[i]);

                printf("Client with Socket %d is Done\n", clientArr[i]);

                DestroyClient(clientArr[i]);

                clientArr[i] = 0;
            }
            else if (randNum <= SEND_OR_RECEIVE_CLIENT)
            {
                printf("Client with Socket %d is Sending\n", clientArr[i]);

                if (FAILURE != SendMessageToServer(clientArr[i]))
                {
                    ReceiveMessageFromServer(clientArr[i], buffer);
                }
            }
        }
    }
}

int main(void)
{
    RunClient();

    return SUCCESS;
}
