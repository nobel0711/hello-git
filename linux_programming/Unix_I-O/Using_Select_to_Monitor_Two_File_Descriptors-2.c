#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#define BUFSIZE 128
int main(int argc, char * arg[]) 
{
	int i;
	if(argc != 2) 
	{
		printf("error usage\n");
		return 1;
	}

	int fd[2];

	char fifo_name[]="./myfifo1";
	if(mkfifo(fifo_name, S_IRUSR | S_IWUSR) ==-1 &&  errno!=EEXIST) 
	{
		perror("cannot create fifo");
		return 1;
	}	
	

	if((fd[0]=open(arg[1], O_RDONLY)) == -1) 
			printf("Failed to open the file %s\n", arg[i+1]);

	if((fd[1]=open(fifo_name, O_RDWR)) == -1) 
	{
		perror("cannot open fifo for writing");
		return 0;
	}

	struct timeval tv;
	while(fd[0]!=-1 || fd[1]!=-1) 
	{
		fd_set readset;
		FD_ZERO(&readset);		
		for(i=0; i<2; i++) 
			if(fd[i]!=-1) 
				FD_SET(fd[i], &readset);
		int maxfd=fd[0]>fd[1]?fd[0]:fd[1];

	        tv.tv_sec=1;
        	tv.tv_usec=0;

		int readynum=select(maxfd+1, &readset, NULL, NULL, &tv);

        	if(readynum==-1)
                  	perror("select error");
		else if(readynum==0)
			printf("hi everybody\n");

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

