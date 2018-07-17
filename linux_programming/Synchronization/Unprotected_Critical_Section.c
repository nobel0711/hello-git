#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
	int i, delay=1000000, n=3;
	pid_t childpid;
	for(i=1; i<=n; i++)
		if((childpid = fork()))
	break;
	char msg[128];
	snprintf(msg, 128, "i:%d PID:%ld Parent PID:%ld Child PID:%ld\n", i, (long)getpid(), 	(long)getppid(), (long)childpid);
	char *c = msg;

	while( *c != '\0' ) 
	{
		fputc(*c, stderr);
		c++;
		for(i=0; i<delay; i++) ;
	}
	while( wait(NULL)>0 );
	return 0;
}

