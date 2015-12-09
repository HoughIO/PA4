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

		if(sel == "Q" || sel == "q")
		{
			more = false;
		}
		if(sel == "1") {
			getline(cin, infix);
                        exprTree.buildTree(infix);
			exprTree.printTree();
		}
		if(sel == "4" && infix.size() != 0){
			exprTree.postfix(exprTree.root);
		}
		else{
			cout << "Please input an expression." << endl;	
		}
			
	}while (more);
} //end of program
