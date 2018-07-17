#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void catchctrlc(int signo) 
{
	char handmsg[] ="Received Ctrl-C\n";
	int msglen=sizeof(handmsg);
	write(STDERR_FILENO, handmsg, msglen);
}
int main(void) 
{
	struct sigaction act;
	act.sa_handler = catchctrlc;
	act.sa_flags = 0;
	if((sigemptyset(&act.sa_mask) == -1) || (sigaction(SIGINT, &act, NULL) == -1))
		perror("Failed to set SIGINT to handle Ctrl-C");
	printf("befor calling pause()\n");
	pause();
	printf("after calling pause()\n");
	return 0;
}


