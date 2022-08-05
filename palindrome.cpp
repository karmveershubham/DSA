#include<iostream>
#include<conio.h>
#include "Stacks.h"
using namespace std;

bool palindrome(string str)
{
	int s=str.size();
	int mid=(s/2)-1;
	Stacks S(s/2);
	for (int i=0;i<=mid;i++)
	{
		S.push(str[i]);
	}
	if (s%2==0)
	{
		mid=mid+1;
	}
	else
	{
		mid=mid+2;
	}
	for(int i=mid;i<s;i++)
	{
		char ch=S.pop();
		if (ch==str[i])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
}

int main()
{
	string str;
	bool res;
	cout<<"Enter the string: ";
	cin>>str;
	res=palindrome(str);
	if (res==true)
	{
		cout<<"Given string is palindrome"<<endl;
	}
	else
	{
		cout<<"Given string is not palindrome"<<endl;
	}
	getch();
	return 0;
	
}
