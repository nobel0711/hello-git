#include <stdio.h>
#include <unistd.h>
int main(void)
{
	printf("process id : %ld\n", (long)getpid());
	printf("parent id : %ld\n", (long)getppid());
	return 0;
}

