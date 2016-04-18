#include "BinarySearch.h"
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include <time.h>


BinarySearch::BinarySearch(){}
BinarySearch::~BinarySearch(){}
int BinarySearch::search(int unsortedList[], int searched, int length){


	int half = (length/2);
	int last = 0;

	for (int x = 0; x < length; x++)
	{
		if (searched == half - 1)
		{
			return x;
		}

		if (searched < half-1)
		{
			last = half;
			half = (half / 2);
		}
		else
		{
			half = (half + 1);
		}

	}
	return -1;
}