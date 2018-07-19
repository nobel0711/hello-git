#include <stdlib.h>
#include <netdb.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	struct servent *serv;
	if(argc < 3) 
	{
		puts("Incorrect parameters. Use: service-name protocol-name ");
		return EXIT_FAILURE;
	}
	serv = getservbyname(argv[1], argv[2]);
	if(serv == NULL) 
	{
		printf("Service %s not found for protocol %s\n", argv[1], argv[2]);
		return EXIT_FAILURE;
	}
	printf("Name: %-15s  Port: %5d    Protocol: %-6s\n", serv->s_name,ntohs(serv->s_port),serv->s_proto);
	return EXIT_SUCCESS;
}


