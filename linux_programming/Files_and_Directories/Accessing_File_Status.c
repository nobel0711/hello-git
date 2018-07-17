#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
int main(int argc, char *arg[]) 
{
	if(argc!=2)
	{
		printf("error usage\n");
		return 1;
	}
	struct stat statbuf;
	if(stat(arg[1], &statbuf) == -1) 
	{ // lstat(arg[1], &statbuf) 
		printf("falied to get status\n");
		return 1;
	}
	if(S_ISDIR(statbuf.st_mode))
		printf("%s is a directory\n", arg[1]);
	printf("[%s] : \n", arg[1]);
	printf("number of hard link  : %d\n", statbuf.st_nlink);
	printf("size : %d\n", statbuf.st_size); 
	printf("last access at : %s", ctime(&(statbuf.st_atime)));
	printf("last modification at : %s", ctime(&(statbuf.st_mtime)));
	return 0;
}
