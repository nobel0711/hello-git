#include <stdio.h>
#include <pthread.h>
void *thread_func(void*arg) 
{
	//pthread_detach(pthread_self());
	return NULL;
}
int main(void) 
{
	int error;
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if((error=pthread_create(&tid, &attr, thread_func, NULL)))
		fprintf(stderr, "Failed to create thread: %d\n", strerror(error));
	pthread_attr_destroy(&attr);
	if((error=pthread_join(tid, NULL)))
		fprintf(stderr, "Failed to join thread: %d\n", strerror(error));
	fprintf(stderr, "main thread finished\n");
	return 0;
}

