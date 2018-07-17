#include <stdio.h>
#include <pthread.h>
#define NUMTHREADS 10
void *printarg(void *arg) 
{
	fprintf(stderr, "Thread received %d\n", *(int*)arg);
	return NULL;
}
int main(void) 
{
	int i, j;
	pthread_t tid[NUMTHREADS];

	//error handling omitted
	for(i=0; i<NUMTHREADS; i++) 
	{
		pthread_create(tid+i, NULL, printarg, (void*)&i);
		sleep(1);
	}
	for(j=0; j<NUMTHREADS; j++) 
		pthread_join(tid[j], NULL);
	printf("All threads done\n");
	return 0;
}

