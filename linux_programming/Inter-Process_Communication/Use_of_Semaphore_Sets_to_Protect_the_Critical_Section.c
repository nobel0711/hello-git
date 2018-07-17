#include <stdio.h>
#include <sys/sem.h>
#include <sys/stat.h>
int main()
{
	int i, j, delay=1000;
	pid_t childpid;
	for(i=1; i<=100; i++)
		if(childpid = fork())
			break;
	char msg[128];
	snprintf(msg, 128, "i:%d PID:%ld Parent PID:%ld Child PID:%ld\n", i, (long)getpid(), 	(long)getppid(), (long)childpid); 
	char *c = msg;
	while(*c != '\0') 
	{
		fputc(*c, stderr);
		c++;
		for(j=0; j<delay; j++) ;
	}
	while(wait(NULL)>0);
	return 0;
}

