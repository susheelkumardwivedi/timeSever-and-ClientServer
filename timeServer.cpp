/*
 * title : timeServer
 * author: susheel kumar dwivedi
 * e-mail: sushilkumar123dwivedi@gmail.com
 * date  : 13/08/2017  dd/mm/yy
 *
 * this program change by anyone for a specific need
 * */
#include <stdio.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define BUFFERSIZE 100

int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		fprintf(stderr,"provide <address><port>\n")
		exit(1);
	}
	time_t tick;
	int server_socket,client_socket;
	struct sockaddr_in server,client;
	char hold[BUFFERSIZE];
	int returnValue;
//create a tcp socket
	if((server_socket=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("socket:");
		exit(1);
	}
	bzero(&server,sizeof(server));
	bzero(&client,sizeof(client));
	server.sin_family=AF_INET;
	inet_aton(argv[1],&server.sin_addr);
	server.sin_port=htons(atoi(argv[2]));
//bind server with specified address and port
	if((bind(server_socket,(struct sockaddr *)&server,sizeof(server))<0))
	{
		perror("bind:");
		exit(1);
	}
// listening for incomming connection

	if(listen(server_socket,10)<0)
	{
		perror("listen:");
		exit(1);
	}
	int client_len=sizeof(client);
	printf("Server running with addr :  %s\n using port  %s\n",inet_ntoa(server.sin_addr),argv[2]);
	while(1)
	{
		if((client_socket=accept(server_socket,(struct sockaddr *)&client,(socklen_t *)&client_len))<0)
		{
			perror("accept:");
			exit(1);
		}
		tick=time(NULL);
		snprintf(hold,BUFFERSIZE,"%.24s",ctime(&tick));
		returnValue=write(client_socket,hold,strlen(hold));
		printf("%d bytes send to %s\n",returnValue,inet_ntoa(client.sin_addr));
		close(client_socket);
	}
	close(server_socket);
	return 0;
}
