// C++ program to evaluate value of a postfix expression
#include <iostream>
#include <conio.h>
#include "Stacks.h"
#include <cmath>
using namespace std;

int postfixEval(string term)
{
	int size=term.size();
    Stacks opStk(size);
	
	for (int i=0; i<size; i++)
	{
		// If the scanned character is an operand
		// push it to the stack. else pop values and perform operation.
		cout<<term[i]<<" ";
		if (isdigit(term[i]))
			opStk.push(term[i]-'0');

		else
		{
			int val1 = opStk.pop();
			cout<<"val1 = "<<val1<<endl;
			int val2 = opStk.pop();
			cout<<"val2 = "<<val2<<endl;
			switch (term[i])
			{
			
			case '$': opStk.push(pow(val2,val1)); return pow(val2,val1); break;
			case '+': opStk.push(val2+val1); break;
			case '-': opStk.push(val2-val1); break;
			case '*': opStk.push(val2*val1); break;
			case '/': opStk.push(val2/val1); break;
			}
		}
	}
	return opStk.pop();
}

// Driver program to test above functions
int main()
{
    cout<<"Enter a Postfix expression: ";
	string exp;
    cin>>exp;
	cout<<"postfix evaluation: "<< postfixEval(exp);
    getch();
	return 0;
}
