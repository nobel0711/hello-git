#include <stdio.h>
#include <dirent.h>
int main(int argc, char *argv[])
{
	struct dirent *direntp;    
	DIR *dirp;    
	if(argc != 2) 
	{        
		fprintf(stderr, "Usage : %s dir\n", argv[0]);        
		return 1;    
	}   
	//error handling omitted
	dirp = opendir(argv[1]);        
	while(direntp=readdir(dirp))        
		printf("%s\n", direntp->d_name);        
	closedir(dirp);        
	return 0;
}

