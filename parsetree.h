
/* 
 * File:   parsetree.cpp
 * Author: pike
 *
 * Created on November 28, 2015
 */



#include <sstream>
#include <queue>
#include <cmath>
#include <iomanip>
#include "parsetree.h"

using namespace std;

// default constructor
ParseTree::ParseTree()
{
	root = NULL;
}

// recursive function to delete(free) tree node
// starting from the node pointed by T
void ParseTree::destroy(TreeNode* T)
{
	if  (T != NULL)    
	{    
		destroy(T->left) ;
		destroy(T->right) ;

		delete  T ;
	}
}

// destructor
// by calling destory function to free each node of the tree
// starting from the root node
ParseTree::~ParseTree()
{
	destroy(root);
}

// calculate the height of tree (tree levels)
// an empty tree has zero height
// The height of the tree is the number of nodes at the longest path
// from the root node to the leaf node
int ParseTree::height(TreeNode* T) 
{
	int hh = 0;
	int lh, rh;
	if (T == NULL) return hh;
	if ((T->left == NULL) && (T->right == NULL)) return (hh++);
	lh = height(T->left);
	rh = height(T->right);
	if (lh >= rh)
		hh = lh + 1;
	else
		hh = rh + 1;
	return hh;
}

// return the height of the parse tree
int ParseTree::getHeight()
{
	if (root == NULL)
		return 0;
	else
		return (height(root));
}

const string PEMDAS = "+-*/";

void ParseTree::setNode(TreeNode& node)
{
	string key = node.key;

	for(int o = 0; o < 4; o++) //scan through operators
	{	
		int brackets = 0;	
		for(int i = 0; i < key.size(); i++) //scan for parentheses
		{
			char c = key[i];
			if(c == OPENBRACE)
				brackets++;
			else if(c == CLOSEBRACE)
				brackets--;
			else if(brackets == 0 && c == PEMDAS[o]) //if parentheses match and & 
			{
				node.key = PEMDAS[o];

				node.left = new TreeNode(key.substr(0, i));
				node.right = new TreeNode(key.substr(i + 1));

				setNode(*node.left);
				setNode(*node.right);

				return;
			}
			if(brackets < 0)
			{
				cout << "Incorrect parentheses. Please try again."<< endl;
				return;
			}
		}
	}
	int openP = 0;
	for(; openP < key.size(); openP++)
		if(key[openP] == OPENBRACE)
			break;

	if(openP == key.size())
		return;

	int closeP = key.size() - 1;
	for(; closeP >= 0; closeP--)
		if(key[closeP] == CLOSEBRACE)
			break;

	node.key = key.substr(openP + 1, closeP - openP - 1);

	setNode(node);
}

// to build the parse tree from an infix expression
void ParseTree::buildTree(string E)
{
	root = new TreeNode (E);

	setNode(*root);
}


// display the parse tree strcture visually
//unchanged from Lab12
void ParseTree::printTree() 
{
	queue<TreeNode*> nodes;
	queue<int> levelList;
	TreeNode* current = NULL;
	int printDepth = this->getHeight();
	int possibleNodes = static_cast<int>(pow(2.0, printDepth + 1));
	int countNodes = 0;

	nodes.push(root);
	int currentLevel = 0;
	int previousLevel = -1;
	levelList.push(currentLevel);

	while (countNodes < possibleNodes) 
	{
		countNodes = countNodes + 1;
		if (!nodes.empty())  
		{    
			current = nodes.front();
			nodes.pop();
		}
		if (!levelList.empty())
		{    
			currentLevel = levelList.front();
			levelList.pop();
		}
		if (currentLevel > previousLevel)
		{
			cout << endl << endl;
			previousLevel = currentLevel;
			for (int j = 0; j < int ((pow(2.0, (printDepth - currentLevel))) - 1); j++)
				cout << setw(FORMAT_WIDTH)<< " ";
		}
		else
		{
			for (int i = 0; i < int ((pow(2.0, (printDepth - currentLevel + 1)) - 1)) ; i++) 
			{
				cout << setw(FORMAT_WIDTH) <<" ";
			}
		}
		if (current != NULL)
		{
			cout << setw(FORMAT_WIDTH) << current->key;
			nodes.push(current->left);
			levelList.push(currentLevel + 1);
			nodes.push(current->right);
			levelList.push(currentLevel + 1);
		}
		else {
			nodes.push(NULL);
			levelList.push(currentLevel + 1);
			nodes.push(NULL);
			levelList.push(currentLevel + 1);
			cout << setw(FORMAT_WIDTH) << " ";
		}

	}
}

