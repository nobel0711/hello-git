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
		exit(7);
	//parent
	if(wait(&status) != pid)
		fprintf(stderr, "wait error\n");
	print_termination_status(status);
	exit(0);
}
void print_termination_status(int status)
{
	if(WIFEXITED(status))
		fprintf(stderr, "normal termination, exit status = %d\n", WEXITSTATUS(status));
	else if(WIFSIGNALED(status))
		fprintf(stderr, "abnormal termination, signal number = %d\n", WTERMSIG(status));
}

