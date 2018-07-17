#include <stdio.h>
#include <signal.h>
void recvUSR1(int signo)
{
	printf("received SIGUSER1\n");
}
int main(void) 
{
	//error handling omitted for clarity
	int childpid;
	signal(SIGUSR1, recvUSR1);
	childpid = fork();
	if(childpid==0)
	{
		sleep(3);
		pause();
		printf("child\n");
	}
	if(childpid>0)
	{
		printf("parent\n");
		kill(childpid, SIGUSR1);
		wait(NULL);
	}
	return 0;
}

