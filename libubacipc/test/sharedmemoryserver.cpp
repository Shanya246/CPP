#include<ubacipc/SharedMemory.h>
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	int sid,key,size;
	char *regionName;
	key =9999;
	size = 1;
	SharedMemory s;
	sid = s.initSharedMemory(key,size,true);
	cout<<"Shared Memory id  : " <<sid<<endl;
	regionName = (char *)s.attachSharedMemory(sid,true);
	char c;
	while(1)
	{
		cout<<"\n Enter an input :  ";
		c = getchar();
		if( c == '\n')
			c= getchar();

		strncpy(regionName,&c,size);
		if(isalnum(*regionName))
		{
			s.detachSharedMemory(regionName);
			s.destroySharedMemory(sid);
			exit(1);
		}
	}
}
