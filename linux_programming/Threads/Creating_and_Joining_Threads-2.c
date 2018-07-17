#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int error;
pthread_t tid,tid2;
void *thread_func(void *arg) 
{
	sleep(5);
	if((error=pthread_join(tid2, NULL)))
		fprintf(stderr, "Failed to join thread: %d\n", strerror(error));
	fprintf(stderr, "pid:%ld, tid:%lx,funthread1\n", (long)getpid(), (unsigned long)pthread_self());
	return NULL;
}

void *thread_func2(void *arg) 
{
	fprintf(stderr, "pid:%ld, tid:%lx,funthread2\n", (long)getpid(), (unsigned long)pthread_self());
	//return NULL;
	exit(0);
}

int main(void)
{
	if((error=pthread_create(&tid, NULL, thread_func, NULL)))
		fprintf(stderr, "Failed to create thread: %d\n", strerror(error));

	if((error=pthread_create(&tid2, NULL, thread_func2, NULL)))
		fprintf(stderr, "Failed to create thread: %d\n", strerror(error));

	if((error=pthread_join(tid, NULL)))
		fprintf(stderr, "Failed to join thread: %d\n", strerror(error));
	fprintf(stderr, "pid:%ld, tid:%lx (main thread)\n", (long)getpid(), (unsigned long)pthread_self());
	return 0;
}

