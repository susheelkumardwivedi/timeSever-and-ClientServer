/*
 * title : timeClient
 * author: susheel kumar dwivedi
 * e-mail: sushilkumar123dwivedi@gmail.com
 * date  : 13/08/2017  dd/mm/yy
 *
 * this program change by anyone for a specific need
 * */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>


int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		fprintf(stderr,"Please provide proper argument\n");
		exit(1);
	}
	struct sockaddr_in client,server;
	int client_socket;
	char recvmsg[100];

	if((client_socket=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("socket:");
		exit(1);
	}
	server.sin_family=AF_INET;
	inet_aton(argv[1],&server.sin_addr);
	server.sin_port=htons(atoi(argv[2]));
	if((connect(client_socket,(struct sockaddr *)&server,sizeof(server)))<0)
	{
		perror("connect:");
		exit(1);
	}
	int recvsize=read(client_socket,recvmsg,sizeof(recvmsg));
	if(recvsize==0)
	{
		fprintf(stderr,"Problem in reading\n");
		exit(1);
	}
	write(1,recvmsg,recvsize);
	printf("\n");
	close(client_socket);
	return 0;
}
