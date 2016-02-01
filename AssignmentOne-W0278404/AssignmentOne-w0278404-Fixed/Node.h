#pragma once
class node
{
	int data;
	node *next;
	node() : data(0), next(nullptr) {};
	~node();
};