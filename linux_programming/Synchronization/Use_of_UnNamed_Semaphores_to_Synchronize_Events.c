#include <stdio.h>      
#include <stdlib.h>    
#include <semaphore.h>  

void handler1(void *ptr);
void handler2(void *ptr);
sem_t mutex;
int counter;
int main()
{
    int i[2];
    pthread_t thread_a;
    pthread_t thread_b;
    i[0] = 1;
    i[1] = 2;
    sem_init(&mutex, 0, 0);
    pthread_create(&thread_a, NULL, (void *) &handler1, (void *) &i[0]);
    pthread_create(&thread_b, NULL, (void *) &handler2, (void *) &i[1]);
    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);
    sem_destroy(&mutex);
    exit(0);
}

void handler1 ( void *ptr )
{
    int x;
    x=*((int *) ptr);
    printf("Thread %d: Waiting to enter critical region...\n", x);
    sem_wait(&mutex);
    printf("function(handler1) thread\n");
    pthread_exit(0);
}

void handler2 ( void *ptr )
{
    int x;
    x=*((int *) ptr);
    printf("Thread %d: Waiting to enter critical region...\n", x);
    printf("function(handler2) thread\n");
    sem_post(&mutex);
    pthread_exit(0);
}

