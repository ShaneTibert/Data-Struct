#ifndef _JENGA_H
#define _JENGA_H

#include <iostream>
#include "JengaBlock.h"

using namespace std;
enum myerror_code { success, underflow, overflow };

class Jenga
{
private:
	JengaBlock *_top;

public:
	Jenga();
	virtual ~Jenga();

	myerror_code Push(int numX,int numY);
	int PeekX();
	int PeekY();
	myerror_code Pop();

	friend ostream& operator<<(ostream& output, Jenga& jenga);
};

#endif
