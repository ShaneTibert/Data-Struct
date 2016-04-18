#include "Tree.h"
Tree::Tree()
{
}


Tree::~Tree()
{
}


bool Tree::Search(BinaryNode* branch, string currentWord)
{
	if (branch != NULL)
	{
		if (currentWord > branch->storedWord)
		{
			return Search(branch->RightLeaf, currentWord);
		}
		else if (currentWord < branch->storedWord)
		{
			return Search(branch->LeftLeaf, currentWord);
		}
		else if (branch->storedWord == currentWord)
		{
			return true;
		}
	}

	return false;
}

BinaryNode* Tree::RL(BinaryNode* branch)
{
	BinaryNode* TempNode;
	TempNode = branch->RightLeaf;
	branch->RightLeaf = TempNode->LeftLeaf;
	TempNode->LeftLeaf = branch;

	int height = 0;

	if (TreeHeight(branch->LeftLeaf) > TreeHeight(branch->RightLeaf))
	{
		height = TreeHeight(branch->LeftLeaf);
	}
	else
	{
		height = TreeHeight(branch->RightLeaf);
	}

	height += 1;

	branch->height = height;

	if (height > TreeHeight(TempNode->RightLeaf))
	{
		height += 1;
	}
	else
	{
		height = TreeHeight(branch->RightLeaf) + 1;
	}

	TempNode->height = height;

	return TempNode;
}

BinaryNode* Tree::LR(BinaryNode* branch)
{
	BinaryNode* tempBranch;
	tempBranch = branch->LeftLeaf;
	branch->LeftLeaf = tempBranch->RightLeaf;
	tempBranch->RightLeaf = branch;

	int height = 0;

	if (TreeHeight(branch->LeftLeaf) > TreeHeight(branch->RightLeaf))
	{
		height = TreeHeight(branch->LeftLeaf);
	}
	else
	{
		height = TreeHeight(branch->RightLeaf);
	}

	height += 1;

	branch->height = height;

	if (TreeHeight(tempBranch->LeftLeaf) > height)
	{
		height = TreeHeight(tempBranch->LeftLeaf) + 1;
	}
	else
	{
		height += 1;
	}

	tempBranch->height = height;

	return tempBranch;
}

BinaryNode* Tree::RR(BinaryNode* branch)
{
	branch->RightLeaf = LR(branch->RightLeaf);
	return RL(branch);
}

BinaryNode* Tree::LL(BinaryNode* branch)
{
	branch->LeftLeaf = RL(branch->LeftLeaf);
	return LR(branch);
}

BinaryNode* Tree::Insert(BinaryNode* branch, string storedWord)
{
	if (branch == NULL)
	{
		branch = new BinaryNode();
		branch->storedWord = storedWord;
		branch->height = 0;
	}
	else
	{

		if (storedWord > branch->storedWord)
		{
			branch->RightLeaf = Insert(branch->RightLeaf, storedWord);
			if ((TreeHeight(branch->RightLeaf) - TreeHeight(branch->LeftLeaf)) == 2)
			{
				if (storedWord > branch->RightLeaf->storedWord)
				{
					branch = RL(branch);
				}
				else
				{
					branch = RR(branch);
				}
			}
		}
		else if (storedWord < branch->storedWord)
		{
			branch->LeftLeaf = Insert(branch->LeftLeaf, storedWord);
			if ((TreeHeight(branch->LeftLeaf) - TreeHeight(branch->RightLeaf)) == 2)
			{
				if (storedWord < branch->LeftLeaf->storedWord)
				{
					branch = LR(branch);
				}
				else
				{
					branch = LL(branch);
				}
			}
		}
		else
		{

		}
	}

	int height = 0;

	if (TreeHeight(branch->LeftLeaf) > TreeHeight(branch->RightLeaf))
	{
		height = TreeHeight(branch->LeftLeaf);
	}
	else
	{
		height = TreeHeight(branch->RightLeaf);
	}

	height += 1;

	branch->height = height;

	return branch;
}


int Tree::TreeHeight(BinaryNode* branch)
{
	int height;
	if (branch == NULL)
		return 0;
	else
	{
		height = branch->height;
		return height;
	}
}