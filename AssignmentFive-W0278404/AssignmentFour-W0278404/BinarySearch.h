#pragma once
#ifndef _BINARYSEARCH_H
#define _BINARYSEARCH_H

#include <iostream>

using namespace std;

class BinarySearch
{
private:

public:
	BinarySearch();
	virtual ~BinarySearch();
	int search(int unsortedList[], int length, int searched);
};

#endif