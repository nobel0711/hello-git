#include <stdio.h>
#include <sys/stat.h>
#include <sys/msg.h>
typedef struct mymsg 
{
	long type;
	int randnum;
} MyMsg;
int main(void) 
{
	int queueid; int childpid;
	//error handling omitted for clarity
	queueid = msgget(IPC_PRIVATE, S_IRUSR | S_IWUSR);
	fprintf(stderr, "queueid:%d\n", queueid);
	childpid = fork();
	if(childpid == 0)
	{ //child
//		sleep(1);
		MyMsg mymsg1;
		srand(time(NULL));
		mymsg1.type = 1;
		mymsg1.randnum = rand()%100;
		msgsnd(queueid, &mymsg1, sizeof(MyMsg), 0);
//		sleep(1);
		return 0;
	}
	if(childpid>0) 
	{ //parent
		MyMsg mymsg2;
		msgrcv(queueid, &mymsg2, sizeof(MyMsg), 1, 0);
		fprintf(stderr, "rand()=%d\n" , mymsg2.randnum);
		msgctl(queueid, IPC_RMID , NULL);
		wait(NULL);
		return 0;
	}
}//main

