#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#define BUFSIZE 10
int main(void)
{
	int childpid;
	char fifo_name[]="./myfifo1";
	if(mkfifo(fifo_name, S_IRUSR | S_IWUSR) ==-1 &&  errno!=EEXIST) 
	{
		perror("cannot create fifo");
		return 1;
	}
	if((childpid=fork()) == -1) 
	{
		perror("cannot fork");
		return 1;
	}
	if(childpid == 0) 
	{ // child
		char buf[]="ccccc";
		int fd;
		if((fd=open(fifo_name, O_WRONLY)) == -1) 
		{
			perror("cannot open fifo for writing");
			return 0;
		}
		sleep(1);
		write(fd, buf, strlen(buf));
	} 
	 else 
 	{//parent
		char buf[BUFSIZE]="ppppp";
		int fd;
		if((fd=open(fifo_name, O_RDONLY)) == -1) 
		{
			perror("cannot open fifo for reading");
			return 0;
		}
		printf("%s\n", buf);
		read(fd, buf, BUFSIZE);
		printf("%s\n", buf);
	 }
	 return 0;
}

