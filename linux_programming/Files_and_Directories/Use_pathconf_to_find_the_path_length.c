#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
	long maxpath;
	char *pcwd;
	if((maxpath=pathconf("/", _PC_PATH_MAX))==-1) 
	{
		perror("pathconf");
		return 1;
	}
	if((pcwd=(char*)malloc(maxpath))==NULL)
	{
		perror("malloc");
		return 1;
	}
	if(getcwd(pcwd, maxpath)==NULL) 
	{
		perror("getcwd");
		return 1;
	}
	printf("current working directory : %s\n", pcwd);
	free(pcwd);
	return 0;
}

