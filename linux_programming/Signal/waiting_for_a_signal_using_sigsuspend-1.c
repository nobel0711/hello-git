#include <stdio.h>
#include <signal.h>
sig_atomic_t sigreceived=0;
void receiveSIG(int signo)
{
	sigreceived=1;
}
int main(void)
{
	struct sigaction act;
	act.sa_handler = receiveSIG;
	act.sa_flags = 0;
	//error handling omitted for clarity
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT, &act, NULL);

	sigset_t masknew, maskold;
	sigprocmask(SIG_SETMASK, NULL, &masknew);
	sigaddset(&masknew, SIGINT);
	sigprocmask(SIG_SETMASK, &masknew, &maskold);
	sigdelset(&masknew, SIGINT);
	while(sigreceived == 0) 
	{
		sleep(5);
		printf("before calling sigsuspend()\n");
		sigsuspend(&masknew);
		printf("after calling sigsuspend()\n");
	}
	printf("received SIGINT\n");
	return 0;
}

