#include <stdio.h>
#include <pthread.h>
void *thread_func(void *arg)
{
        pthread_mutex_t *mutex=(pthread_mutex_t*)arg;
        int i, delay=1000000;
        char msg[128];
        snprintf(msg, 128, "PID:%ld Parent PID:%ld Thread ID:%lx\n", (long)getpid(), (long)getppid(), (unsigned long)pthread_self());
        char *c = msg;
        pthread_mutex_lock(mutex);
        while(*c != '\0')
        {
                fputc(*c, stderr); c++;
                for(i=0; i<delay; i++) ;
        }
        pthread_mutex_unlock(mutex);
        return NULL;
}

int main(void) 
{
	int i, n=100; pthread_t tid[n];
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);
	for(i=0; i<n; i++) 
	{
		tid[i]=pthread_self();
		pthread_create(tid+i, NULL, thread_func, (void*)&mutex);
	}
	for(i=0; i<n; i++)
		pthread_join(tid[i], NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}
