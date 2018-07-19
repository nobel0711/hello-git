#define	MAXLINE 4096
int Socket(int family, int type, int protocol);
void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
void sig_chld(int);
typedef void Sigfunc(int);
int Socket(int family, int type, int protocol);
void Listen(int fd, int backlog);
int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
void Connect(int fd, const struct sockaddr *sa, socklen_t salen);
void Close(int fd);
pid_t Fork(void);
size_t writen(int fd, const void *vptr, size_t n);
void Writen(int fd, void *ptr, size_t nbytes);
ssize_t readline(int fd, void *vptr, size_t maxlen);
ssize_t Readline(int fd, void *ptr, size_t maxlen);
void str_echo(int sockfd);
char *Fgets(char *ptr, int n, FILE *stream);
void Fputs(const char *ptr, FILE *stream);
void str_cli(FILE *fp, int sockfd);
void Inet_pton(int family, const char *strptr, void *addrptr);
void sig_chld(int signo);
Sigfunc *Signal(int signo, Sigfunc *func);
ssize_t Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
		 struct sockaddr *sa, socklen_t *salenptr);
void Sendto(int fd, const void *ptr, size_t nbytes, int flags,
	   const struct sockaddr *sa, socklen_t salen);
void udp_echo(int sockfd, struct sockaddr *pcliaddr, socklen_t clilen);
void udp_cli(FILE *fp, int sockfd, struct sockaddr *pservaddr, socklen_t servlen);
void udp_cli_timeout(FILE *fp, int sockfd, struct sockaddr *pservaddr, socklen_t servlen, struct timeval tv);
