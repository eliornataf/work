#include <pthread.h> /* pthread_create, pthread_join, pthread_exit */
#include <semaphore.h> /* sem_init, sem_wait, sem_post, sem_dstroy */
#include <stdio.h> /* printf */

#define NUM_OF_THREADS 100

#define DO_NOT_SHARE_SEM_WITH_OTHER_PROCCESSES (0)

#define PRODUCER_SEM_INIT_VALUE (100)
#define BINARY_SEM_INIT_VALUE (1)
#define CONSUMER_SEM_INIT_VALUE (0)

#define MAX_ITER_NUM (100)

typedef enum Status
{
    SUCCESS = 0,
    FAILURE
} Status_t;

/******************************************************************************/

static sem_t g_semProducer = {0};
static sem_t g_semMutex = {0};
static sem_t g_semConsumer = {0};

static int g_var = 0;

/******************************************************************************/

static void *ProducerBinary(void *_noNeed)
{
    size_t i;

    (void)_noNeed;

    for (i = 0;i < MAX_ITER_NUM;++i)
    {
        sem_wait(&g_semProducer);
        sem_wait(&g_semMutex);

        printf("\033[1;34mg_var value [Producer]: %d\n\033[0m", ++g_var);

        sem_post(&g_semMutex);
        sem_post(&g_semConsumer);
    }
}

static void *ConsumerBinary(void *_noNeed)
{
    size_t i;

    (void)_noNeed;

    for (i = 0;i < MAX_ITER_NUM;++i)
    {
        sem_wait(&g_semConsumer);
        sem_wait(&g_semMutex);

        printf("\033[1;32mg_var value [Consumer]: %d\n\033[0m", --g_var);

        sem_post(&g_semMutex);
        sem_post(&g_semProducer);
    }
}

/******************************************************************************/

int ProducerConsumerBinary(void)
{
    pthread_t producerThreads[NUM_OF_THREADS];
    pthread_t consumerThreads[NUM_OF_THREADS];
    int status;
    size_t i;

    if (0 != sem_init(&g_semProducer, DO_NOT_SHARE_SEM_WITH_OTHER_PROCCESSES, PRODUCER_SEM_INIT_VALUE))
    {
        return FAILURE;
    }

    if (0 != sem_init(&g_semMutex, DO_NOT_SHARE_SEM_WITH_OTHER_PROCCESSES, BINARY_SEM_INIT_VALUE))
    {
        return FAILURE;
    }

    if (0 != sem_init(&g_semConsumer, DO_NOT_SHARE_SEM_WITH_OTHER_PROCCESSES, CONSUMER_SEM_INIT_VALUE))
    {
        return FAILURE;
    }

    for (i = 0;i < NUM_OF_THREADS;++i)
    {
        status = pthread_create(&producerThreads[i], NULL, ProducerBinary, NULL);

        while (0 != status)
        {
            status = pthread_create(&producerThreads[i], NULL, ProducerBinary, NULL);
        }

        status = pthread_create(&consumerThreads[i], NULL, ConsumerBinary, NULL);

        while (0 != status)
        {
            status = pthread_create(&consumerThreads[i], NULL, ConsumerBinary, NULL);
        }
    }

    for (i = 0;i < NUM_OF_THREADS;++i)
    {
        status = pthread_join(producerThreads[i], NULL);

        while (0 != status)
        {
            status = pthread_join(producerThreads[i], NULL);
        }

        status = pthread_join(consumerThreads[i], NULL);

        while (0 != status)
        {
            status = pthread_join(consumerThreads[i], NULL);
        }
    }

    if (0 != sem_destroy(&g_semProducer))
    {
        return FAILURE;
    }

    if (0 != sem_destroy(&g_semMutex))
    {
        return FAILURE;
    }

    if (0 != sem_destroy(&g_semConsumer))
    {
        return FAILURE;
    }

    return SUCCESS;
}


int main(void)
{
    return ProducerConsumerBinary();
}