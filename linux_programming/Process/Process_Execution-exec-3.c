#include <stdio.h>
#include <unistd.h>
int main(void)
{
	pid_t pid=fork();
	if(pid==0)
		execl("/bin/ls", "ls", "-l", NULL);
	if(pid>0)
		waitpid(pid, NULL, 0);
	return 0;
}

