#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#define FLAGS O_WRONLY | O_CREAT | O_APPEND
#define MODES S_IRUSR | S_IWUSR
int main(void) 
{
	int fd;
	if((fd=open("./dup2test", FLAGS, MODES)) == -1)
	{
		perror("Failed to open file");
		return 1;
	}
	if(dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("Failed to redirect stdout");
		return 1;
	}
	//error handling omitted
	close(fd);
	char buf[]="redirect\n";
	write(STDOUT_FILENO, buf, strlen(buf));
	return 0;
} 

