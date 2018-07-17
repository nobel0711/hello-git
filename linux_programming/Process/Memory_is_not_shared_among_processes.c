#include <stdio.h>
#include <unistd.h>
int g_x=5;
int main(void)
{
	int x=7;
	pid_t childpid;
	childpid = vfork();
	if(childpid == -1)
		perror("Failed to fork\n");
	else if(childpid == 0) 
	{
		g_x++;
		x++;
	}
//	else
//		sleep(1);
	printf("g_x:%d x:%d\n", g_x, x);
	return 0;
}

