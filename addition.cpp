#include <iostream>
#include "stack.h"
using namespace std;


class addition{
    string num1 , num2 ;
    int size1 , size2 ;
    int sum , carry ;

    public:
        addition(string s1 , string s2);
        void add();
};

addition::addition(string s1 , string s2){
    num1 = s1 ;
    num2 = s2 ;
    size1 = s1.length() ;
    size2 = s2.length() ;
    sum = 0 ;
    carry = 0 ;
}
void addition::add(){
	//define stacks 
    Stack S1(size1) , S2(size2) , S3(size2+8) ;
    
    //push element to the stack
    for (int i = 0; i < size1;i++){
        S1.push(num1[i]);
    }
    for (int i = 0; i < size2;i++){
        S2.push(num2[i]);
    }
    int sum = 0 , carry = 0 ;
    
    //add until one of the stack is empty 
    while(!(S1.isEmpty())&&!(S2.isEmpty()))
    {
        int sum = int(S1.pop())-48 + int(S2.pop()) -48 + carry ;
        if (sum > 9){
            carry = 1 ;
            sum = sum - 10 ;
        }
        else{
            carry = 0 ;
        }
        
        S3.push(char(sum)+48);
        
    }
    
    //if there is element in the second stack add them to carry 
    if (S1.isEmpty()){
        while(!S2.isEmpty()){
            sum = int(S2.pop()) - 48 + carry ;
            if (sum > 9){
                carry = 1 ;
                sum = sum - 10 ;
            }
            else{
                carry = 0 ;
            }
            S3.push(char(sum)+48);
        }
    }
    //if there is elemnt in the first stack add them with the carry 
    else if (S2.isEmpty()){
        while(!S1.isEmpty()){
            sum = int(S1.pop()) - 48 + carry ;
            if (sum > 9){
                carry = 1 ;
                sum = sum - 10 ;
            }
            else{
                carry = 0 ;
            }
            S3.push(char(sum)+48);
        }
    }
    //uf carry == 1 push it into the resultant stack
    if (carry == 1){
        S3.push('1');
    }
    
    //show the stack
    while(!S3.isEmpty()){
        cout << S3.pop();
    }
}
int main(){
    string S1,S2;
    cout<<"enter the first number : "<<endl;
    cin>>S1;
    cout<<"enter the second number: "<<endl;
    cin>>S2;
    addition A1(S1,S2);
    A1.add();

}
