#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#define BUFSIZE 10
int main(void)
{
        int childpid;
        char fifo_name[]="./myfifo1";
 	if(mkfifo(fifo_name, S_IRUSR | S_IWUSR) ==-1 &&  errno!=EEXIST)
        {
               	 perror("cannot create fifo");
               	 return 1;
       	}
        char buf[BUFSIZE]="ppppp";
        int fd;
        if((fd=open(fifo_name, O_RDONLY)) == -1)
        {
                perror("cannot open fifo for reading");
                return 0;
        }
        printf("%s\n", buf);
        read(fd, buf, BUFSIZE);
        printf("%s\n", buf);
	return 0;
}

