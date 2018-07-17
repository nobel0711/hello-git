#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
void print_termination_status(int status);
int main(void) 
{
	pid_t pid;
	int status;
	if((pid = fork()) == -1)
		fprintf(stderr, "fork error\n");
	else if(pid == 0) // child
	{
		int *p = NULL;
		*p = 10;
		printf("test");
	}
	//parent
	if(wait(&status) != pid)
		fprintf(stderr, "wait error\n");
	print_termination_status(status);
	exit(0);
}
void print_termination_status(int status)
{
	if(WIFEXITED(status))
		printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
	else if(WIFSIGNALED(status))
		printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status), "");
}

