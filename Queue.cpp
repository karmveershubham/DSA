// C Program to Implement a Queue using an Array 
#include <iostream>
using namespace std;

class Queue {
    private:
        int rear,front,*q_array,size;
    public:
        Queue(int n){
            size=n;
            q_array=new int[size];
            front = 0;
            rear = - 1;
        }

        void enqueue(int val)
        {   
            q_array[++rear] = val;
        } // End of insert() 
        
        int dequeue()
        {
            int val= q_array[front++];
            return val;
        } //End of delete() 
        int peek(){
            int val=dequeue();
            enqueue(val);
            return val;
        }

        bool isFull(){
            return (rear == size-1);
        }
        bool isEmpty(){
            return (front>rear)?true:false;
        }
        void display()
        {
            if (isEmpty())
                cout<<"Queue is empty \n";
            else
            {
                cout<<"Queue is: ";
                for (int i=front; i <= rear; i++)
                    cout<<q_array[i]<<" ";
                cout<<endl;
            }
        } 
};

int main()
{
    int size, val;
    cout<<"Enter the size of Queue: ";
    cin>>size;
    Queue q(size);
    int choice;
    cout<<"\n1. Insert element to queue \n";
    cout<<"2. Delete element from queue \n";
    cout<<"3. Display all elements of queue \n";
    cout<<"4. Check Empty queue"<<endl;
    cout<<"5. Check Full queue"<<endl;
    cout<<"6. Display top element"<<endl;
    cout<<"7. Quit \n";
    while(1)
    {
        
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                if(q.isFull())
                    cout<<"Queue Overflow \n";
                else{
                    cout<<"Enter value to  insert in queue: "; 
                    cin>>val;
                    q.enqueue(val);
                }
                break;
            case 2:
                if(q.isEmpty())
                    cout<<"Queue Underflow \n";
                else{
                    val=q.dequeue();
                    cout<<"The dequeued value is: "<<val;
                }
                break;
            case 3:
                q.display();
                break;
            case 4:
                if(q.isEmpty())
                    cout<<"Queue is Empty"<<endl;
                else
                    cout<<"Queue is Not Empty"<<endl;
                break;
            case 5:
                if(q.isFull())
                    cout<<"Queue is Full"<<endl;
                else
                    cout<<"Queue is Not Full"<<endl;
                break;
            case 6:{
                if(!q.isEmpty())
                    cout<<"Top element of queue is: "<<q.peek()<<endl;
                else{
                    cout<<"Queue is Empty\n";
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


