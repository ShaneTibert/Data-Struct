#pragma once



#ifndef NODE_H
#define NODE_H


class Node
{
public:
	int data;
	Node *next;
	Node() : data(0), next(nullptr) {};
	~Node();
};


#endif /* NODE_H */