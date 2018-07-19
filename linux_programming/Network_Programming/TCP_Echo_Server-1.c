///singal way
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#define RECV_PORT 9877
#define SEND_PORT 9878
#define LISTENQ 1024
int main(int argc, char **argv)
{

	int listenfd, connfd;

		socklen_t clilen;
		struct sockaddr_in cliaddr, servaddr;
		listenfd = Socket(PF_INET, SOCK_STREAM, 0);
		memset(&servaddr, 0, sizeof(servaddr));
		servaddr.sin_family = PF_INET;
		servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
		servaddr.sin_port = htons(RECV_PORT);
		Bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
		Listen(listenfd, LISTENQ);
		for ( ; ; ) 
		{
			clilen = sizeof(cliaddr);
			connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
			str_echo(connfd);
			Close(connfd);
		} // for
}

