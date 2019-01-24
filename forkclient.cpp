#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<iostream>

#define PORT 8880

using namespace std;
int main()
{
	int clientsocket,ret;
	struct sockaddr_in sockaddress;
	char msg[1000];

	clientsocket = socket(AF_INET,SOCK_STREAM,0);
	if(clientsocket<0)
	{
		cerr<<"\n Error in connection";
		exit(1);
	}

	cout<<"\n Client socket is created";

	memset(&sockaddress,'\0',sizeof(sockaddress));
	sockaddress.sin_family = AF_INET;
	sockaddress.sin_port=htons(PORT);
	sockaddress.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = connect(clientsocket,(struct sockaddr*)&sockaddress,sizeof(sockaddress));

	if(ret<0)
	{
		cerr<<"\n Error in connection ";
		exit(1);
	}
	cout<<"\n Connected to the server ";

	while(1)
	{
		cout<<"\n Client : ";
		cin>>msg;
		send(clientsocket,msg,strlen(msg),0);

		if(strcmp(msg,":exit")==0)
		{
			close(clientsocket);
			cout<<"\n Disconnected from the server ";
			exit(1);
		}

		if(recv(clientsocket,msg,1000,0)<0)
			cout<<"\n Error in receiving data";
		else
			cout<<"\n Server  : "<<msg;
	}
	return 0;

}
