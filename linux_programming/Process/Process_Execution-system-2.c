#include <stdlib.h> 
#include <stdio.h>
int  main()
{
	printf("Running ps rith system\n");
	system("ps -ax &");
	printf("Done.\n");
	exit (0);
}

