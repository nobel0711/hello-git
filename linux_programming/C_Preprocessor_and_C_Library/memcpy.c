#include <stdio.h>
#include <string.h>
#define N 6
int main(void)
{
	int i;
	int source[N]={1,3,5,7,9,11};
	int target[N];

	memcpy(target, source, N*sizeof(int));

	for(i=0; i<N; i++)
		printf("%d ", target[i]);
	fputc('\n', stdout);
	return 0;
}

