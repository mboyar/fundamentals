/*----------------------------------------------------------------------------------------------------------------------
    Üretici tüketici probleminin semaphore ile çözümü
----------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define QUEUE_SIZE 10

void *thread_proc_producer(void *param);
void *thread_proc_consumer(void *param);

void exit_sys(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

void exit_sys_thread(const char *msg, int err_num)
{
    fprintf(stderr, "%s:%s\n", msg, strerror(err_num));
    exit(EXIT_FAILURE);
}

sem_t g_sem_producer;
sem_t g_sem_consumer;
int g_queue[QUEUE_SIZE];
int g_head, g_tail;

int main(void)
{
    pthread_t tid_producer, tid_consumer;
    int result;

    if ((result = sem_init(&g_sem_producer, 0, QUEUE_SIZE)) != 0)
        exit_sys_thread("sem_init", result);

    if ((result = sem_init(&g_sem_consumer, 0, 0)) != 0)
        exit_sys_thread("sem_init", result);

    if ((result = pthread_create(&tid_producer, NULL, thread_proc_producer, NULL)) != 0)
        exit_sys_thread("pthread_create", result);

    if ((result = pthread_create(&tid_consumer, NULL, thread_proc_consumer, NULL)) != 0)
        exit_sys_thread("pthread_create", result);

    if ((result = pthread_join(tid_producer, NULL)) != 0)
        exit_sys_thread("pthread_join", result);

    if ((result = pthread_join(tid_consumer, NULL)) != 0)
        exit_sys_thread("pthread_join", result);

    sem_destroy(&g_sem_producer);
    sem_destroy(&g_sem_consumer);

    return 0;
}

void *thread_proc_producer(void *param)
{
    int i;

    i = 0;
    for (;;) {
        usleep(rand() % 300000);
        sem_wait(&g_sem_producer);
        g_queue[g_tail++] = i;
        g_tail %= QUEUE_SIZE; /* Dizinin uzunluğunu geçmemesi için yapılıyor*/
        sem_post(&g_sem_consumer);
        if (i == 99)
            break;

        ++i;
    }

    return NULL;
}

void *thread_proc_consumer(void *param)
{
    int val;

    for (;;) {
        sem_wait(&g_sem_consumer);
        val = g_queue[g_head++];
        g_head %= QUEUE_SIZE; /* Dizinin uzunluğunu geçmemesi için yapılıyor*/
        sem_post(&g_sem_producer);

        usleep(rand() % 300000);
        printf("%d ", val);
        fflush(stdout);
        if (val == 99)
            break;
    }
    putchar('\n');

    return NULL;
}
