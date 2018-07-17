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
		perror("usage: udpcli <IPaddress>");
		exit(1);
	}
	sockfd = Socket(PF_INET, SOCK_DGRAM, 0);
	struct timeval tv;
	tv.tv_sec=3;
	tv.tv_usec=0;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = PF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	Inet_pton(PF_INET, argv[1], &servaddr.sin_addr);
	udp_cli_timeout(stdin, sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr), tv);
	//udp_cli(stdin, sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	exit(0);
}

