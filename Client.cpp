#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>
using namespace std;

struct client{
int length;
char message[500]=" ";
}client,client1;
int clientsd,length;
char buffer[1000];
void connect();

int main(int argc, char *argv[])
{
	if(argc !=  3 )
	{
		cerr<<"Enter 3 Paramters"<<endl;
		exit(0);
	}
	char *serverip = argv[1];
	int port = atoi(argv[2]);

	struct hostent* host = gethostbyname(serverip);
    sockaddr_in sendsockaddr;
    bzero((char*)&sendsockaddr, sizeof(sendsockaddr));
    sendsockaddr.sin_family = AF_INET;
    sendsockaddr.sin_addr.s_addr=
	    inet_addr(inet_ntoa(*(struct in_addr*)*host->h_addr_list));
    sendsockaddr.sin_port = htons(port);
     clientsd = socket(AF_INET, SOCK_STREAM, 0);
    //try to connect...
    int status = connect(clientsd,
                         (sockaddr*) &sendsockaddr, sizeof(sendsockaddr));

	if(status < 0)
	{
		cout<<"Error connecting to socket"<<endl;
		exit(0);
	}
	cout<<"Connected to the server! "<<endl;

	connect();
return 0 ;
}

void connect()
{
	while(1)
	{

		cout<<"\nEnter message : "<<endl;
		cout<<">";
		cin>>client.message;
		client.length = strlen(client.message);
		char iden[10];
		int i,count = client.length;
		for( i=0 ; count>0 ;i++)
		{
			count = count/10;
		}		
		sprintf(iden,"%d",i);
		cout<<"\n Value of I :  " <<i<<endl;
		
		memcpy(buffer,iden,sizeof iden);
		memcpy(buffer+1,(char*)&client,sizeof(client));
		cout<<"Message Sent !! "<<endl;
		string data = buffer;	
		strcpy(buffer,data.c_str());
	
		if(data == "exit")
		{
			send(clientsd,(char*)&buffer,sizeof(buffer),0);
			break;
		}

		send(clientsd,(char*)&buffer,sizeof(buffer),0);
		

	}

}
