#include <stdio.h> 
#include <signal.h> 
#include <time.h> 
void catcher(int sig) 
{ 
	printf("inside catcher() function\n"); 
} 
void timestamp(char *str) 
{ 
	time_t t; 
	time(&t); 
	printf("%s the time is %s\n", str, ctime(&t)); 
} 
int main(int argc, char *argv[]) 
{ 
	sigset_t block_set; 
	sigfillset(&block_set); 
	sigdelset(&block_set, SIGALRM); 

	struct sigaction sigact;   
	sigact.sa_handler = catcher; 
	sigemptyset(&sigact.sa_mask); 
	sigact.sa_flags = 0; 
	sigaction(SIGALRM, &sigact, NULL);

	timestamp("before sigsuspend()");    
	alarm(10); 
	sigsuspend(&block_set);    
	timestamp("after sigsuspend()");
	return(0); 
} 

