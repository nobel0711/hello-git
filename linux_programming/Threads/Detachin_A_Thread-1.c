#include <stdio.h>
#include <pthread.h>
void *thread_func(void* arg) 
{
	pthread_detach(pthread_self());
	return NULL;
}
int main(void) 
{
	int error;
	pthread_t tid;
	if((error=pthread_create(&tid, NULL, thread_func, NULL)))
		fprintf(stderr, "Failed to create thread: %d\n", strerror(error));
	sleep(1);
	if((error=pthread_join(tid, NULL)))
		fprintf(stderr, "Failed to join thread: %d\n", strerror(error));
	fprintf(stderr, "main thread finished\n");
	return 0;
}

