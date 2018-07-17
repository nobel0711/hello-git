#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
		printf("Running PS with execlp\n");
		execlp("ps", "ps", "-ax",  (char *)0);
		printf("Done\n");
		exit(0);
}

