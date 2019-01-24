#include<iostream>
#include<string.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<fstream>
#include<netdb.h>
#include<fcntl.h>
#include<sys/uio.h>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
struct server{
	int length;
	char message[500] = "  ";
}server;
char recv1[2000];
int offset=1;

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		cerr<<"Enter 2 parameters";
		exit(0);
	}

	int port= atoi(argv[1]);
	char msg[1000];
	sockaddr_in servaddr;
	bzero((char*)&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(port);

	int serversd = socket(AF_INET,SOCK_STREAM,0);
	if(serversd < 0)
	{
		cerr<<"Error in server socket"<<endl;
		exit(0);
	}
	int bindstatus = bind(serversd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if(bindstatus < 0)
	{
		cerr<<"Error in binding"<<endl;
		exit(0);
	}
	
	cout<<"Waiting for a client to connect "<<endl;
	listen(serversd,5);
	
	sockaddr_in newsockaddr;
	socklen_t newsockaddrsize = sizeof(newsockaddr);
	
	int newsd =  accept(serversd,(sockaddr *)&newsockaddr,&newsockaddrsize);
	if(newsd < 0)
	{
		cerr<<"Error accepting request from client!"<<endl;
		exit(1);
	}
	cout<<"Connected with client !! "<<endl;
	
	while(1)
	{
		char buffer[1000];
		cout<<"\n\nWaiting for the client response ..."<<endl;
	        int datacount=recv(newsd,(char*)&msg,sizeof(msg),0);
		//cout<<"\n Data Count :  :"<<datacount;
		if(!strcmp(msg,"exit"))
		{
			cout<<"Client has quit the session"<<endl;
			break;
		}
		int i;
		char identifierbyte;
		memcpy(&identifierbyte,&msg[0],sizeof(identifierbyte));

		memcpy(&server,&msg[1],sizeof server);
	        char ser[10];
                sprintf(ser,"%d",server.length);
		memcpy(&buffer,ser,sizeof ser);
		strcat(buffer,server.message);
		cout<<"\n Buffer message :  " <<buffer<<endl;
		int inden = identifierbyte - '0';
		cout<<" Indentifier Byte : " <<identifierbyte<<endl;
		char len[5];	
		if(inden == 1)
		{
			cout<<" length : "<<buffer[inden- 1];
		//	offset++;
		}
		else if(inden == 2)
		{
			cout<<" length :" ;
			for(i=0;i<inden;i++){
				cout<<buffer[i];
		//		offset++;
			}
		}
		else if(inden == 3)
		{
			cout<<" length :";
			for(i=0;i<inden;i++){
				cout<<buffer[i];
		//		offset++;
			}
		}
//		offset = offset+strlen(ser)+strlen(server.message);
//	        cout<<"\n Offset after len : "<<offset;	
		cout<<"\n Message :  ";
//		for(i=offset;i<=strlen(buffer);i++){
//			cout<<buffer[i];
//		}
//		offset = offset+strlen(ser)+strlen(server.message);
//		cout<<"\n Offset : " <<offset;
//		cout<<"\n Identifier  :" <<identifierbyte;
//		cout<<"\n Server msg length : " <<server.length<<endl;
//		cout<<"\n Server message : "<<server.message;
//		for(int i=2;i<strlen(server.message);i++){
//			offset++;
//		}
		strcat(recv1,ser);
		strcat(recv1,server.message);
		if(strlen(ser)>2)
			offset++;

		for(i=offset;i<=strlen(recv1);i++)
			cout<<recv1[i];
		   offset = offset+strlen(ser)+strlen(server.message);
		  cout<<"\n Appended Message : " <<recv1;

		cout<<"\n Offset value : " <<offset;
		cout<<"\n\n **********  ********* "<<endl;
	
	}
	
	cout<<"Connection closed!!"<<endl;
	close(newsd);
	close(serversd);
	return 0;
}
