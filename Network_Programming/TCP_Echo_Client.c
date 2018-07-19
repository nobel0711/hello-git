#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SERV_PORT 9877
int main(int argc, char **argv)
{
	int sockfd;
	struct sockaddr_in servaddr;
	if(argc != 2) 
	{
		perror("usage: tcpcli <IPaddress>");
		exit(1);
	}
	sockfd = Socket(PF_INET, SOCK_STREAM, 0);
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = PF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	Inet_pton(PF_INET, argv[1], &servaddr.sin_addr);
	Connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	str_cli(stdin, sockfd);
	exit(0);
}


