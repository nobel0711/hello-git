#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
	int i, n=10,rank=0,randnumber=0,distance=0; 
	pid_t childpid,callpid;
	for(i=1; i<=n; i++)
	{
		childpid = fork();
		if(childpid <= 0)
			break;
		printf("Horse%d=%ld\n", i, (long)childpid);
	}

	if(childpid){
		while((callpid=wait(NULL))!=-1)
			printf("rank:%d pid:%ld\n", ++rank, (long)callpid);
	}
	else{
		while(distance<100){
			srand(getpid());
			randnumber=(rand() % 10) +1;
			distance+=randnumber;
			//printf("distance=%d\n",distance);
			//sleep(1);
			usleep(10000);
		}
	}
	return 0;
}

