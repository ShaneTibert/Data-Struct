#include <iostream>
#include "JengaBlock.h"
#include "Jenga.h"

using namespace std;


Jenga::Jenga() : _top(NULL)
{
}

Jenga::~Jenga()
{
	while (_top != NULL)
	{
		Pop();
	}
}

myerror_code Jenga::Push(int numX,int numY)
{
	_top = new JengaBlock(numX,numY, _top);
	return(success);
}

int Jenga::PeekX()
{
	return _top->getDataX();
}

int Jenga::PeekY()
{
	return _top->getDataY();
}
myerror_code Jenga::Pop()
{
	if (_top != NULL) {

		JengaBlock* block = _top;
		_top = _top->getNext();
		delete block;
		return(success);
	}
	else {
		return(underflow);
	}
}

ostream& operator<<(ostream& output, Jenga& jenga)
{
	JengaBlock *block = jenga._top;

	while (block != NULL)
	{
		cout << block->getDataX() << " " << block->getDataY() << endl;
		block = block->getNext();
	}

	return output;
}

