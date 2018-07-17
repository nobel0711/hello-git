#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>

int counttime=0;
void alarm_handler(int signo)
{
	counttime++;
	fprintf(stderr,"counttime:%d\n",4-counttime);
}

void go_handler(int signo)
{
	fprintf(stderr, "pid:%ld running.\n", (long)getpid());
}


int main(void)
{
	int i, n=10,rank=0,randnumber=0,distance=0,levelnumber=0;
	pid_t childpid, callpid;	
	pid_t horsepid[10];

	signal(SIGALRM, alarm_handler);
	signal(SIGUSR1, go_handler);

	for(i=1; i<=n; i++){

		horsepid[i-1] = childpid = fork();
		if(childpid <= 0)
			break;
		printf("Horse%d=%ld\n", i, (long)childpid);
	}
	
	if(childpid){

		fprintf(stderr,"----------CountDown----------\n");

		while(counttime<3){
			alarm(1);
			sleep(1);
		}
	
		fprintf(stderr,"--------Running Time----------\n");
		alarm(0);

		for(i=1; i<=n; i++)
			kill(horsepid[i-1],SIGUSR1);	

		while((callpid=wait(NULL))!=-1)
			printf("rank:%d pid:%ld\n", ++rank, (long)callpid);
	}
	else{
		pause();
		while(distance<100){
			srand(getpid()*time(NULL));
			randnumber=(rand() % 10) +1;
			distance+=randnumber;
			//printf("pid:%ld distance=%d\n", (long)getpid(), distance);
			usleep(500000);
		}
	}
	return 0;
}
