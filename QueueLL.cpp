#include<iostream>
#include<conio.h>
#include "LinkedList.h"

int main()
{
    SLList l;
    int ch, val;
    cout<<"\n1. Insert element to queue \n";
    cout<<"2. Delete element from queue \n";
    cout<<"3. Display all elements of queue \n";
    cout<<"4. Check Empty queue"<<endl;
    cout<<"5. Check Full queue"<<endl;
    cout<<"6. Display front element"<<endl;
    cout<<"7. Quit \n";
    while(1)
    {
        
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch (ch)
        {
            case 1:
                cout<<"Enter value to  insert in queue: "; 
                cin>>val;
                l.addToTail(val);
                break;
            case 2:
                if(l.isEmpty())
                    cout<<"Queue Underflow \n";
                else{
                    val=l.deleteFromHead();
                    cout<<"The dequeued value is: "<<val;
                }
                break;
            case 3:
                cout<<"The Queue is: ";
                l.Traverse();
                break;
            case 4:
                if(l.isEmpty())
                    cout<<"Queue is Empty"<<endl;
                else
                    cout<<"Queue is Not Empty"<<endl;
                break;
            case 5:
                cout<<"Queue is Not Full"<<endl;
            case 6:{
                if(!l.isEmpty())
                {
                int val=l.deleteFromHead();
                    l.addToHead(val);
                cout<<"Top element of queue is: "<<val<<endl;
                }else{
                    cout<<"queue is Empty"<<endl;
                }
                break;
            }
            case 7:
                return 0;
            default:
                cout<<"Wrong choice \n";
        } //End of switch 
    } //End of while 
} //End of main() 


