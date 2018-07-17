#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include "mysock.h"
int Socket(int family, int type, int protocol)
{
	int n;
	if((n=socket(family, type, protocol))<0) 
	{
		perror("socket error");
		exit(1);
	}
	return(n);
}
void Listen(int fd, int backlog)
{
	char *ptr;
	/*4can override 2nd argument with environment variable */
	if((ptr=getenv("LISTENQ")) != NULL)
		backlog = atoi(ptr);
	if(listen(fd, backlog)<0)
	{
		perror("listen error");
		exit(1);
	}
}
int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
	int		n;
again:
	if((n = accept(fd, sa, salenptr))<0) {
#ifdef	EPROTO
		if(errno == EPROTO || errno == ECONNABORTED)
#else
		if(errno == ECONNABORTED)
#endif
			goto again;
		else{
			perror("accept error");	exit(1);
		}
	}
	return(n);
}
void Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if(bind(fd, sa, salen)<0)
	{
		perror("bind error"); 
		exit(1);
	}
}
void Connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if(connect(fd, sa, salen) < 0) 
	{
		perror("connect error"); 
		exit(1);
	}
}
void Close(int fd)
{
	if(close(fd) == -1)
	{
		perror("close error"); 
		exit(1);
	}
}
pid_t Fork(void)
{
	pid_t pid;
	if((pid=fork())==-1)
	{
		perror("fork error"); 
		exit(1);
	}
	return(pid);
}
size_t	writen(int fd, const void *vptr, size_t n)
{
	size_t nleft;
	ssize_t nwritten;
	const char *ptr;
	ptr=vptr;
	nleft=n;
	while(nleft>0)
	{
		if((nwritten=write(fd, ptr, nleft))<= 0)
		{
			if (errno == EINTR)
				nwritten = 0; /* and call write() again */
			else
				return(-1); /* error */
		}
		nleft -= nwritten;
		ptr   += nwritten;
	}
	return(n);
}
void Writen(int fd, void *ptr, size_t nbytes)
{
	if(writen(fd, ptr, nbytes)!=nbytes)
	{
		perror("writen error");	
		exit(1);
	}
}
static ssize_t my_read(int fd, char *ptr)
{
	static int	read_cnt = 0;
	static char	*read_ptr;
	static char	read_buf[MAXLINE];
	if (read_cnt <= 0) 
	{
	again:
		if((read_cnt = read(fd, read_buf, sizeof(read_buf))) < 0)
		{
			if(errno == EINTR)
				goto again;
			return(-1);
		}else if(read_cnt==0)
			return(0);
		read_ptr = read_buf;
	}
	read_cnt--;
	*ptr = *read_ptr++;
	return(1);
}
ssize_t readline(int fd, void *vptr, size_t maxlen)
{
	int n, rc;
	char c, *ptr;
	ptr=vptr;
	for(n=1;n<maxlen; n++)
	{
		if((rc=my_read(fd, &c))==1)
		{
			*ptr++ = c;
			if (c == '\n')
				break;	/* newline is stored, like fgets() */
		}else if (rc == 0)
			{
				if (n == 1)
					return(0);	/* EOF, no data read */
				else
				break;		/* EOF, some data was read */
		}else
			return(-1);		/* error, errno set by read() */
	}
	*ptr = 0;	/* null terminate like fgets() */
	return(n);
}
ssize_t Readline(int fd, void *ptr, size_t maxlen)
{
	ssize_t n;
	if((n=readline(fd, ptr, maxlen))<0)
	{
		perror("readline error"); 
		exit(1);
	}
	return(n);
}
void str_echo(int sockfd)
{
	ssize_t	n;
	char line[MAXLINE];
	for(;;)
	{
		if((n=Readline(sockfd, line, MAXLINE))==0)
			return;		/* connection closed by other end */
		Writen(sockfd, line, strlen(line));
	}
}
char *Fgets(char *ptr, int n, FILE *stream)
{
	char *rptr;
	if((rptr=fgets(ptr, n, stream))==NULL&&ferror(stream))
	{
		perror("fgets error"); 
		exit(1);
	}
	return (rptr);
}
void Fputs(const char *ptr, FILE *stream)
{
	if(fputs(ptr, stream)==EOF)
	{
		perror("fputs error"); 
		exit(1);
	}
}
void str_cli(FILE *fp, int sockfd)
{
	char	sendline[MAXLINE], recvline[MAXLINE];
	while (Fgets(sendline, MAXLINE, fp) != NULL)
	{
		Writen(sockfd, sendline, strlen(sendline));
		if (Readline(sockfd, recvline, MAXLINE) == 0)
		{
			perror("str_cli: server terminated prematurely"); 
			exit(1);
		}
		Fputs(recvline, stdout);
	}
}
void Inet_pton(int family, const char *strptr, void *addrptr)
{
	int n;
	if((n=inet_pton(family, strptr, addrptr)) < 0)
	{
		perror("inet_pton error"); 
		exit(1);
	}
	else if(n==0)
	{
		perror("inet_pton error"); 
		exit(1);
	}
}
void sig_chld(int signo)
{
	pid_t	pid;
	int	stat;
	while((pid = waitpid(-1, &stat, WNOHANG))>0)
		printf("child %d terminated\n", pid);
	return;
}
Sigfunc *Signal(int signo, Sigfunc *func)	/* for our signal() function */
{
	Sigfunc	*sigfunc;
	if((sigfunc=signal(signo, func))==SIG_ERR)
	{
		perror("signal error");
		exit(1);
	}
	return(sigfunc);
}
ssize_t Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
		 struct sockaddr *sa, socklen_t *salenptr)
	{
	ssize_t	n;
	if((n=recvfrom(fd, ptr, nbytes, flags, sa, salenptr))<0)
	{
  		perror("recvfrom error"); 
		exit(1);
	}
	return(n);
}
void Sendto(int fd, const void *ptr, size_t nbytes, int flags,
	   const struct sockaddr *sa, socklen_t salen)
{
	if(sendto(fd, ptr, nbytes, flags, sa, salen)!=nbytes)
	{
		perror("sendto error"); 
		exit(1);
	}
}
void udp_echo(int sockfd, struct sockaddr *pcliaddr, socklen_t clilen)
{
	int		n;
	socklen_t	len;
	char		mesg[MAXLINE];
	for(;;)
	{
		len = clilen;
		n = Recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);
		Sendto(sockfd, mesg, n, 0, pcliaddr, len);
	}
}
void udp_cli(FILE *fp, int sockfd, struct sockaddr *pservaddr, socklen_t servlen)
{
	int	n;
	char	sendline[MAXLINE], recvline[MAXLINE + 1];
	while(Fgets(sendline, MAXLINE, fp) != NULL) 
	{
		Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);
		n = Recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);
		recvline[n] = 0;	/* null terminate */
		Fputs(recvline, stdout);
	}
}
void udp_cli_timeout(FILE *fp, int sockfd, struct sockaddr *pservaddr, socklen_t servlen, struct timeval tv)
{
	int	n;
	char	sendline[MAXLINE], recvline[MAXLINE + 1];
	setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
	while(Fgets(sendline, MAXLINE, fp) != NULL)
	{
		Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);
		n = recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);
		if(n<0)
		{
			if(errno==EAGAIN || errno==EWOULDBLOCK)
				fprintf(stderr, "recvfrom() timeout\n");
			else
				perror("recvfrom error\n");
			exit(1);
		}
		recvline[n] = 0;	/* null terminate */
		Fputs(recvline, stdout);
	}
}

