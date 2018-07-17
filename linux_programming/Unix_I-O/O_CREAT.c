#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#define FLAGS O_WRONLY|O_CREAT
#define MODES S_IRUSR|S_IWUSR
int main(void) 
{
	int fd;
	char buf[]="test\n";
	if((fd=open("create_flag", FLAGS, MODES))==-1) 
	{
		perror("Failed to open file");
		return 1;
	}
	write(fd, buf, strlen(buf));
	close(fd);
	return 0;
}

