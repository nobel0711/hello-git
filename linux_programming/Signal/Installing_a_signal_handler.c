#include <stdio.h> 
#include <signal.h> 
void ouch(int sig)
{
	printf("OUCH�I �X I got signal %d\n", sig); 
	(void)signal(SIGINT, SIG_DFL);
}
int main()
{
	(void)signal(SIGINT, ouch);
	while(1)
	{
		printf("Hello World!\n");
		sleep(1);
	}
}
