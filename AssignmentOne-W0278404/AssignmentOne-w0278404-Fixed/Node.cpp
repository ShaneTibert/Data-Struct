#include "Node.h"

Node::~Node()
{
	next = nullptr;
	delete(next);
}