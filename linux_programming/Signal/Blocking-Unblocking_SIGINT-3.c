#include <stdio.h> 
#include <signal.h> 
#include <time.h> 

void catcher(int sig)
{ 
	printf("inside catcher() function-ALRM\n"); 
} 

void catcher2(int sig)
{ 
	printf("inside catcher() function-STOP\n"); 
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
	
	sact.sa_handler = catcher2; 
	sigaction(SIGTSTP, &sact, NULL); 


	sigemptyset(&new_set); 
	sigaddset(&new_set, SIGTSTP);
	sigaddset(&new_set, SIGALRM); 

	time(&start);    
	printf("SIGALRM signals blocked at %s\n", ctime(&start)); 
	sigprocmask(SIG_BLOCK, &new_set, &old_set);

	sleep(3);
	printf("aaa");
	alarm(1); /* SIGALRM will be sent in 1 second */ 
	do
	{  
		printf("bbb\n");
		sleep(3);
		time(&finish); 
		diff = difftime(finish, start); 
	}while(diff < 8); 

	sigprocmask(SIG_SETMASK, &old_set, NULL);
 	printf("SIGALRM signals unblocked at %s\n", ctime(&finish)); 
 	return(0); 
} 

