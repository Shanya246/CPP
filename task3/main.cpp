#include<iostream>
#include "string11.h"

using namespace std;


int main()
{
	cout<<"\n String ";
	char string1[100],string2[100];
	String str;
        int index,s_index,e_index;
        //String str ;
        cout<<"\n Enter the first String :  ";
        cin>>string1;
        cout<<"\n Enter the second String : ";
        cin>>string2;
        str.len(string1);
        str.append(string1,string2);
        cout<<"\n Enter the index number to get the character in the first string :  ";
        cin>>index;
        str.indexof(string1,index);
        cout<<"\n\n Enter the starting index :  ";
        cin>>s_index;
        cout<<"\n Enter the ending index : " ;
        cin>>e_index;
        str.substring(string1,s_index,e_index);

}
