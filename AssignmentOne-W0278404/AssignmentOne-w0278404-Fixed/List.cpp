#include "List.h"
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
			//Yo mamma jamma??
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

void List::Add(int num)
{
}

void List::DeleteValue(int value)
{
}

void List::DeletePosition(int nodenum)
{
}

void List::DeleteAll()
{
}

void List::InsertAfterValue(int value, int num)
{
}

void List::InsertAtPosition(int nodenum, int num)
{
}
