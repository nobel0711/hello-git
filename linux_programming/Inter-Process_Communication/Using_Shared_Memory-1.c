#include <stdio.h>
#include <sys/stat.h>
#include <sys/shm.h>
int main(void)
{
	int shmid; int childpid;
	//error handling omitted for clarity
	shmid = shmget(IPC_PRIVATE, sizeof(int), S_IRUSR | S_IWUSR);
	fprintf(stderr, "shmid:%d\n", shmid);
	childpid = fork();
	if(childpid == 0) 
	{//child
		sleep(3);
		int *shmPtr1 = (int*)shmat(shmid, NULL, 0);
		srand(time(NULL));
		(*shmPtr1) = rand();
		shmdt(shmPtr1);
		return 0;
	}
	if(childpid>0) 
	{ //parent
	
		wait(NULL);
		int *shmPtr2 = (int*)shmat(shmid, NULL, 0);
		fprintf(stderr, "rand()=%d\n", (*shmPtr2));
		shmdt(shmPtr2);
		shmctl(shmid, IPC_RMID, NULL);
//		wait(NULL);
		return 0;
	}
}

