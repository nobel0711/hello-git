#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#define BUFSIZE 10
int main(void)
{
        int childpid;
        char fifo_name[]="./myfifo1";
        char buf[]="ccccc";
        int fd;
        if((fd=open(fifo_name, O_WRONLY)) == -1)
        {
                perror("cannot open fifo for writing");
                return 0;
        }
        write(fd, buf, strlen(buf));
        while(1);
        return 0;
}

