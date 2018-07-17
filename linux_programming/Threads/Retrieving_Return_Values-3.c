#include <stdio.h>
#include <pthread.h>
//double ret=0.0;
void *thread_func(void *arg) 
{
	//non portable code
	fprintf(stderr, "tid:%x\n", (int)pthread_self());
	double *ret=(double*)arg;
	*ret=1.0f;
	fprintf(stderr, "in thread_func : %.1f\n", *ret);
	//ret=1.0f;
	//pthread_detach(pthread_self());
	//fprintf(stderr, "in thread_func : %.1f\n", ret);
	

	return NULL;
}
int main(void)
{
	int error;
	pthread_t tid;
	double ret;
	if((error=pthread_create(&tid, NULL, thread_func, (void*)&ret)))
	//if((error=pthread_create(&tid, NULL, thread_func, NULL)))
		fprintf(stderr, "Failed to create thread: %d\n", strerror(error));
	if((error=pthread_join(tid, NULL)))
		fprintf(stderr, "Failed to join thread: %d\n", strerror(error));
	fprintf(stderr, "in main : %.1f\n", ret);
	return 0;
}

