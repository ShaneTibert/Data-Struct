#include "Node.h"

#pragma once
class List
{
private:
	Node *first;
	Node *current;

public:
	List() : first(new Node()) {};
	~List();
	bool empty() const;
	void Add(int num);
	void DeleteValue(int valueue);
	void DeletePosition(int nodenum);
	void DeleteAll();
	void InsertAfterValue(int valueue, int num);
	void InsertAtPosition(int nodenum, int num);
	int RetrieveValue(int valueue);
	int RetrievePosition(int nodenum);
};