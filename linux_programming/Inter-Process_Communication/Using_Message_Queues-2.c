#include <stdio.h>
#include <sys/stat.h>
#include <sys/msg.h>
typedef struct mymsg1 
{
	long type;
	double average;
	int test;
} MyMsg1;
typedef struct mymsg2
{
	long type;
	int sum;
} MyMsg2;
#define N 10
int main(void)
{
	int i;
	int queueid;
	int childpid;
	int data[N]={1,2,3,4,5,6,7,8,9,10};
	//error handling omitted for clarity
	queueid = msgget(IPC_PRIVATE, S_IRUSR | S_IWUSR);
	fprintf(stderr, "shmid:%d\n", queueid);
	childpid = fork();
	if(childpid == 0) 
	{ //child
		sleep(1);
		MyMsg1 mymsg1; MyMsg2 mymsg2;
		double average;
		int sum = 0;
		for(i=0; i<N; i++)
		sum += data[i];
		average = sum/(double)N;
		mymsg1.type = 1; mymsg1.average = average; mymsg1.test=10;
		mymsg2.type = 2; mymsg2.sum = sum;
		msgsnd(queueid, &mymsg1,sizeof(MyMsg1)-sizeof(long), 0);
		msgsnd(queueid, &mymsg2,sizeof(MyMsg2)-sizeof(long), 0);
		return 0;
	}
	if(childpid>0) 
	{ //parent
		//wait(NULL);
		MyMsg1 mymsg1; MyMsg2 mymsg2;
		int recv;
		msgrcv(queueid, &mymsg2,sizeof(MyMsg2)-sizeof(long), 1, 0);
		msgrcv(queueid, &mymsg1,sizeof(MyMsg1)-sizeof(long), 2, 0);
		fprintf(stderr, "sum=%d average=%.1f test=%d\n",
		mymsg2.sum, mymsg1.average, mymsg1.test);
		msgctl(queueid, IPC_RMID, NULL);
		return 0;
	}
}//main

