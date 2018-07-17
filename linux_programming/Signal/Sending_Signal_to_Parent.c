#include <stdio.h>
#include <signal.h>
int main(void)
{
	pid_t childpid;
	childpid = fork();
	//error handling omitted
	if(childpid == 0)
	{
		sleep(2);
		kill(getppid(), SIGUSR1);
	}
	else
	{
		int i;
		for(i=0;;i++)
			printf("i:%d\n", i);
	}
	printf("hahahahaha");
	return 0;
}

