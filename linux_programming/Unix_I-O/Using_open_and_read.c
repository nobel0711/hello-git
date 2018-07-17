#include <fcntl.h>
#include <stdio.h>
struct foo
{    
	int x;    
	double y;
};
int main(void)
{    
	int rfd;    
	struct foo foo1={0, 0};    
	if((rfd=open("./iotest", O_RDONLY))== -1)         
		perror("Failed to open the file");    
	read(rfd, &foo1, sizeof(struct foo));    
	printf("foo.x:%d foo.y:%.1f\n", foo1.x, foo1.y);    
	close(rfd);    
	return 0;
}

