#include<iostream>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#define PORT 8880

using namespace std;
int main()
{
	int CHUNK_SIZE =5;
//	char chunk[CHUNK_SIZE];
	static int total_size = 0;
	int size_recv;
	int sockfd,ret;
	struct sockaddr_in sockaddress;

	int newsocket;
	struct sockaddr_in newaddr;

	socklen_t addr_size;

	char msg[CHUNK_SIZE],buffer[1000];
	pid_t childid;

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	if(sockfd < 0){
		cerr<<"Error in connection !!";
		exit(0);
		}
	
	cout<<"Socket created !!";

	memset(&sockaddress,'\0',sizeof(sockaddress));
	sockaddress.sin_family = AF_INET;
	sockaddress.sin_port = htons(PORT);
	sockaddress.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = bind(sockfd,(struct sockaddr*)&sockaddress,sizeof(sockaddress));
	if(ret<0)
	{
		cerr<<"\n Error in binding";
		exit(1);
	}

	cout<<"\nBinded !!";

	if(listen(sockfd,10)==0)
		cout<<"\n Listening:";
	else
		cout<<"\n Error in listening";

bzero(buffer,0);
	while(1)
	{
		newsocket = accept(sockfd,(struct sockaddr*)&newaddr,&addr_size);
		if(newsocket < 0 ){
			cerr<<"Connection failed !!";
			exit(1);
		}

		cout<<"\n Connection accepted from : "<<inet_ntoa(newaddr.sin_addr)<<"  " <<ntohs(newaddr.sin_port);
		if((childid=fork())==0)
		{
			close(sockfd);
			while(1){
				cout<<"\n Awaiting for client response ...."<<endl;
				memset(&msg,0,CHUNK_SIZE); //clear the buffer 
				
					
					size_recv = recv(newsocket,(char*)&msg,CHUNK_SIZE,0);
					//cout<<"\n"<<size_recv<<endl;
					strcat(buffer,msg);

				
				if(size_recv>0){
					total_size += size_recv;
					cout<<"Client : "<<msg;
				}
				else
					break;
			
				cout<<buffer;		
				if(strcmp(msg,"exit") == 0 )
				{
					cout<<"\n Disconnected from "<<inet_ntoa(newaddr.sin_addr),ntohs(newaddr.sin_port);
					break;
				}
				else
				{
				//out<<"\n Client : "<<msg;
					cout<<"\n > ";
					string data;
					getline(cin,data);
					memset(&msg,0,CHUNK_SIZE);
					strcpy(msg,data.c_str());
					if(data == "exit")
					{
					send(newsocket,(char*)&msg,CHUNK_SIZE,0);
					break;
					}
					send(newsocket,(char*)&msg,CHUNK_SIZE,0);
					bzero(msg,sizeof(msg));
				}
				}
			cout<<"\nTOTAL SIZE : "<<total_size;

		}
	}

	close(newsocket);
	return 0;

}
