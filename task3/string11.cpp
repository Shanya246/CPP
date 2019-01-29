#include "string11.h"

#include<iostream>
#include<stdio.h>

using namespace std;


void String :: append(char *string1,char *string2)
{
	int i,j;
	cout<<"\n\n ***Appended function*** " ;
	for(i=0;string1[i]!='\0';i++)
		string3[i]= string1[i];
	for(j=0;string2[j]!='\0';j++)
		string3[i+j]= string2[j];
	string3[i+j] = '\0';
	cout<<"\n\n Appended string : " <<string3<<endl;

}

void String :: indexof(char *string1,int index)
{
	int l;
	cout<<"\n ***Index function*** " <<endl;
	if((l=len(string1))>index)
	{
	for(int i=0;i<=index;i++)
		if(i==(index-1)){
			cout<<"\n Index at "<<i+1;
			cout<<":" <<string1[i];
		}
	}
	else
		cout<<"\n __Invalid index value__";

}

void String :: substring(char *string1,int s_index,int e_index)
{
	cout<<"\n ***Substring function*** "<<endl;
	if(e_index>s_index){
		cout<<"\n Substring : ";
		for(int i=s_index;i<=e_index;i++)
			cout<<string1[i];
		cout<<"\n";
	}
	else
		cerr<<"\n Invalid starting and ending index";

}

int String :: len(char *string1)
{
	int length=0;
	for(int i=0;string1[i]!='\0';i++)
		length++;
	cout<<"\n The length of the string  is  : " <<length<<endl;
	return length;
}
/*
int main()
{
	int index,s_index,e_index;
	String str ;
	cout<<"\n Enter the first String :  ";
	cin>>str.string1;
	cout<<"\n Enter the second String : ";
	cin>>str.string2;
	str.len(str.string1);
	str.len(str.string2);
	str.append(str.string1,str.string2);
	cout<<"\n Enter the index number to get the character in the first string :  ";
	cin>>index;
	str.indexof(str.string1,index);
	cout<<"\n\n Enter the starting index :  ";
	cin>>s_index;
	cout<<"\n Enter the ending index : " ;
	cin>>e_index;
	str.substring(str.string1,s_index,e_index);

}
*/
