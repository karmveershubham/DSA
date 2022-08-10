// CPP program to check for balanced Parenthesis.
#include <iostream>
#include<fstream>
#include<conio.h>
#include"Stacks.h"
#include<string>
using namespace std;
// Function to check whether two characters are opening 
// and closing of same type. 
bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}
bool balncedParenthesis(string exp, int size)
{
	Stacks S(size);
	for(int i =0;i<size;i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(S.isEmpty() || !ArePair(S.TopElement(),exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.isEmpty() ? true:false;
}

// Driver code
int main()
{   
    ofstream MyFile("filename.txt");        // Create and open a text file
    string content;
    cout<<"Enter the set of Parenthesis.:";     
    getline(cin,content);                
    MyFile<<content;                        // Write to the file
    MyFile.close();

    string myText;
    ifstream MyReadFile("filename.txt"); 
    getline(MyReadFile,myText);
    MyReadFile.close();

    int len=myText.length();
	// Function call
	if (balncedParenthesis(myText,len))
		cout << "Balanced Parenthesis."<<endl;
	else
		cout << "Parenthesis Not Balanced."<<endl;
	return 0;
    getch();
}
