#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "parsetree.h"

using namespace std;

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
		if(sel == "3" && infix.size() != 0){
			cout << "Expression from user: " << infix << endl;
			cout << "INFIX Expression: " << infix << endl;
		}

		else{
			cout << "Expression from user input is empty!" << endl;	
		}
		
		if(sel == "4" && infix.size() != 0){
			cout << "Expression from user input: " << infix << endl;
			cout << "Outputting postifx:" << endl;
			exprTree.printPost();
		}

		else{
			cout << "Expression from user input is empty!" << endl;	
		}
			
	}while (more);
} //end of program
