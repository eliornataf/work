#include <stdio.h> /* printf */ 
#include <unistd.h> /* fork */

int g_var = 0;

int main(void)
{
    int l_var = 0;
    int pid = fork();
    size_t i;
    
    printf("\033[1;31mProgram start\n\033[0m");

    if (pid < 0) /* error code handling */
    {
        printf("Error code handling\n");
    }
    else if (!pid) /* child process */
    {
        for (i = 0;i < 30;++i)
        {
            printf("\033[1;34mChild process g_var is %d and l_var is %d\n\033[0m", g_var--, l_var--);
            sleep(1);
        }
    }
    else if (0 < pid) /* parent process */
    {
        for (i = 0;i < 30;++i)
        {
            printf("\033[1;32mParent process g_var is %d and l_var is %d\n\033[0m", g_var++, l_var++);
            sleep(1);
        }
    }

    printf("\033[1;31mProgram end\n\033[0m");

    return 0;
}