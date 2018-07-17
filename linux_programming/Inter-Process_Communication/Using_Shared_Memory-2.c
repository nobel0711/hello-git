#include <stdio.h>
#include <sys/stat.h>
#include <sys/shm.h>
#define N 10
int main(void)
{
	int i;
	int data[N]={1,2,3,4,5,6,7,8,9,10};
	int shmid;
	int childpid;
	//error handling omitted for clarity
	shmid = shmget(IPC_PRIVATE, sizeof(int),             S_IRUSR | S_IWUSR);
	fprintf(stderr, "shmid:%d\n", shmid);
	childpid = fork();
	if(childpid == 0)//child
	{
//		sleep(1);
		int *shmPtr1 = (int*)shmat(shmid, NULL, 0); 
		*shmPtr1 = 0;
		for(i=N/2; i<N; i++)
			*shmPtr1 += data[i];
		shmdt(shmPtr1);
		return 0;
	}
	if(childpid>0)//parent
	{
		int total = 0;
		for(i=0; i<N/2; i++)
			total += data[i];
		//wait(NULL);
		int *shmPtr2 = (int*)shmat(shmid, NULL, 0);
		total += *shmPtr2;
		fprintf(stderr, "total = %d\n", total);
		shmdt(shmPtr2);
		shmctl(shmid, IPC_RMID, NULL);
		return 0;
	}
}//main

