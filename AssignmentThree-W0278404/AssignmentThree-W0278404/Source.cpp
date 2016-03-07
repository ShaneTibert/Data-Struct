#include <iostream>
#include <time.h>

int main()
{
	clock_t starting;
	clock_t ending;
	// Creates a new array to sort
	int unsortedArray[100000];

	// Populates the array with random numbers between 0 and 32,767
	for (int i = 0; i < 100000; i++) {
		unsortedArray[i] = rand();
	}
	starting = clock();

	ending = clock();
}