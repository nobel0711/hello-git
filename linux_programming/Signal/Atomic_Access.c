#include <stdio.h>
#include <signal.h>
sig_atomic_t doneflag=0;
void catchctrlc(int signo) 
{
	doneflag=1;
}
int main(void)
{
	struct sigaction act;
	act.sa_handler = catchctrlc;
	act.sa_flags = 0;
	if((sigemptyset(&act.sa_mask) == -1) || (sigaction(SIGINT, &act, NULL) == -1))
		perror("Failed to set SIGINT to handle Ctrl-C");
	while(!doneflag) 
	{
		char ch='a'-1;
		while(ch++!='z') 
		{
			fputc(ch, stderr);
			int i;
			for(i=0; i<20000000; i++);
		}
		fputc('\n', stderr);
	}
	printf("Programterminating ...\n");
	return 0;
}

