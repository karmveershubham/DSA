#include<iostream>
using namespace std;

//creating class;
class Stack{

    private:
        int n, top;
        char *arr;

    public:
        Stack(int size){
            n=size-1;
            arr=new char[n];
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
        int push(char val) {
            arr[++top]=val;
        }
            
            //pop function
        char pop() {
            char a = arr[top];
            top--;
            return a;
        }

            //display function
        void display() {
            cout<<"Stack elements are:\t";
            for(int i=top; i>=0; i--)
                cout<<arr[i]<<" ";
                cout<<endl;
        }
            
        char TopElement(){
            char val= pop();
            push(val);
            return val;
        }        
};

bool is_palindrome(string text){
    int i;
    int len=text.length()/2;

    for(i=0; i=len; i++){
        st.push (text[i]);
    }

    if (text.length() % 2 != 0) {
        i++;
    }

    while (text[i] != '\0')
    {
        char ele = st.TopElement();
        st.pop();

    // If the characters differ then the
    // given string is not a palindrome

        if (ele != text[i])
            return false;
        i++;
    }   
    return true;
}


int main(){
    string word;
    cout<<"Enter the word"<<endl;
    cin>>word;
    
    int len = word.length()/2;
    Stack st(len);

    bool res = is_palindrome(word);
    if(res==true){
        cout<<"The word is palindrome"<<endl;
    }
    else{
        cout<<"The word is not a palindrome"<<endl;
    }
    
    return 0;
}

