#include <fcntl.h>
#include <sys/stat.h>
struct foo
{    
	int x;    
	double y;
};
int main(void)
{    
	int wfd;    
	struct foo foo1={20, 0.1};    
	if((wfd=open("./iotest", O_WRONLY|O_CREAT , S_IRUSR|S_IWUSR)) == -1)
		perror("Failed to open the file");    
	write(wfd, &foo1, sizeof(struct foo));    
	close(wfd);    
	return 0;
}

