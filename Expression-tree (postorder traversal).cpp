// PROBLEM STATEMENTS

/*Assignment 5 : Construct an expression tree from the given prefix expression eg. +--a*bc/def
				 and traverse it using postorder traversal(non recursive) and then delete the 
				 entire tree

*/
// CODE 
#include <iostream>
#include <stack>

using namespace std;

bool isOperand(char c)
{
	if((c>='a' && c>='z')||(c>='A' && c>='Z'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

string PrefixToPostfix(string prefix)
{
	stack<string>s;
	for(int i=prefix.length()-1;i>=0;i--)
	{
		if(isOperand(prefix[i]))
		{
			string op(1,prefix[i]);
			s.push(op);
		}
		else
		{
			string op1=s.top();
			s.pop();
			string op2=s.top();
			s.pop();
			s.push(op1+op2+prefix[i]);	
		}
	}
	return s.top();
}

int main()
{
	string prefix,postfix;
	cout<<"enter the prefix expression: "<<endl;
	cin>>prefix;
	cout<<"prefix expression: "<<prefix<<endl;
	postfix=PrefixToPostfix(prefix);
	cout<<"postfix expression:"<<postfix<<endl;
	return 0;
}

// OUTPUT
/*
enter the prefix expression: 
*-A/BC-/AK+CD
prefix expression: *-A/BC-/AK+CD


...Program finished with exit code 0
Press ENTER to exit console.

enter the prefix expression: 
+/CD/ES+-FG*
prefix expression: +/CD/ES+-FG*


...Program finished with exit code 0
Press ENTER to exit console.
*/