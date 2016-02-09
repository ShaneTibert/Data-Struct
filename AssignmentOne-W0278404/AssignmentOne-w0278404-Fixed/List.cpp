#include "Node.h"
#include "List.h"

using namespace std;

int List::RetrieveValue(int valueue)
{
	return 0;
}
// gets the value at a position
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

// adds data to the current link
void List::Add(int num) {
	current->data = num;
}

// deletes the data from the current link 
void List::DeleteValue(int value)
{
	current->data = 0;
}

// deletes the data from the specified link 
void List::DeletePosition(int nodenum)
{
	current = first;
	for (int i = 0; i < nodenum; i++) {
		if (i == nodenum -1) {
			current->data = 0;
			break;
		}
		else {
			current = current->next;
		}
	}
}

//Deletes all data (sets it to zero)
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
//Inserts a new data value after the spcified link
void List::InsertAfterValue(int value, int num)
{
	current = first;

		for (int i = 0; i <= value++; i++) {
			if (i == value++) {
				current->data = num;
			}
			else {
				current->next = new Node();
				current = current->next;
			}
		}
}

// inserts data at a node number
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
