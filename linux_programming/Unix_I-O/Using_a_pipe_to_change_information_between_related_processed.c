#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define BUFSIZE 10

int main(void) 
{
	char buffer_in[BUFSIZE]="iiiii";
	char buffer_out[]="ooooo";
	int fd[2];
	pid_t childpid;
	if(pipe(fd)==-1)
		perror("cannot create a pipe:");
	childpid=fork();
	if(childpid==0)  
	{ //child
		close(fd[0]);
		write(fd[1], buffer_out, strlen(buffer_out)+1);
		close(fd[1]);
	}
	if(childpid>0) 
	{ //parent
		close(fd[1]);
		read(fd[0], buffer_in, BUFSIZE);
		printf("%s\n",buffer_in);
		close(fd[0]);
	}
	return 0;
}

