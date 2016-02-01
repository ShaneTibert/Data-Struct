#include "Node.h"

node::~node()
{
	next = nullptr;
	delete(next);
}