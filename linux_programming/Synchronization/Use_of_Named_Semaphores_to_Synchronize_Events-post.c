#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
int main(void)
{
	sem_t *sem;
	char *sem_name = "/testsem";
	sem=sem_open(sem_name, O_CREAT, S_IWUSR|S_IRUSR, 0);
	if(sem==SEM_FAILED)
	{
		perror("cannot create sem");
		return -1;
	}
	printf("parent process\n");
	sem_post(sem);
	sem_close(sem);
	return 0;
}

