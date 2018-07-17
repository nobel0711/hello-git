#include <stdio.h> 
#include <signal.h> 
#include <time.h> 

void catcher(int sig)
{ 
	printf("inside catcher() function-ALRM\n"); 
} 

int main(int argc, char *argv[])
{ 
	
	struct sigaction sact;
	time_t start, finish; 
	sigset_t new_set, old_set; 
	double diff;
 	
	sigemptyset(&sact.sa_mask); 
	sact.sa_flags = 0; 
	sact.sa_handler = catcher; 
	sigaction(SIGALRM, &sact, NULL); 
	
	sigemptyset(&new_set); 
	sigaddset(&new_set, SIGALRM); 
	sigprocmask(SIG_BLOCK, &new_set, &old_set);

	time(&start);    
	printf("SIGALRM signals blocked at %s\n", ctime(&start)); 

	alarm(1); /* SIGALRM will be sent in 1 second */ 
	do
	{  
		time(&finish); 
		diff = difftime(finish, start); 
	}while(diff < 10); 

	sigprocmask(SIG_SETMASK, &old_set, NULL);
 	printf("SIGALRM signals unblocked at %s\n", ctime(&finish)); 
 	return(0); 
} 

