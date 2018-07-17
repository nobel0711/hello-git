#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
void print_termination_status(int status);
int main(void)
{
	int ret;
	if((ret=system("date"))==-1)
		perror("system()");
	else
		print_termination_status(ret);
	if((ret=system("notacommand"))==-1)
		perror("system()");
	else
		print_termination_status(ret);
	return 0;
}

void print_termination_status(int status)
{
	if(WIFEXITED(status))
		fprintf(stderr, "normal termination, exit status = %d\n", WEXITSTATUS(status));
	else if(WIFSIGNALED(status))
		fprintf(stderr, "abnormal termination, signal number = %d\n", WTERMSIG(status));
}

