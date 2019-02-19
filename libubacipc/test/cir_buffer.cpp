#include<ubacipc/CircularBuffer.h>
#include<stdio.h>
#include<stdlib.h>
void createbuff();
void writebuff();
void readbuff();
void readcommit();
CircularBuffer *cir;
int main()
{
	int choice;
	while(1){
	cout<<"\n 1.Create Buffer \n 2.Write \n 3.Read \n 4.ReadCommit";
		cout<<"\n Enter the choice  : ";
	cin>>choice;
	if(choice ==1)
		createbuff();
	else if (choice ==2)
		writebuff();
	else if(choice==3)
		readbuff();
	else if(choice ==4)
		readcommit();
	else
		cout<<"\n Enter the correct choice ";
	cir->print();
	}
}

void createbuff()
{
	cout<<"\n Enter the capacity :  ";
	int capacity;
	cin>>capacity;
	cir = new CircularBuffer(capacity);
	cout<<"\n Buffer created  ";
	
}

void writebuff()
{
	string con;
	cout<<"\n Enter the contents to the buffer :  ";
	cin>>con;

	int written = cir->write(con.c_str(),con.length());
	cout<<"\n Written bytes : "<<written<<"Tot bytes : "<<con.length();
}

void readbuff()
{
	cout<<"\n Reading...   ";
	char *readbuf = new char[100];
	int r=cir->read(readbuf);
	cout<<"\n The data is  : "<<readbuf;
	free(readbuf);
}

void readcommit()
{
	cout<<"Read commit :  ";
	int commit;
	cin>>commit;
	cir->readCommit(commit);
}
