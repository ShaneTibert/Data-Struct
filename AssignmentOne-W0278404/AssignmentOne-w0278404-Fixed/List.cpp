#include "Node.h"
#include "List.h"

using namespace std;

int List::RetrieveValue(int valueue)
{
	return 0;
}
int List::RetrievePosition(int nodenum) {

	int num = nodenum - 1;

	int value = 0;
	current = first;
	for (int i = 0; i < nodenum; i++) {
		if (i == num) {
			value = current->data;
			break;
		}
		else {
			if (current->next == nullptr) {
				current->next = new Node();
				current = current->next;
			}
			else {
				current = current->next;
			}
		}
	}
	return value;
}

List::~List()
{
}

bool List::empty() const
{
	return false;
}

void List::Add(int num) {
	current->data = num;
}

void List::DeleteValue(int valueue)
{
	current->data = 0;
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
	Node* next;
	current = first;

	while (current->next != nullptr){
		current->data = 0;
		next = current->next;
		current = next;

	}
	current->data = 0;
}

void List::InsertAfterValue(int valueue, int num)
{
	current = first;

		for (int i = 0; i <= valueue++; i++) {
			if (i == valueue++) {
				current->data = num;
			}
			else {
				current->next = new Node();
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
			current->next = new Node();
			current = current->next;
		}
		else {
			current = current->next;
		}
	}
}
