#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc, char * arg[]) 
{
	if(argc!=2)
	{
		printf("error usage\n");
		return 0;
	}
	int fd = open(arg[1], O_WRONLY);
	struct flock lock;
	lock.l_type=F_WRLCK;
	lock.l_start = 0;
	lock.l_whence = SEEK_SET;
	lock.l_len = 0;
	if(fcntl(fd, F_SETLKW, &lock)== -1)
	{
		printf("failed to lock %s for writing\n", arg[1]);
		return 1;
	}
	printf("%s is locked for writing\n", arg[1]);
	printf("press enter to unlock\n");
	getchar();
	lock.l_type=F_UNLCK;
	if(fcntl(fd, F_SETLK, &lock)== -1) 
	{
		printf("failed to unlock\n");
		return 1;
	}
	printf("unlock successfully\n");
	return 0;
}

