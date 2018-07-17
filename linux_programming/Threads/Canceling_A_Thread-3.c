#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void *thread_func(void *arg) 
{
	int i, oldstate, oldtype;
	fprintf(stderr, "tid:%x\n", (unsigned int)pthread_self()); //non portable code
	srand(time(NULL));
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, &oldtype);
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &oldstate);
	while(1) 
	{
		char msg[100];
		float randnum = rand()/(float)RAND_MAX;
		sprintf(msg, "random number(0-1.0) : %.5f\n", randnum);
		char *c=msg;
		while(*c!='\0') 
		{ 
			fputc(*c, stderr); 
			c++;
		}
		for(i=0; i<50000000; i++);
	}
	return NULL;
}
int main(void)
{
	int error;
	pthread_t tid;
	if((error=pthread_create(&tid, NULL, thread_func, NULL)))
		fprintf(stderr, "Failed to create thread: %d\n", strerror(error));
	sleep(2);
	pthread_cancel(tid);
	sleep(2);
//	if((error=pthread_join(tid,NULL)))
//		fprintf(stderr, "Failed to join thread: %d\n", strerror(error));
	return 0;
}

