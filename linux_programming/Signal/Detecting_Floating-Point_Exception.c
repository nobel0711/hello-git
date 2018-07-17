#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fenv.h>
void recvFPE(int signo)
{
	printf("floating point exception\n");
	exit(1);
}
int main(int argc, char *argv[])
{
	//error handling omitted for clarity
	if(argc !=3)
	{
		printf("usage : program i j\n");
		return 0;
	}
	feenableexcept(FE_DIVBYZERO);
	signal(SIGFPE, recvFPE);
	float a,b;
	if(1!=sscanf(argv[1], "%f", &a))
		return -1;
	if(1!=sscanf(argv[2], "%f", &b))
		return -1;
	printf("%f / %f = %f\n", a, b, a/b);
	return 0;
}//gcc -lm ...

