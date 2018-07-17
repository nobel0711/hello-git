#include <stdio.h>
#include <sys/stat.h>

int main(int arg,char *argv[])
{
//	if(mkdir("abcd", 0777)==-1) 
		perror(NULL); 
	if(rmdir("abcd")==-1) 
		perror(NULL);  
     return 0;
}

