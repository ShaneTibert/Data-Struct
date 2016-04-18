#pragma once
#ifndef TREE_H
#define TREE_H

#include <string>
#include "BinaryNode.h"

class  Tree
{
public:
	BinaryNode* Root;

	 Tree();
	~Tree();

	BinaryNode* Insert(BinaryNode* node, string data);
	int TreeHeight(BinaryNode* node);
	bool Search(BinaryNode* node, string word);
	BinaryNode* RL(BinaryNode* node);
	BinaryNode* LR(BinaryNode* node);
	BinaryNode* RR(BinaryNode* node);
	BinaryNode* LL(BinaryNode* node);
};

#endif

