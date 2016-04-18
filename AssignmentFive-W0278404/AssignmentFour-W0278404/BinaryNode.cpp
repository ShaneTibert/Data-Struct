#include "BinaryNode.h"



BinaryNode::BinaryNode()
{
	LeftLeaf = NULL;
	RightLeaf = NULL;
}


BinaryNode::~BinaryNode()
{
	delete LeftLeaf;
	delete RightLeaf;
}
