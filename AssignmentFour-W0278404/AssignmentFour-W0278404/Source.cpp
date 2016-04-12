#include <iostream>
#include <time.h>
#include <conio.h>
#include "BinarySearch.h"
#include "SequentialSearch.h"

using namespace std;
int main()
{
	clock_t starting;
	clock_t ending;

	BinarySearch bs;
	SequentialSearch ss;

	int SequentialArray[1000];

	for (int i=0; i < 1000, i++;){
		SequentialArray[i] = i+1;
	}
	starting = clock();
	ss.search(SequentialArray, 1000, 1000);
	ending = clock();
	cout << "Search Time: " << ending - starting << endl;
	_getch();
}