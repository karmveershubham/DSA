#include <iostream>
#include "Stack.h"
using namespace std;
bool is_palindrome(string text){
    
    int len = text.length()/2;
    Stack st(len);
    int i;

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
    bool res = is_palindrome(word);
    if(res==true){
        cout<<"The word is palindrome"<<endl;
    }
    else{
        cout<<"The word is not a palindrome"<<endl;
    }
    
    return 0;
}

