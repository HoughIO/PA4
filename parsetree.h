/* 
 * File:   parsetree.h
 * Author: Graham Hough 
 */

#ifndef PARSETREE_H
#define	PARSETREE_H

#include <iostream>
#include <string>

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
        void buildTree(string E);
		void setNode(TreeNode&);
        int getHeight();
        void printTree();               // show the tree in a figure
	void postfix(TreeNode* T);
	
	// ------------------------------------------
        void destroy(TreeNode* T);
        int height(TreeNode* T);
};


#endif	/* PARSETREE_H */

