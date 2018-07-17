#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *thread_func(void *arg) 
{
	//non portable code
	fprintf(stderr, "tid:%x\n", (int)pthread_self());
	double *ret=malloc(sizeof(*ret));
	if(!ret) 
		return NULL;
	*ret=1.0;
	fprintf(stderr, "in thread_func : %.1f\n", *ret);
	pthread_detach(pthread_self());
	return (void*)ret;
}
int main(void) 
{
	int error; double *ret; pthread_t tid;
	if((error=pthread_create(&tid, NULL, thread_func, NULL)))
		fprintf(stderr, "Failed to create thread: %d\n", strerror(error));
	if((error=pthread_join(tid, (void**)&ret)))
		fprintf(stderr, "Failed to join thread: %d\n", strerror(error));
	if(error==0)
	{
		fprintf(stderr, "in main : %.1f\n", *ret);
		free(ret);
	}
	return 0;
}

