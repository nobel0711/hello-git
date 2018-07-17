#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
        int fd = open("output", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        if(fd < 0)
        {
		perror("Opening the file failed");
		return -1;
        }
        if(dup2(fd, 1) < 0)
        {
		perror("Dup failed");
		return -1;
        }
        printf("This will be printed to the file instead of the screen\n");
        close(fd);
        return 0;
}

