#include<iostream>
#include<ubacipc/VariableBuffer.h>
#include<stdio.h>
#include<unistd.h>
using namespace std;

void copy(char *start,char *end,char *recv)
{
	while(start<end)
	{
		*recv = *(start);
		start++;
		recv++;
	}
}
/*void print(char *start,size_t length)
{
	while(length> 0)
	{
		printf("%c",*(start));
		start++;
		length--;
	}
	cout<<"\n";
}
*/
class client :public VariableBuffer
{
	public:
		client(size_t c):VariableBuffer :: VariableBuffer(c,10)
		{
		}

		~client(){}

};

int main()
{
	client cli(100);
	char word[15] ="HelloWorld";
	char recv[15]={0};
	char *start = word;
	char *end = start;
	char *input = word + 10;

	while(1)
	{
		while(start<input && end <input)
		{
			int seed = random()%10;
			end += seed;
			if(end >= input)
				end = input;

			copy(start,end,recv);
			cout<<"\n RECV :  "<<recv;
			cout<<"  Length :  "<<strlen(recv);
			cli.align_data(recv,strlen(recv));
			bzero(recv,sizeof(recv));
			start = end;
			sleep(5);
		}
	start= word;
	end = start;
	}
}	

