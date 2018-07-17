#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#define SERV_PORT 9877
#define LISTENQ 1024
int main(int argc, char **argv)
{
	int sockfd;
	struct sockaddr_in cliaddr, servaddr;
	sockfd = Socket(PF_INET, SOCK_DGRAM, 0);
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = PF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	Bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	udp_echo(sockfd, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
	return 0;
}

