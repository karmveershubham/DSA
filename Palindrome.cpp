#include<iostream>
#include<conio.h>
#include "Stacks.h"
using namespace std;

bool palindrome(string str)
{
    int i=0 ,size=str.size(), mid=(size/2);
    Stacks St(mid);

    for(i=0; i<mid; i++)
    {
        St.push (str[i]);
    }

    if (size % 2 != 0)
    {
        i++;
    }

    while (str[i] != '\0')
    {
        char ele =  St.pop();
        if (ele != str[i])
            return false;
        i++;
    }   
    return true;
}


int main(){
    string word;
    cout<<"Enter the word"<<endl;
    cin>>word;
    bool res = palindrome(word);
    if(res==true){
        cout<<"The word is palindrome."<<endl;
    }
    else{
        cout<<"The word is not a palindrome."<<endl;
    }
    getch();
    return 0;
}


