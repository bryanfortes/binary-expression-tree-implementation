#ifndef BET_H
#define BET_H
#include <string>
#include <cctype>
struct BinaryNode {
	std::string token;
	BinaryNode* left;
	BinaryNode* right;
	BinaryNode(const std::string& theToken, BinaryNode* l, BinaryNode* r)
		: token{ theToken }, left{ l }, right{ r } {}
	BinaryNode(const std::string&& theToken, BinaryNode* l, BinaryNode* r)
		: token{ std::move(theToken) }, left{ l }, right{ r } {}
};

class BET {
public:
	BET();
	BET(const std::string& postfix);
	BET(const BET& rhs);
	~BET();

	bool buildFromPostfix(const std::string& postfix);
	const BET & operator=(const BET& rhs);
	void printInfixExpression() const;
	void printPostfixExpression() const;
	size_t size() const;
	size_t leaf_nodes() const;
	bool empty() const;

private:
	BinaryNode *root;
	void printInfixExpression(BinaryNode *n) const;
	void makeEmpty(BinaryNode* &t) const;
	BinaryNode* clone(BinaryNode* t) const;
	void printPostfixExpression(BinaryNode *n) const;
	size_t size(BinaryNode*t) const;
	size_t leaf_nodes(BinaryNode *t) const;

	bool isOperator(char x) { //helper function i made
		if (x == '*' || x == '/' || x == '+' || x == '-')
			return true;
		return false;
	}
};
#endif