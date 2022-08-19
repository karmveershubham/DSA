#include<iostream>
#include<conio.h>
#include "Stacks.h"
using namespace std;

char addition(string num1, string num2)
{
    int len1=num1.length();
    int len2=num2.length();
    int carry=0,  sum=0;

    //having equal length of both num
    Stacks st1(len1), st2(len2);
    if (len1< len2)
        num1.insert(0, len2-len1, '0');
    else
        num2.insert(0, len1-len2, '0');
        
    Stacks Res(num1.length()+1);

    //inserting digits in array
    for (int i=0; i<num1.length(); i++){
        st1.push(num1[i]);
        st2.push(num2[i]);
    }
    //adding while stack not get empty.
    while(!(st1.isEmpty()))
    {
        int sum = int(st1.pop())-48 + int(st2.pop()) -48 + carry ;
        Res.push(char(sum%10)+48);
        carry=sum/10;   
    }
    //inserting carry if occur
    if (carry == 1)
        Res.push('1');

    //displaying result o addition.
    cout<<"Result of Addition:\t";
    while(!Res.isEmpty()){
        cout << Res.pop();
    }
}

int main()
{
    string num1, num2;
    cout<<"Enter first number."<<endl;
    cin>>num1;
    cout<<"Enter second number."<<endl;
    cin>>num2;

    addition(num1,num2);
    getch();
    return 0;
}
