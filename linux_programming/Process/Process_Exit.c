#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void foo1(void);
void foo2(void);
int main(void)
{
	if(atexit(foo1))
		printf("cannot register foo1()\n");
	if(atexit(foo1))
		printf("cannot register foo1()\n");
	if(atexit(foo2))
		printf("cannot register foo2()\n");
	return 0;
	//_exit(0);
	//exit(0);
}
void foo1(void)
{
	printf("foo1()\n");
}
void foo2(void)
{
	printf("foo2()\n");
}

