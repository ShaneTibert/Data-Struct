#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <string>

using namespace std;

class BinaryNode
{
public:
	int height;
	string storedWord;
	BinaryNode* LeftLeaf;
	BinaryNode* RightLeaf;
	BinaryNode();
	~BinaryNode();
};

#endif