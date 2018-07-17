#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
int main(void)
{    
	int wfd;    
	if((wfd=open("./iotest", O_WRONLY|O_CREAT , S_IRUSR|S_IWUSR))  == -1) 
		perror("Failed to open the file");    
	int childpid = fork();    
	if(childpid == 0) 
	{ 
		char *msg="child 1";        
		write(wfd, msg, strlen(msg));        
		close(wfd);    
	}    
	if(childpid > 0) 
	{        
		char *msg="parent process";        
		write(wfd, msg, strlen(msg));       
		close(wfd);    
	}    
	return 0;
}

