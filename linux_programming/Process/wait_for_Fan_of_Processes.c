#include <stdio.h>
#include <sys/wait.h>
int main(void)
{
	int i, n=10; 
	pid_t childpid;
	for(i=1; i<=n; i++)
	{
		childpid = fork();
		if(childpid <= 0)
			break;
	}
	while(wait(NULL)!=-1)
		;
	printf("i:%d pid:%ld parentid:%ld childid:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
	return 0;
}

