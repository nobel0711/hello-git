#include <stdio.h>
#include <errno.h>
#include <sys/shm.h>
#include <sys/stat.h>
int main(void) 
{
	key_t mykey;
	char key_path[]="/root/";
	int id=123;
	if((mykey=ftok(key_path,id))==(key_t)-1) 
	{
		fprintf(stderr,"Failed to derive key from %s: %d\n",	key_path, strerror(errno));
		return -1;
	}
	fprintf(stderr, "Derived key is %lu\n", (unsigned long)mykey);
	int shmid=-1;
	int shm_size=100;
	if((shmid=shmget(mykey, shm_size, S_IRUSR | S_IWUSR | IPC_CREAT)) == -1)
		perror("Failed to create shared memory");
	fprintf(stderr,"Shared memory id: %d\n", shmid);
	return 0;
}

