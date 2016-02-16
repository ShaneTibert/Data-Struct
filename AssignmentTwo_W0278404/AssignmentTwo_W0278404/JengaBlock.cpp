#include <iostream>
#include "JengaBlock.h"

using namespace std;

JengaBlock::JengaBlock() : _dataX(0), _dataY(0), _next(NULL)
{
}

JengaBlock::JengaBlock(int dataX, int dataY, JengaBlock* next) : _dataX(dataX), _dataY(dataY), _next(next)
{
}

JengaBlock::~JengaBlock()
{
}

int JengaBlock::getDataX()
{
	return _dataX;
}
int JengaBlock::getDataY()
{
	return _dataY;
}

void JengaBlock::setData(int dataX,int dataY)
{
	_dataX = dataX;
	_dataY = dataY;
}

JengaBlock* JengaBlock::getNext()
{
	return _next;
}

void JengaBlock::setNext(JengaBlock *next)
{
	_next = next;
}
