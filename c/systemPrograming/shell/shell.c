#include <stdio.h> /* printf, fgets */
#include <stdlib.h> /* exit */
#include <string.h> /* strtok */
#include <unistd.h> /* fork, exevp */

#define STR_LENGTH 1000
#define AGRV_NUM_OF_COMMAND 100

typedef enum Status
{
	SUCCESS = 0,
	FAILURE
} Status_t;

/**************************************************************/

static int GetInputStrToArgv(char *_buffer, char **_argv)
{
    char *token = NULL;
    size_t agrc;

    if (NULL == fgets(_buffer, STR_LENGTH, stdin))
    {
        return FAILURE;
    }

    for (agrc = 0, token = strtok(_buffer, " \n");NULL != token && agrc < AGRV_NUM_OF_COMMAND;++agrc, token = strtok(NULL, " \n"))
    {
        _argv[agrc] = token;
    }

    _argv[agrc] = NULL;

    return SUCCESS;
}

/**************************************************************/

int main(void)
{
    char buffer[STR_LENGTH];
    char *argv[AGRV_NUM_OF_COMMAND];
    int pid, status;

    while(1)
    {
        printf("\033[1;33meliorn@shell:~$ \033[0m");

        if (FAILURE == GetInputStrToArgv(buffer, argv))
        {
            return FAILURE;
        }

        pid = fork();

        if (pid < 0) /* error code handling */
        {
            printf("Error code handling\n");
            break;
        }
        else if (!pid) /* child process */
        {
            execvp(argv[0], argv);
            printf("\033[1;31mCommand not found! Try again..\n\033[0m");
            exit(1);
        }
        else if (0 < pid) /* parent process */
        {
            waitpid(pid, &status, 0);
        }
    }

    return SUCCESS;
}
