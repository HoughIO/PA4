/*
Name: Graham Hough
Section: 1
Class: CS216
*/

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
bool isAnOperator(const string &c);
int infix2postfix(string infix)
{
    istringstream isAString(infix);
    vector<string> positionaltok;
    while(isAString)
    {
        string temp;
        isAString >>temp;
        positionaltok.push_back(temp);
    }
    vector<string> outputList;//output vector
    stack<string> s;//main stack
 
    //operator: +, -, *, /, ^, ()
    //operands: 1234567890
    for(unsigned int i = 0; i < positionaltok.size(); i++)  //read from right to left
    {
        if(TryParse(positionaltok[i]))
        {
            outputList.push_back(positionaltok[i]);
        }
        if(positionaltok[i] == "(")
        {
            s.push(positionaltok[i]);
        }
        if(positionaltok[i] == ")")
        {
            while(!s.empty() && s.top() != "(")
            {
                outputList.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        if(isAnOperator(positionaltok[i]) == true)
        {
            while(!s.empty() && Priority(s.top()) >= Priority(positionaltok[i]))
            {
                outputList.push_back(s.top());
                s.pop();
            }
            s.push(positionaltok[i]);
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
    bool isANumber = false;
    for(unsigned int i = 0; i < symbol.size(); i++)
    {
        if(!isdigit(symbol[i]))
        {
            isANumber = false;
        }
        else
        {
            isANumber = true;
        }
    }
    return isANumber;
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
bool isAnOperator(const string &c)
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
		if(sel == "2" ){
			if(infix.size() != 0){
				cout << "Expression from user: " << infix << endl;
				cout << "Prefix Expression: ";
				stringstream buffer;
				buffer << infix2postfix(infix);
				string y(buffer.str());
				string z(y.rbegin(), y.rend());
				cout << z << endl;


			}
			else{
				cout << "Expression from user input is empty!" << endl;	
			}
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
