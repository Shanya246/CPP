#include<iostream>
#include<string.h>
using namespace std;

class String{
	public:
		int length;
		char* str;
		char* sub;
		String()
		{
			length =0;
		}
		String(const char* c)
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
		int len();
		int indexof(char);
		char* substring(int,int);
		
		String operator+(const String str1)
		{
			String s;
			s.str = new char[strlen(str1.str)];
			strcat(str,str1.str);
			strcpy(s.str,str);
			return s;
		}

		String operator=(const String str1)
		{
			String s;
			s.str = str1.str;
			return s;
		}

		~String()
		{
			delete[] str;
			//cout<<"\n Destructor calls..";
		}

};

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
                     c++;   
        }
	if(c>1)
		return c;
	else
		return -1;
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



int main()
{
	int s_index,e_index;
	const char* h = "Hello world";
	String s2(h);
	String s1= s2;
	String s4("......HAIII");
	cout<<"\n The length of the string is :  "<<s1.len()<<endl;
	cout<<"\n Enter the character :  ";
	char c ;
	cin>>c;
	cout<<"\n The index is : "<<s1.indexof(c)<<endl;
	cout<<"\n Enter the starting index :  ";
	cin>>s_index;
	cout<<"\n Enter the ending index :  ";
	cin>>e_index;
	cout<<"\n The substring is : "<<s1.substring(s_index,e_index);
	String s3 = s1+s4;
	cout<<"\n\n The appended string is  : "<<s3.str;
	String s5 = "Market";
	cout<<"\n The s5 Object returns :  "<<s5.str<<endl;
}
	
