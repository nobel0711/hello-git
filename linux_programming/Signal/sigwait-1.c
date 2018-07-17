#include <stdio.h>
#include <signal.h>
int main(void)
{
	int sigcount=0;
	int signum = SIGINT;
	int signum2 = SIGTSTP;
	int signo;
	sigset_t sigset;
	if(sigemptyset(&sigset) == -1 ||  sigaddset(&sigset, signum) == -1 || sigaddset(&sigset, signum2) == -1 || sigprocmask(SIG_BLOCK, &sigset, NULL) == -1)
		perror("Failed to block signal ");
	for(;;)
	{
		sigwait(&sigset, &signo);
		sigcount++;
		printf("number of signal : %d %d\n", sigcount, signo);
	}
	return 0;
}

