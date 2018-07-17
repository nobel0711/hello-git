#include <signal.h> 
#include <unistd.h> 
#include <stdio.h> 

void catcher(int sig) 
{ 
	puts("inside catcher() function\n"); 
} 

void check_pending(int sig, char *signame) 
{ 
	sigset_t sigset; 
	if(sigpending(&sigset) != 0) 
		perror("sigpending() error\n" );
	else if(sigismember(&sigset, sig))
		printf("a %s signal is pending\n", signame); 
	else 
		printf("no %s signals are pending\n", signame); 
} 

int main(int argc, char *argv[]) 
{ 
	struct sigaction sigact; 
	sigset_t sigset;
	sigemptyset( &sigact.sa_mask); 
	sigact.sa_flags = 0; 
	sigact.sa_handler = catcher; 
	if(sigaction(SIGUSR1, &sigact, NULL) != 0) 
		perror("sigaction() error\n"); 
	else 
	{ 
		sigemptyset(&sigset); 
		sigaddset(&sigset, SIGUSR1);
 		if(sigprocmask(SIG_SETMASK, &sigset, NULL) != 0) 
			perror("sigprocmask() error\n");
		else
		{ 
			printf("SIGUSR1 signals are now blocked\n"); 
			kill(getpid(), SIGUSR1); 
			printf("after kill()\n");
			check_pending(SIGUSR1, "SIGUSR1");
			sigemptyset(&sigset); 
			sigprocmask(SIG_SETMASK, &sigset, NULL); 
			printf("SIGUSR1 signals are no longer blocked\n"); 
			check_pending( SIGUSR1, "SIGUSR1"); 
		} 
	} 
	return(0); 
} 


