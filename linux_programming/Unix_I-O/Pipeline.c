#include <stdio.h>
#include <unistd.h>
int main(void) 
{
	int fd[2];
	pid_t childpid;
	if(pipe(fd)==-1)
		perror("cannot create a pipe:");
	childpid=fork();
	if(childpid==0)  
	{ //child
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execl("/bin/ls", "ls", "-l", NULL);
	}
	
	if(childpid>0) 
	{ //parent
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		execl("/usr/bin/sort", "sort", NULL);
	}
	return 0;
}

