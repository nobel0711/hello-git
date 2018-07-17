#include <stdio.h>
#include <signal.h>
sig_atomic_t sigreceived=0;
void receiveCtrlC(int signo)
{
	sigreceived=1;
}
int main(void)
{
	struct sigaction act;
	act.sa_handler = receiveCtrlC;
	act.sa_flags = 0;
	//error handling omitted for clarity
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT, &act, NULL);

	printf("waiting ctrl-c\n");
	while(sigreceived == 0)

		pause();
	printf("received ctrl-c\n");
	return 0;
}

