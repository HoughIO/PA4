/* 
 * File:   parsetree.h
 * Author: pike
 *
 * Created on November 28, 2015
 */

#ifndef PARSETREE_H
#define	PARSETREE_H

#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
#include <queue>
#include <sstream>
#include <cmath>
#include <vector>
using namespace std;

class TreeNode
{
private:
	string key;
	TreeNode *left, *right;
public:
	TreeNode(string k) {key = k; left = right = NULL;}
	friend class ParseTree;
};

const char PLUS = '+';
const char MINUS = '-';
const char MULTIPLY = '*';
const char DIVIDE = '/';
const char OPENBRACE = '(';
const char CLOSEBRACE = ')';
const int FORMAT_WIDTH = 3;  // It is for the display of a tree structure: the width of each operand

class ParseTree
{
private:	
public:
	TreeNode* root;				// points to the root of the tree
	ParseTree();			//constructor
        ParseTree(string key);
	~ParseTree();			//destructor
	//void Preorder(TreeNode* node);
        void buildTree(string E);
		void setNode(TreeNode&);
        int getHeight();
        void printTree();               // show the tree in a figure
	void postfix(TreeNode *T);
// for postfix expression
	/*
	bool TryParse(const string &symbol);
	int Precedence(const string &c);	//checks precendence
	bool isOperator(const string &c); //check for operators
	int infix2postfix(string infix);
	*/
	// ------------------------------------------
        void destroy(TreeNode* T);
        int height(TreeNode* T);
};


#endif	/* PARSETREE_H */
