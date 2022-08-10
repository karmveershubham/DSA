#include<iostream>
#include<conio.h>
#include<string>
#include "Stacks.h"
using namespace std;

char addition(string num1, string num2)
{
    int len1=num1.length();
    int len2=num2.length();
    int carry=0,  sum=0, max;
    
    Stacks st1(len1);
    Stacks st2(len2);
    if (len1>=len2)
        max=len1;
    else
        max=len2;
    Stacks Res(max+1);

    for (int i=0; i<len1; i++){
        st1.push(num1[i]);
    }
    for (int i=0; i<len2; i++){
        st2.push(num1[i]);
    }

    while((st1.isEmpty()!=true) || (st2.isEmpty()!=true)){
        sum=(static_cast<int>(st1.pop()))+(static_cast<int>(st2.pop()))+carry;
        Res.push(static_cast<char>(sum%10));
        carry=sum/10;
    }
    while(st1.isEmpty()!=true){
        sum=(static_cast<int>(st1.pop()))+carry;
        Res.push(static_cast<char>(sum%10));
        carry=sum/10;
    }
    while(st2.isEmpty()!=true){
        sum=(static_cast<int>(st2.pop()))+carry;
        Res.push(static_cast<char>(sum%10));
        carry=sum/10;
    }
    while(carry>0){
        Res.push(static_cast<char>(carry));
        carry /= 10;
    }

    Res.display();

}

int main(){
    long num1, num2;
    cout<<"Enter first number."<<endl;
    cin>>num1;
    cout<<"Enter second number."<<endl;
    cin>>num2;

    string n1= to_string(num1);
	string n2= to_string(num2);
    addition(n1,n2);
    getch();
    return 0;

}
