#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#define FLAGS O_WRONLY|O_CREAT|O_EXCL
#define MODES S_IRUSR|S_IWUSR
int main(void) 
{
	int fd;
	if((fd=open("excl_flag", FLAGS, MODES))==-1 && errno!=EEXIST) 
	{
		perror("Failed to open file");
		return 1;
	}
	if(fd==-1 && errno==EEXIST)
		printf("file already exists\n");
	else
		printf("file created\n");
	close(fd);
	return 0;
}

