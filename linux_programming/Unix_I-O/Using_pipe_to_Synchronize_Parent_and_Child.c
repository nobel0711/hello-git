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
		fprintf(stderr, "child sleeping for 3 secs\n");
		sleep(3);
		fprintf(stderr, "child process\n");
		close(fd[0]);
		write(fd[1], "p", 1);
		close(fd[1]);
	}
	if(childpid>0) 
	{ //parent
		char c;
		close(fd[1]);
		read(fd[0], &c, 1);
		close(fd[0]);
		fprintf(stderr, "parent process\n");
	} 
	return 0;
}

