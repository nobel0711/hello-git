#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd, nread;
    char buf[1024];  
    /*open file "data" for reading */
    fd = open("data", O_RDONLY);

    /* read in the data */
    nread = read(fd, buf, 1024);
    printf("%s",buf); 
    /* close the file */
    close(fd);
}

