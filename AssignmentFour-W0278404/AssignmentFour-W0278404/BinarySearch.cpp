#include "BinarySearch.h"
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include <time.h>


BinarySearch::BinarySearch(){}
BinarySearch::~BinarySearch(){}
int BinarySearch::search(int unsortedList[], int searched, int length){


	int half = length - 1 / 2;
	int last = 0;

	for (int x = 0; x < length; x++)
	{
		if (searched == unsortedList[half])
		{
			return x;
		}

		if (searched < unsortedList[half])
		{
			last = half;
			half = half / 2;
		}
		else
		{
			half = half + ((length - half) / 2);
		}

	}
	return -1;
}