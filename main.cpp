#include <string>
#include <iterator>
#include <stack>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "parsetree.h"

using namespace std;

bool TryParse(const string &symbol);
int Priority(const string &c);
bool isOperator(const string &c);
int infix2postfix(string infix)
{
    istringstream iss(infix);
    vector<string> tokens;//store the tokens here
    while(iss)
    {
        string temp;
        iss >>temp;
        tokens.push_back(temp);
    }
    vector<string> outputList;//output vector
    stack<string> s;//main stack
 
    //operator: +, -, *, /, ^, ()
    //operands: 1234567890
    for(unsigned int i = 0; i < tokens.size(); i++)  //read from right to left
    {
        if(TryParse(tokens[i]))
        {
            outputList.push_back(tokens[i]);
        }
        if(tokens[i] == "(")
        {
            s.push(tokens[i]);
        }
        if(tokens[i] == ")")
        {
            while(!s.empty() && s.top() != "(")
            {
                outputList.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        if(isOperator(tokens[i]) == true)
        {
            while(!s.empty() && Priority(s.top()) >= Priority(tokens[i]))
            {
                outputList.push_back(s.top());
                s.pop();
            }
            s.push(tokens[i]);
        }
    }
    //pop any remaining operators from the stack and insert to outputlist
    while(!s.empty())
    {
        outputList.push_back(s.top());
        s.pop();
    }
 
    for(unsigned int i = 0; i < outputList.size(); i++)
    {
        cout<<outputList[i] << " ";
    }
    return 0;
}
bool TryParse(const string &symbol)
{
    bool isNumber = false;
    for(unsigned int i = 0; i < symbol.size(); i++)
    {
        if(!isdigit(symbol[i]))
        {
            isNumber = false;
        }
        else
        {
            isNumber = true;
        }
    }
    return isNumber;
}
int Priority(const string &c)
{
    if(c == "^")
    {
        return 3;
    }
    if(c == "*" || c == "/")
    {
        return 2;
    }
    if(c== "+" || c == "-")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool isOperator(const string &c)
{
    return (c == "+" || c == "-" || c == "*" || c == "/" || c == "^");
}
int main()
{
	ParseTree exprTree; 
	string infix;
	string sel;
	bool more = true;
	do
	{
		cout << endl;
		cout << "***********************************************************\nSELECTIONS:\n1. Read an expression\n2. Display the prefix expression\n3. Display the infix expression\n4. Display the postfix expression\n5. Evaluate the expression using postfix notation.\n6. Exit\n***********************************************************" << endl;
		getline(cin,sel);

		if(sel == "6")
		{
			more = false;
		}

		if(sel == "1") {
			cout << "Please type an infix expression: ";
			getline(cin, infix);
                        exprTree.buildTree(infix);
			exprTree.printTree();
		}
		if(sel == "3" ){
			if(infix.size() != 0){
				cout << "Expression from user: " << infix << endl;
				cout << "INFIX Expression: " << infix << endl;
			}
			else{
				cout << "Expression from user input is empty!" << endl;	
			}
		}
		
		if(sel == "4" ){
			if(infix.size() != 0){
				cout << "Expression from user input: " << infix << endl;
				cout << "Outputting postifx:" << endl;
				infix2postfix(infix);
			}
			else{
				cout << "Expression from user input is empty!" << endl;	
			}
		}

			
	}while (more);
} //end of program
