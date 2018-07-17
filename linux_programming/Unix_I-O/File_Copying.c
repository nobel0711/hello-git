#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024
int main(int argc, char **argv)
{
	char *buffer = (char *)malloc(BUFFER_SIZE);
	int input_fd, output_fd;
	int amt_read = BUFFER_SIZE;
	if(argc != 3)
	{
		printf("Usage: input_file output_file\n");
		return 0;
	}
	if(buffer == NULL)
	{
		perror("Couldn't create buffer");
		return -1;
	}
	input_fd = open(argv[1], O_RDONLY);
	output_fd = open(argv[2], O_WRONLY |O_CREAT |O_TRUNC);
	if(input_fd < 0 || output_fd < 0)
	{
		perror("Couldn't open files");
		return -1;
	}
	while((amt_read = read(input_fd, buffer, amt_read)) > 0)
	{
		write(output_fd, buffer, amt_read);
		amt_read = BUFFER_SIZE;
	}
	close(input_fd);
	close(output_fd);
	free(buffer);
	return 0;
}

