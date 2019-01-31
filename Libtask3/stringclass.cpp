#include<iostream>
#include <stringclass.h>
#include<string.h>
using namespace std;


	String::String()
		{
			length =0;
		}
	String::String(const char* c)
		{
			if(c)
			{
				int len=0;
				while(c[len] != '\0')
					len++;
				length = len;
				str = new char[length];
				for(int i=0;i<len;i++)
					str[i]=c[i];
				cout<<str<<endl;
			}
			else
			{
				length =0;
				str = new char[0];
			}
		}


	String String :: operator+(const String str1)
		{
			String s;
			s.str = new char[strlen(str1.str)];
			strcat(str,str1.str);
			strcpy(s.str,str);
			return s;
		}

       String String :: operator=(const String str1)
		{
			String s;
			s.str = str1.str;
			return s;
		}

	String::~String()
		{
			delete[] str;
			//cout<<"\n Destructor calls..";
		}

int String :: len()
{
        int length=0;
//      cout<<"\n\n Len function calls..."<<endl;
        for(int i=0;(str[i])!='\0';i++)
        {
                length++;
        }
        return length;
}

int String :: indexof(char in)
{
        int c=0;
//      cout<<"\n Indexof function calls..."<<endl;
	for(int i=0;str[i]!='\0';i++)
        {
                if(in==str[i])
                     c = i;
        }
/*	if(c>1)
		return c;
	else
		return -1;*/
	return c;
}

char* String :: substring(int s_index,int e_index)
{

        int j=0,i;
	int value=e_index -s_index;
	char* sub=new char[value];
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
	return sub;
}

