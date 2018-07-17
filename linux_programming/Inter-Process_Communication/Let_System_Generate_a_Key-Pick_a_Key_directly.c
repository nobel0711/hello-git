#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
int main(void)
{
	int shmid=-1;
	int shm_size=100;
	// let system pick a key
//	if((shmid=shmget(IPC_PRIVATE, shm_size, S_IRUSR | S_IWUSR | IPC_CREAT)) == -1)
	// pick a key directly
	if((shmid=shmget(123457, shm_size, S_IRUSR | S_IWUSR | IPC_CREAT)) == -1)
		perror("Failed to create shared memory");
	fprintf(stderr,"Shared memory id: %d\n", shmid);

	return 0;
}

