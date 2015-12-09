//course: CS216-00x
//Project: Lab Assignment 12
//Date: 11/28/2015
//Purpose: to build a parse tree which shows the relationships
//         among operators and operands in an expression
//         display the tree structure visually
//Author: (your name)
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iterator>
#include <stack>
#include <fstream>
#include <cmath>
#include "parsetree.h"
#include <cstdlib>
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
 
    for(unsigned int i = 0; i < tokens.size(); i++)  //read from right to left
    {
        if(TryParse(tokens[i]))//order for postfix
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

//remoave leftover operators from stack and put ihn outputlist
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
bool TryParse(const string &symbol)//check if each in string are operand or operator (including parentheses)
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
int Priority(const string &c)//assign importance/order of operators
{
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
bool isOperator(const string &c) //check for operators
{
    return (c == "+" || c == "-" || c == "*" || c == "/");
}

//main function
int main()
{
	ParseTree exprTree; 
	bool option1 = false; //check if option 1 chosen first
	string choice;
	string expression; //entered infix expression
	cout << endl;
	while (choice != "6"){
		cout << "********************************************************" << endl;
		cout << "1. Read an expression" << endl;
		cout << "2. Display the prefix expression" << endl; 
		cout << "3. Display the infix expression" << endl;
		cout << "4. Display the postfix expression" << endl;
		cout << "5. Evaluate the expression using postfix notation" << endl;
		cout << "6. Exit" << endl;
		cout << "********************************************************" << endl;
		cout << "Select: ";
		getline(cin, choice);

		if (choice == "1"){
			cout << "Enter an infix expression:" << endl;
			cin >> expression;	
			exprTree.buildTree(expression);
			exprTree.printTree();
			cout << endl;
			option1 = true;								 //option 1 chosen first
		} // end choice 1

		if (choice == "2"){
			if (option1 == false){ 							//option 1 not chosen first
				cout << "Please enter an expression using Option 1" << endl;}

			else { 										//option 1 chosen

			} 
		} //end option 2
		if (choice == "3"){
			if (option1 == false){ 							//option 1 not chosen first
				cout << "Please enter an expression using Option 1" << endl;}

			else { 										//option 1 chosen
				cout << expression  << endl;			//infix expression
			}

		} //end option 3
		if (choice == "4"){
			if (option1 == false){ 							//option 1 not chosen first
				cout << "Please enter an expression using Option 1" << endl;}

			else {
				cout <<"Inputted Expression: " << expression << endl;				//option 1 chosen
				cout << "Postfix Expression: " << endl;
				infix2postfix(expression);			
				cout << endl;	
			}

		} //end option 4
		if (choice == "5"){
			if (option1 == false){ 							//option 1 not chosen first
				cout << "Please enter an expression using Option 1" << endl;}

			else { 										//option 1 chosen
			}
		}
	} // end while
	return 0;
}
