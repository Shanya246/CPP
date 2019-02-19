#include<ubacipc/SharedMemory.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
int main()
{
	int key,size,sid;
	key = 9999;
	size = 1;
	SharedMemory s;
	sid  = s.initSharedMemory(key,size,false);
	char *detectKey ;
	detectKey = (char*)s.attachSharedMemory(sid,false);
	char c;
	c = *detectKey;
	while(1)
	{
		if(c!= *detectKey)
		{
			if(isalnum(detectKey[0]))
			{
				cout<<"\n Key detected :  "<<detectKey<<endl;
				s.detachSharedMemory(detectKey);
				s.destroySharedMemory(sid);
				exit(1);
			}
			else
				cout<<"\n Key detected is  :  "<<detectKey<<endl;
			c= *detectKey;
		}
	}
}
