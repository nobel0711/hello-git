#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
int main(void)
{
	sem_t *sem;
	char *sem_name = "testsem";
	sem=sem_open(sem_name, O_CREAT, S_IWUSR|S_IRUSR, 0);
	if(sem==SEM_FAILED)
	{
		perror("cannot create sem");
		return -1;
	}
	pid_t pid=fork();
	if(pid==-1)
		perror("cannot fork ");
	if(pid==0) /* child process */
	{
		sem_wait(sem);
		sem_close(sem);
		printf("child process\n");
		return 0;
	}
	else
	{
		sleep(3);
		printf("parent process\n");
		sem_post(sem);
		sem_close(sem);
		wait(NULL);
		int ret =sem_unlink(sem_name);
		if(ret==-1)
			perror("error");
		return 0;
	}
}

