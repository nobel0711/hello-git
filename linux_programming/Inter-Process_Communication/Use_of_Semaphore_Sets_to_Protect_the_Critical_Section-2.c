#include <sys/sem.h>
//error handling omitted for clarity
int initelement(int semid, int semnum, int semvalue)
{
	union semun {
		int val;
		struct semid_ds *buf;
		unsigned short *array;
	} arg;
	arg.val = semvalue;
	return semctl(semid, semnum, SETVAL, arg);
}
void setsembuf(struct sembuf *s, int num, int op, int flg)
{
	s->sem_num = (short)num;
	s->sem_op = (short)op;
	s->sem_flg = (short)flg;
	return;
}

