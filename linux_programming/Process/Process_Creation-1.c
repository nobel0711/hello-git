#include <stdio.h>
#include <unistd.h>
int main(void)
{
	pid_t childpid;
	printf("c\n");
	childpid = fork();
//	printf("c\n");
	if(childpid == -1)
		perror("Failed to fork\n");
	else if(childpid ==0)
		printf("child, pid:%ld ppid:%ld\n", (long)getpid(), (long)getppid());
	else
		printf("parent, pid:%ld ppid:%ld\n", (long)getpid(), (long)getppid());
	return 0;
}

