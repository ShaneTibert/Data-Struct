#include "Node.h"

#pragma once
class List
{
private:
	node *first;
	node *current;

public:
	List() : first(new node()) {};
	~List();
	bool empty() const;
	void grow();
	void Add(int num);
	void DeleteValue(int value);
	void DeletePosition(int nodenum);
	void DeleteAll();
	void InsertAfterValue(int value, int num);
	void InsertAtPosition(int nodenum, int num);
	int RetrieveValue(int value);
	int RetrievePosition(int nodenum);
};