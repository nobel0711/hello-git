#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#define BUFSIZE 128
int main(int argc, char * arg[]) 
{
	int i;
	if(argc != 3) 
	{
		printf("error usage\n");
		return 1;
	}
	int fd[2];
	for(i=0; i<2; i++)
		if((fd[i]=open(arg[i+1], O_RDONLY)) == -1) 
			printf("Failed to open the file %s\n", arg[i+1]);
	while(fd[0]!=-1 || fd[1]!=-1) 
	{
		fd_set readset;
		FD_ZERO(&readset);
		for(i=0; i<2; i++) 
			if(fd[i]!=-1) 
				FD_SET(fd[i], &readset);
		int maxfd=fd[0]>fd[1]?fd[0]:fd[1];
		int readynum=select(maxfd+1, &readset, NULL, NULL, NULL);
		if(readynum==-1)
			perror("select error");
		for(i=0; i<2; i++)
		{
			if(fd[i]!=-1 && FD_ISSET(fd[i], &readset)) 
			{
				char buffer[BUFSIZE];
				int numread = read(fd[i], buffer, 1);
				if(numread==0 || numread==-1) 
				{	
					close(fd[i]);
					fd[i]=-1;
				}                      
				else
					write(STDOUT_FILENO, buffer, numread);
			}
		}
	}
	return 0;
}

