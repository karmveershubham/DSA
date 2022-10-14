#include<iostream>
#include<conio.h>
using namespace std;

int factorial(int n){
    if(n==0){
        return 1;
    }
    else if(n==1){
        return n;
    }else{
        n=n*factorial(n-1);
    }
}
int main(){
    char ch='y';
    while(ch=='y'){
        int n;
        cout<<"Enter the number: ";
        cin>>n;
        if(n<0){
            cout<<"Enter positive value.";
        }else{
            cout<<"Factorial of "<<n<<" is: "<<factorial(n);
        }
        cout<<"\nContinue??";
        cin>>ch;
    }
    cout<<"Thanks";
    getch();
    return 0;
}