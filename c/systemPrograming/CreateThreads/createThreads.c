#include <pthread.h> /* pthread_create, pthread_join, pthread_exit */
#include <stdio.h> /* printf */

#define NUM_OF_THREADS 30000

typedef enum Status
{
    SUCCESS = 0,
    FAILURE = 1
} Status_t;

/**********************************************/

size_t g_var = 0;

/**********************************************/

static void *PrintThead(void *_theadNum)
{
    size_t l_var = 0;
    size_t i;

    for (i = 0;i < 10;++i)
    {
        ++g_var;
        ++l_var;

        printf("Thread number %ld: g_var is %ld, l_var is %ld\n", (size_t)_theadNum, g_var, l_var);
    }

    pthread_exit(NULL);
}

/**********************************************/

int main(void)
{
    pthread_t threads[NUM_OF_THREADS];
    int status;
    size_t i;

    for (i = 0;i < NUM_OF_THREADS;++i)
    {
        status = pthread_create(&threads[i], NULL, &PrintThead, (void*)i);

        while (0 != status)
        {
            status = pthread_create(&threads[i], NULL, &PrintThead, (void*)i);
        }
    }

    for (i = 0;i < NUM_OF_THREADS;++i)
    {
        status = pthread_join(threads[i], NULL);

        while (0 != status)
        {
            status = pthread_join(threads[i], NULL);
        }
    }

    return SUCCESS;
}
