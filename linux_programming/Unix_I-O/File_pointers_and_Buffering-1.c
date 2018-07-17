#include <stdio.h>
int main(void)
{
	fprintf(stdout, "a");
	fprintf(stderr, "b");
	fprintf(stdout, "c");
	fprintf(stderr, "d");
	fprintf(stdout, "\n");
	return 0;
}

