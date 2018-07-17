#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
void sigroutine(int signo)
{
        printf("Catch a signal -- SIGALRM \n");
        return;
}

int main()
{
   struct itimerval value, ovalue;
   printf("process id is %d\n", getpid());
   signal(SIGALRM, sigroutine);
   value.it_value.tv_sec = 1;
   value.it_value.tv_usec = 0;
   value.it_interval.tv_sec =0;
   value.it_interval.tv_usec = 500000;
   setitimer(ITIMER_REAL, &value, &ovalue);
   for(;;)
   ;
}

