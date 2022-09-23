#include<iostream>
#include<conio.h>
#include "LinkedList.h"

int main() 
{
    //creatig object for class
    SLList l;
    int ch, val;

    cout<<"\n1) Push in stack"<<endl;
    cout<<"2) Pop from stack"<<endl;
    cout<<"3) Display stack"<<endl;
    cout<<"4) Check Empty stack"<<endl;
    cout<<"5) Check Full stack"<<endl;
    cout<<"6) Display top elemnt"<<endl;
    cout<<"7) EXIT"<<endl;

    bool t=true;

    while(t)
    {
        cout<<"\nEnter choice: "<<endl;
        cin>>ch;
            //calling function according to choices.
        switch(ch) {
            case 1: {
                cout<<"Enter value to be pushed:"<<endl;
                cin>>val;
                l.addToTail(val);
            	l.Traverse();
                break;
            }
            case 2: 
            {
                if(l.isEmpty())
                {
                    cout<<"stack underflow";
                }
                else
                {
                    cout<<"The popped elemnt is: "<<l.deleteFromTail()<<endl;
                }
                break;
            }
            case 3:
            {
            	cout<<"\nStack is: ";
                l.Traverse();
                break;
            }
            case 4:{
                if(l.isEmpty())
                {
                    cout<<"Stack is Empty"<<endl;
                }
                else
                {
                    cout<<"stack is Not Empty"<<endl;
                }
                break;
            }
            case 5:
            {
                cout<<"Stack is Not Full"<<endl;
                break;
            }
            case 6:
            {
            	if(!l.isEmpty())
            	{
            	int val=l.deleteFromTail();
            	l.addToTail(val);
                cout<<"Top element of Stack is:\t "<<val<<endl;
            	}else{
            		cout<<"Stack is Empty"<<endl;
            	}
                break;
            }
            case 7:
            {
                cout<<"\nThanks. "<<endl;
                t=false;
                break;
            }
            default: 
            {
                cout<<"Invalid Choice"<<endl;
            }
        }
    }
    getch();
    return 0;
}
