#include <stdio.h>
#include <signal.h>
int main(void)
{
	//error handling omitted for clarity
	int childpid;
	int signum = SIGUSR1;
	int signo;
	sigset_t sigset;
	if(sigemptyset(&sigset) == -1 || sigaddset(&sigset, signum) == -1 || sigprocmask(SIG_BLOCK, &sigset, NULL) == -1)
		perror("Failed to block signal ");

	childpid = fork();
	if(childpid==0) 
	{
		kill(getppid(), signum);
		printf("child\n");
	}
	if(childpid>0)
	{
		sleep(3);
		sigwait(&sigset, &signo);
		printf("parent\n");
		wait(NULL);
	}
	return 0;
}

