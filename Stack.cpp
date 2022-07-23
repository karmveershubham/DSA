#include <iostream>
using namespace std;

//creating class;
class Stack{

    private:
        int n, *arr, top;
    public:
        Stack(){
            int size;
            cout<<"Enter the size of Stack: ";
            cin>>size;
            n=size-1;
            arr=new int[n];
            top=-1;
        }
    
    bool isEmpty(){
        if(top<=-1){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isFull(){
        if(top>n-1){
            return true;
        }
        else{
            return false;
        }
    }
        //push function
    int push(int val) {
        arr[++top]=val;
    }
        
            //pop function
    int pop() {
        //cout<<"The popped element is "<< arr[top] <<endl;
        int a = arr[top];
        top--;   // top = top-1
        return a;
    }

        //display function
    void display() {
        cout<<"Stack elements are:\t";
        for(int i=top; i>=0; i--)
            cout<<arr[i]<<" ";
            cout<<endl;
    }
        
    int TopElement(){
        int val= pop();
        push(val);
        cout<<"Top element of Stack is:\t :"<<val<<endl;

    }
};

int main() {
    //creatig object for class
    Stack st;
    int ch, val;
    cout<<"1) Push in stack"<<endl;
    cout<<"2) Pop from stack"<<endl;
    cout<<"3) Display stack"<<endl;
    cout<<"4) Check Empty stack"<<endl;
    cout<<"5) Check Full stack"<<endl;
    cout<<"6) Display top elemnt"<<endl;
    cout<<"7) EXIT"<<endl;

    bool t=true;
    while(t){
        cout<<"\nEnter choice: "<<endl;
        cin>>ch;
        //calling function according to choices.
        switch(ch) {
            case 1: {
                if(st.isFull()){
                    cout<<"stack overflow."<<endl;
                }
                else{
                    cout<<"Enter value to be pushed:"<<endl;
                    cin>>val;
                    st.push(val);
                }
                break;
            }
            case 2: {
                if(st.isEmpty()){
                    cout<<"stack underflow";
                }
                else{
                    cout<<"The popped elemnt is: "<< st.pop() <<endl;
                }
                break;
            }
            case 3: {
                st.display();
                break;
            }
            case 4:{
                if(st.isEmpty()){
                    cout<<"Stack is Empty"<<endl;
                }
                else{
                    cout<<"stack is Not Empty"<<endl;
                }
                break;
            }
            case 5:{
                if(st.isFull()){
                cout<<"Stack is full"<<endl;
                }else{
                cout<<"Stack is Not Full"<<endl;
                }
                break;
            }
            case 6:{
                st.TopElement();
                break;
            }
            case 7:{
                cout<<"\nThanks. "<<endl;
                t=false;
                break;
            }
            default: {
                cout<<"Invalid Choice"<<endl;
            }
        }
    }
return 0;
}
