#include <stdio.h>
#include <sys/stat.h>
int main(int argc, char *arg[]) 
{
	if(argc!=2)
	{
		printf("error usage\n");
		return 1;
	}
	struct stat statbuf;
	if(lstat(arg[1], &statbuf) == -1) 
	{
		printf("falied to get status\n");
		return 1;
	}
	printf("[%s] : \n", arg[1]);
	if(S_ISDIR(statbuf.st_mode))
		printf("type: Directory\n");
	else if(S_ISLNK(statbuf.st_mode))
		printf("type: Symbolic Link\n");
	else if(S_ISREG(statbuf.st_mode))
		printf("type: Regular file\n");
	else if(S_ISFIFO(statbuf.st_mode))
		printf("type: Pipe\n");
	else 
		printf("type: Other\n");
	return 0;
} 

