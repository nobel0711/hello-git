#include <signal.h>
#include <stdio.h>
struct five_words
{
	int a; int b; int c; int d; int e;
} memory;
void handler(int signo)
{
	printf("%d,%d,%d,%d,%d\n", memory.a, memory.b,memory.c, memory.d, memory.e);
	alarm(1);
}
int main(void)
{
	struct five_words zeros = {0,0,0,0,0}, ones={1,1,1,1,1};
	signal(SIGALRM, handler);
	alarm(1);
	while(1)
	{
		memory = zeros;
		memory = ones;
 	}
	return 0;
}

