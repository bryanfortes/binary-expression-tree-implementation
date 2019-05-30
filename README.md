Educational Objectives: Gain experience with a binary tree and its application in converting postfix expressions into infix expressions, as well as practice with developing recursive algorithms.

Task: Implement a binary expression tree and use the tree to convert postfix expressions into infix expressions

Project Requirements:
In this project, you are asked to develop a binary expression tree and use the tree to convert postfix expressions into infix expressions. In this project, a postfix expression may contain 4 types of operators: multiplication (*), division (/), plus (+), and minus (-). We assume that multiplication and division have the same precedence, plus and minus have the same precedence, and multiplication and division have higher precedence than plus and minus. All operators are left-associative (i.e. associate left-to-right).

Binary Expression Tree:. Build a binary expression tree class called "BET". Your BET class must have a nested structure named "BinaryNode" to contain the node-related information (including, e.g., element and pointers to the children nodes). In addition, BET must at least support the following interface functions:

Public interface

BET(): default zero-parameter constructor. Builds an empty tree. 

BET(const string& postfix): one-parameter constructor, where parameter "postfix" is string containing a postfix expression. The tree should be built based on the postfix expression. Tokens in the postfix expression are separated by spaces.

BET(const BET&): copy constructor -- makes appropriate deep copy of the tree

~BET(): destructor -- cleans up all dynamic space in the tree

bool buildFromPostfix(const string& postfix): parameter "postfix" is string containing a postfix expression. The tree should be built based on the postfix expression. Tokens in the postfix expression are separated by spaces. If the tree contains nodes before the function is called, you need to first delete the existing nodes. Return true if the new tree is built successfully. Return false if an error is encountered.

const BET & operator= (const BET &): assignment operator -- makes appropriate deep copy

void printInfixExpression(): Print out the infix expression. Should do this by making use of the private (recursive) version

void printPostfixExpression(): Print the postfix form of the expression. Use the private recursive function to help

size_t size(): Return the number of nodes in the tree (using the private recursive function)

size_t leaf_nodes(): Return the number of leaf nodes in the tree. (Use the private recursive function to help)

bool empty(): return true if the tree is empty. Return false otherwise.

Private helper functions (all the required private member functions must be implemented recursively):

void printInfixExpression(BinaryNode *n): print to the standard output the corresponding infix expression. Note that you may need to add parentheses depending on the precedence of operators. You should not have unnecessary parentheses.

void makeEmpty(BinaryNode* &t): delete all nodes in the subtree pointed to by t.

BinaryNode * clone(BinaryNode *t): clone all nodes in the subtree pointed to by t. Can be called by functions such as the assignment operator=.

void printPostfixExpression(BinaryNode *n): print to the standard output the corresponding postfix expression.

size_t size(BinaryNode *t): return the number of nodes in the subtree pointed to by t.

size_t leaf_nodes(BinaryNode *t): return the number of leaf nodes in the subtree pointed to by t.
