#include "bet.h"
#include <stack>
#include <iostream>
using namespace std;

BET::BET() : root{nullptr} {}

BET::BET(const std::string & postfix) {	buildFromPostfix(postfix); }

BET::BET(const BET & rhs) { root = clone(rhs.root); }

BET::~BET() { makeEmpty(root); }

bool BET::buildFromPostfix(const string& postfix) {
	if (size() > 0) { makeEmpty(root); }
	stack<BinaryNode*> stck; //using algorithm from notes/ textbook using stl stack
	string next; //next in input
	int opCount = 0; //tracker for operands
	for (auto itr = postfix.begin(); itr != postfix.end(); ++itr) { //using stl string iterator to traverse 
		if (isOperator(*itr) && stck.size() >= 2) { //if an operator is read in and the stack is >=2, 
			next += *itr;
			BinaryNode* right = stck.top();
			stck.pop();
			BinaryNode* left = stck.top();
			stck.pop(); //pop 2 operands and store them as left/right children
			BinaryNode* parent = new BinaryNode{ next, left, right }; //for the parent node made from the postfix
			stck.push(parent); //push expression to stack
			opCount--; //decrement bc an operator has been pushed
			next.clear(); //clear next for more input
		}
		else if (isOperator(*itr) && stck.size() < 2) { //checks if # of operators match # of operands and breaks
			opCount--;
			break;
		}
		else if (!isOperator(*itr) & !isspace(*itr)) { //checks if operand
			while (!isspace(*itr) && !isOperator(*itr) && itr != postfix.end()) { //grabs operand, skipping ws
				next += *itr;
				++itr;
			}
			--itr; //move itr back
			BinaryNode* leaf = new BinaryNode{next, nullptr, nullptr}; //create leaf from operand
			opCount++;
			stck.push(leaf);
			next.clear();
		}
		else // ignores ws
			continue;
	}

	swap(root, stck.top()); //top() contains pointer to final tree, swaps with root

	if (opCount == 1) // there should be one more operand than operator in stack once function is complete
		return true; //return true if so
	else { //else delete tree and report error
		makeEmpty(root);
		cout << "Wrong postfix expression.\n";
		return false;
	}
}

const BET & BET::operator=(const BET & rhs)
{
	root = clone(rhs.root);
	return *this;
}

void BET::printInfixExpression() const {
	printInfixExpression(root);
	cout << '\n';
}

void BET::printPostfixExpression() const {
	printPostfixExpression(root);
	cout << '\n';
}

size_t BET::size() const { return size(root); }

size_t BET::leaf_nodes() const { return leaf_nodes(root); }

bool BET::empty() const { return size() == 0; }

/**************************/
/*private helper functions*/
/******defined below*******/
/**************************/

void BET::printInfixExpression(BinaryNode* n) const {
	if (n->left == nullptr)
		cout << n->token;
	else {
		if (n != this->root)
			cout << "(";
		printInfixExpression(n->left);
		cout << ' ' << n->token << ' ';
		printInfixExpression(n->right);
		if (n != this->root)
			cout << ")";
	}
}

void BET::makeEmpty(BinaryNode* & t) const {
	if (t != nullptr) {
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}

BinaryNode* BET::clone(BinaryNode* t) const {
	if (t == nullptr)
		return nullptr;
	else
		return new BinaryNode{ t->token, clone(t->left), clone(t->right) };
}

void BET::printPostfixExpression(BinaryNode* n) const { 
	if (n != nullptr)
	{
		printPostfixExpression(n->left);
		printPostfixExpression(n->right);
		cout << n->token << ' ';
	}
}

size_t BET::size(BinaryNode* t) const {
	if (t == nullptr)
		return 0;
	else
		return (1 + size(t->left) + size(t->right));
}

size_t BET::leaf_nodes(BinaryNode* t) const {
	if ((t != nullptr) && ((t->left == nullptr) && (t->right == nullptr)))
		return 1;
	else
		return leaf_nodes(t->left) + leaf_nodes(t->right);
}