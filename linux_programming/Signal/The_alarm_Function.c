#include <unistd.h>
#include <signal.h>
#include <stdio.h>
void alarm_handler(int signo)
{
	raise(SIGKILL);
	//printf("aaaa");
	//exit(0);
}
int main(void)
{
	char buffer[128];
	signal(SIGALRM, alarm_handler);
	printf("You have 5 seconds to enter the password : ");
	alarm(5);
	fgets(buffer, 128, stdin);
	alarm(0); 
	printf("You've entered %s", buffer);
	return 0;
}

