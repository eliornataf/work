#include <stdio.h> /* printf */
#include "tcpSelectServer.h" /* TCP No Blocking Client Header */

#define SUCCEEDED ("\033[1;32mSuccess\033[0m") 
#define FAILED ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCEEDED : FAILED ))

void ServerTest(void)
{
    TCPServer_t *tcpServer = NULL;
    int status;

    printf("\033[1;34m\n*******Server Test:*******\n\n\033[0m");

    tcpServer = InitServer();

    printf("Init TCP Server Func Test: ");

    CHECK_FUNC(NULL != tcpServer);

    printf("Run TCP Server Func Test:\n\n");

    status = RunServer(tcpServer);

    printf("Run TCP Server Func Test: (status)");

    CHECK_FUNC(FAILURE != status);

    DestroyServer(&tcpServer);

    printf("Destroy TCP Server Func Test: ");

    CHECK_FUNC(NULL == tcpServer);
}

int main(void)
{
    ServerTest();

    return SUCCESS;
}
