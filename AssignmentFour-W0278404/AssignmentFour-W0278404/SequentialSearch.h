#pragma once
#ifndef _SEQUENTIALSEARCH_H
#define _SEQUENTIALSEARCH_H

#include <iostream>

using namespace std;

class SequentialSearch
{
private:

public:
	SequentialSearch();
	virtual ~SequentialSearch();
	int search(int unsortedList[], int length, int searched);
};

#endif