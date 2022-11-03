#include<iostream>
#include<conio.h>
#include "Stacks.h"
#include<algorithm>
using namespace std;

bool isOperator(char c)
{
	return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C)
{
	if (C == '-' || C == '+')
		return 1;
	else if (C == '*' || C == '/')
		return 2;
	else if (C == '$')
		return 3;
	return 0;
}

string infixToPostfix(string infix)
{
	infix = '(' + infix + ')';
	int l = infix.size();
	Stacks stack(l);
	string output;

	for (int i = 0; i < l; i++) {

		// If the scanned character is an
		// operand, add it to output.
		if (isalpha(infix[i]) || isdigit(infix[i]))
			output += infix[i];

		// If the scanned character is an
		// ‘(‘, push it to the stack.
		else if (infix[i] == '(')
			stack.push('(');

		// If the scanned character is an
		// ‘)’, pop and output from the stack
		// until an ‘(‘ is encountered.
		else if (infix[i] == ')') {
			while (stack.TopElement() != '(') {
				output += stack.TopElement();
				stack.pop();
			}

			// Remove '(' from the stack
			stack.pop();
		}

		// Operator found
		else
		{
			if (isOperator(stack.TopElement()))
			{
				if(infix[i] == '$')
				{
					while (getPriority(infix[i]) <= getPriority(stack.TopElement()))
					{
						output += stack.TopElement();
						stack.pop();
					}
					
				}
				else
				{
					while (getPriority(infix[i]) < getPriority(stack.TopElement()))
					{
						output += stack.TopElement();
						stack.pop();
					}
					
				}

				// Push current Operator on stack
				stack.push(infix[i]);
			}
		}
	}
	while(!stack.isEmpty()){
		output += stack.TopElement();
		stack.pop();
	}
	return output;
}

string infixToPrefix(string infix)
{
	/* Reverse String
	* Replace ( with ) and vice versa
	* Get Postfix
	* Reverse Postfix * */
	int l = infix.size();

	// Reverse infix
	reverse(infix.begin(), infix.end());

	// Replace ( with ) and vice versa
	for (int i = 0; i < l; i++) {

		if (infix[i] == '(') {
			infix[i] = ')';
		}
		else if (infix[i] == ')') {
			infix[i] = '(';
		}
	}

	string prefix = infixToPostfix(infix);

	// Reverse postfix
	reverse(prefix.begin(), prefix.end());

	return prefix;
}

int main()
{
	
	string s; // = ("(A-B/C)*(A/K+L)");
	cout<<"Enter the infix string: ";
	cin>>s;
	cout <<"Prefix Expression: "<<infixToPrefix(s)<<"\n" << endl;
	cout<<"Postfix Expression: "<<infixToPostfix(s)<<endl;
	
    getch();
	return 0;
}


