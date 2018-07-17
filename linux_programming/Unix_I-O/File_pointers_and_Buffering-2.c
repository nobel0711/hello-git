#include <stdio.h>
#include <unistd.h>
int main(void)
{
	fprintf(stdout, "fprintf1\n");
	write(STDOUT_FILENO, "write", 6);
	fork();
	return 0;
}

