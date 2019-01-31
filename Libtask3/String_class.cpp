#include<iostream>
#include<string.h>
using namespace std;

class String
{
	public:
		char* str;
		char sub[30];
		String(){
		}
		String(char* str)
		{
			cout<<"\n Constructor calls...";
			this->str=str;
			cout<<"\n Value of str : "<<str;
		}
		int len();
		char indexof(int index);
		String operator+(String str1)
		{
			String s;
			strcat(str,str1.str);
			strcpy(s.str,str);
			return s;
		}
		void display_string()
		{
			cout<<str;
		}
		void substring(int,int);
};
int String :: len()
{
	int length=0;
	cout<<"\n\n Len function calls...";
	for(int i=0;(str[i])!='\0';i++)
	{
		length++;
	}
	return length;
}

char String :: indexof(int index)
{
	char c;
	cout<<"\n Indexof function calls...";
	for(int i=0;i<=index;i++)
	{
		if(i==index)
			c=str[index];
	}
	return c;
}

void String :: substring(int s_index,int e_index)
{

	int j=0,i;
	cout<<"\n Starting index at the function  : "<<s_index;
	cout<<"\n Ending index at the function : "<<e_index;
	if(e_index>s_index)
	{
		for(i=s_index,j=0;i<=e_index;i++,j++)
		{
			sub[j]=str[i];
		}
		sub[j]='\0';
	}
	else
		cout<<"\n Invalid inputs..."<<endl;
	cout<<"\n The String S will be .." <<sub;
}

int main()
{
	char s[100];
//	char *sub;
	int index,s_index,e_index;
	cout<<"\n Enter the string :  ";
	cin>>s;
	String s1(s);
	String s2 = s1;
	int len = s1.len();
	cout<<"\n The length of the string is :  "<<len<<endl;
	String s3 = s1+s2;
	cout<<"\n The Appended string is :";
	s3.display_string();
	cout<<"\n The length of the string : "<<len<<endl;
	cout<<"\n Enter the index value : ";
	cin>>index;
	char c = s1.indexof(index);
	cout<<"\n Index at "<<index<<" : "<<c;
	cout<<"\n Enter the starting index : ";
	cin>>s_index;
	cout<<"\n Enter the ending index :  ";
	cin>>e_index;
	s3.substring(s_index,e_index);

	}

