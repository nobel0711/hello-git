#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *path=getenv("USER");
	if(path)
		printf("PATH:%s\n",path);
	return 0;
}
//echo $PATH


