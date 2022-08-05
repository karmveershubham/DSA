#include<iostream>
using namespace std;

//creating class
class Stacks{

    private:
        int n, top;
        char *arr;

    public:
        Stacks(int size)
        {
            n=size;
            arr=new char[n];
            top=-1;
        }
    
        bool isEmpty()
        {
            if(top<=-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        bool isFull()
        {
            if(top>=n-1)
            {
                return true;
            }
            else{
                return false;
            }
        }
            //push function
        int push(char val) 
        {
            arr[++top]=val;
        }
            
            //pop function
        char pop() 
        {
            char a = arr[top];
            top--;
            return a;
        }

            //display function
        void display() 
        {
            cout<<"Stack elements are:\t";
            for(int i=top; i>=0; i--)
                cout<<arr[i]<<" ";
                cout<<endl;
        }
            
        char TopElement()
        {
            char val= pop();
            push(val);
            return val;
        }        
};
