#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>


pid_t childpid_fun;
void *thread_func(void *arg) 
{
	//non portable code

//	sleep(4);

	//pid_t childpid_fun;
//	childpid_fun=fork();
	system("ls");
	//execlp("ps", "ps", "-ax",  (char *)0);
	fprintf(stderr, "pid:%ld, tid:%lx\n", (long)getpid(), (unsigned long)pthread_self());
	return NULL;
}

int main(void)
{
	int error;
	pid_t childpid;
	pthread_t tid;

//	childpid=fork();
	
	if((error=pthread_create(&tid, NULL, thread_func, NULL)))
		fprintf(stderr, "Failed to create thread: %d\n", strerror(error));

//	sleep(2);
//	childpid=fork();

	if((error=pthread_join(tid, NULL)))
		fprintf(stderr, "Failed to join thread: %d\n", strerror(error));

	childpid_fun=fork();
	if(childpid_fun>0)
	{
		wait(NULL);
		fprintf(stderr, "pid:%ld, tid:%lx (main thread),parent process\n", (long)getpid(), (unsigned long)pthread_self());
	}
	else
		fprintf(stderr, "pid:%ld, tid:%lx (main thread),child process\n", (long)getpid(), (unsigned long)pthread_self());
	return 0;
}

