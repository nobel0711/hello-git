#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	switch(fork())
	{
		case -1:
			perror("Fork error");
			return -1;
				
		case 0:
			execlp("hostname", "hostname", (char *) 0);
			return 0;
			
		default:
			execlp("hostname", "hostname", (char *) 0);
			printf("You will never see this\n");
	}
	return 0;
}

