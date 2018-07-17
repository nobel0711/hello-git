#include <stdio.h>
#include <signal.h>
int main(void)
{
	sigset_t intmask, oldmask;
	sigemptyset(&intmask);
	sigaddset(&intmask, SIGINT);
	for(;;)
	{
		sigprocmask(SIG_BLOCK, &intmask, &oldmask);
		char ch='a'-1;
		while(ch++!='z')
		{
			fputc(ch, stderr);
			int i;
			for(i=0; i<20000000; i++) ;
		}
		fputc('\n', stderr);
		sigprocmask(SIG_SETMASK, &oldmask, NULL);
	}
	return 0;
}

