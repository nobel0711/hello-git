#include <stdio.h>
#include <pthread.h>
typedef struct 
{
	int id; int value; int offset;
} data_t;
void *thread_func(void *arg);
int main(void)
{
	int i, tnum=2;
	pthread_t tid[tnum];
	data_t data[2]={{1,0,+1}, {2,10,-1}};
	srand(time(NULL));
	pthread_create(&tid[0], NULL, thread_func, data);
	pthread_create(&tid[1], NULL, thread_func, data+1);
	while(data[0].value <= data[1].value)
		fprintf(stderr,"123\n");
	fprintf(stderr, "variable1(%d) > variable2(%d)\n", data[0].value, data[1].value);
	for(i=0; i<tnum; i++)
		pthread_cancel(tid[i]);
	for(i=0; i<tnum; i++)
		pthread_join(tid[i], NULL);
	fprintf(stderr, "main thread finished\n");
	return 0;
}
void *thread_func(void *arg)
{
	data_t *data=(data_t*)arg;
	while(1) 
	{
		if(rand()%3 ==0) 
		{
		   data->value += data->offset;
	                          fprintf(stderr,"variable%d:%d\n",                                                     data->id, data->value);
		}
	sleep(1);
	}
}

