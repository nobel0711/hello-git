#include <stdio.h>
#include <pthread.h>
pthread_mutex_t mutexa =PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexb =PTHREAD_MUTEX_INITIALIZER;
void *thr_fun1(void *arg) 
{
	int i=1;
	while(1)
	{
		pthread_mutex_lock(&mutexa);
		pthread_mutex_lock(&mutexb);
		printf("thread 1 doing command : %d\n", i++);
		pthread_mutex_unlock(&mutexb);
		pthread_mutex_unlock(&mutexa);
	}
}
void *thr_fun2(void *arg) 
{
	int i=1;
	while(1)
	{
		pthread_mutex_lock(&mutexa);
		pthread_mutex_lock(&mutexb);
		printf("thread 2 doing command : %d\n", i++);
		pthread_mutex_unlock(&mutexb);
		pthread_mutex_unlock(&mutexa);
	}
}
int main()
{
	int i, j;
	pthread_t tid[2];
	//error handling omitted for clarity
	pthread_create(&tid[0], NULL, thr_fun1, NULL);
	pthread_create(&tid[1], NULL, thr_fun2, NULL);
	for(i=0; i<2; i++)
		pthread_join(tid[i], NULL);
	return 0;
}

