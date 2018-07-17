#include <stdio.h>
#include <signal.h>
void alarm_handler(int signo)
{
        printf("%d\n", time(NULL));
}
int main(void)
{
        signal(SIGALRM, alarm_handler);
        ualarm(500000, 100000);
        while(1)
             ;
        return 0;
}

