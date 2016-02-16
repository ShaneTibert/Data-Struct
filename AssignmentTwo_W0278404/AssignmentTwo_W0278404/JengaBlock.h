#ifndef _JENGABLOCK_H
#define _JENGABLOCK_H

class JengaBlock
{
private:
	int _dataX;
	int _dataY;
	JengaBlock *_next;

public:
	JengaBlock();
	JengaBlock(int dataX, int dataY, JengaBlock* next);
	virtual ~JengaBlock();

	int getDataX();
	int getDataY();
	void setData(int dataX, int dataY);

	JengaBlock* getNext();
	void setNext(JengaBlock *next);
};

#endif
