#include "List.h"
#include "Node.h"
#include <iostream>

using namespace std;

int List::RetrieveValue(int value)
{
	return 0;
}
int List::RetrievePosition(int nodenum) {

	int num = nodenum - 1;

	int val = 0;
	current = first;
	for (int i = 0; i < nodenum; i++) {
		if (i == num) {
			val = current->data;
			break;
		}
		else {
			if (current->next == nullptr) {
				grow();
				current = current->next;
			}
			else {
				current = current->next;
			}
		}
	}
	return val;
}

List::~List()
{
}

bool List::empty() const
{
	return false;
}

void List::grow()
{
}

void List::Add(int num) {
Node *node = new Node();
node->data = num;

if (first == NULL)
{
	first = node;
}
else
{
	Node *currNode = first;
	Node *prevNode = NULL;

	while (currNode != NULL)
	{
		prevNode = currNode;
		currNode = currNode->next;
	}

	if (prevNode != NULL)
	{
		prevNode->next = node;
	}
}
	}

void List::DeleteValue(int value)
{
	Node *node = first;
	Node *prev = NULL;

	while (node != NULL)
	{
		if (node->data == value)
		{
			break;
		}

		prev = node;
		node = node->next;
	}

	if (node != NULL)
	{
		if (node == first)
		{
			first = node->next;
		}
		else
		{
			prev->next = node->next;
		}

		delete node;
	}
}

void List::DeletePosition(int nodenum)
{
	int num = nodenum - 1;

	current = first;
	for (int i = 0; i < nodenum; i++) {
		if (i == num) {
			current->data = 0;
			break;
		}
		else {
			break;
		}
	}
}

void List::DeleteAll()
{

}

void List::InsertAfterValue(int value, int num)
{
	current = first;

		for (int i = 0; i <= value++; i++) {
			if (i == value++) {
				current->data = num;
			}
			else {
				grow();
				current = current = current->next;
			}
		}
}

void List::InsertAtPosition(int nodenum, int num)
{
	current = first;

	nodenum = nodenum - 1;

	for (int i = 0; i <= nodenum; i++) {
		
		if (i == nodenum) {
			current->data = num;
			break;
		}
		if (current->next == nullptr) {
			grow();
			current = current->next;
		}
		else {
			current = current->next;
		}
	}
}
