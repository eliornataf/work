#include <stdio.h> /* printf */ 
#include <unistd.h> /* fork */

int main(void)
{
    int pid;

    printf("\033[1;31mProgram start\n\033[0m");

    sleep(5);

    pid = fork();

    if (pid < 0) /* error code handling */
    {
        printf("Error code handling\n");
    }
    else if (!pid) /* child process */
    {
        printf("\033[1;34mChild process start\n\033[0m");
        sleep(20);
        printf("\033[1;34mChild process end\n\033[0m");
    }
    else if (0 < pid) /* parent process */
    {
        printf("\033[1;32mParent process start\n\033[0m");
        sleep(10);
        printf("\033[1;32mParent process end\n\033[0m");
    }

    printf("\033[1;31mProgram end\n\033[0m");

    return 0;
}