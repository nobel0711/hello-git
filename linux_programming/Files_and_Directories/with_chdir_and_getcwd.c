#include <stdio.h>
#include <unistd.h>
#ifndef PATH_MAX
#define PATH_MAX 255
#endif
int main(void)
{    
	char mycwd[PATH_MAX];    
	if(getcwd(mycwd, PATH_MAX) == NULL)    
	{        
		perror("Failed to get current working directory : ");
		return -1;    
	}    
	printf("cwd : %s\n", mycwd);   
	chdir("../"); //error handling omitted    
	getcwd(mycwd, PATH_MAX); //error handling omitted    
	printf("cwd : %s\n", mycwd);    
	return 0;
}

