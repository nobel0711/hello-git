#include <stdio.h>
#include <sys/wait.h>
int main(int argc, char **argv)
{
	pid_t   pid;
	int     status;
	switch(pid = fork())
	{
	case -1:
		perror("Fork failed");
		return -1;
	case 0:
		printf("Child: I'm %d and my parent is %d\n", getpid(), getppid());
		return 0;
	default:
		if(wait(&status) == -1)
		{
			perror("Wait failed");
			return -1;
		}
		printf("Parent: I'm %d and my child is %d\n", getpid(), pid);
	}	
	return 0;
}

