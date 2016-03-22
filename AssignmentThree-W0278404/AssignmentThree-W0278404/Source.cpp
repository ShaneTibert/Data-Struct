#include <iostream>
#include <time.h>
#include <conio.h>
#include "SortMC.h"
#include "FileWriter.h"

int main()
{
	int arrayLength = 100000;
	clock_t starting;
	clock_t ending;

	// An unsorted array of random numbers
	static int unsortedArray[100000];

	cout << "Creating Random Number array of "<<arrayLength<<"..." << endl;
	// Populates the array with random numbers between 0 and 32,767
	for (int i = 0; i < arrayLength; i++) {
		unsortedArray[i] = rand();
	}
	cout << "Done" << endl;

	SortMC sort;
	FileWriter fw;
	int temp[100000],mergeTemp[100000];
	copy(unsortedArray, unsortedArray + 100000, temp);
/*
	//Bubble Sort
	cout << "Bubble Sorting..." << endl;
	starting = clock();
	fw.CreateAlgoFile(sort.bubbleSort(temp, arrayLength), "Bubble.txt");
	ending = clock();
	cout << "Done" << endl;
	cout << "Bubble Sort Time: " << ending - starting << endl;

	copy(unsortedArray, unsortedArray + 100000, temp);
	//Selection sort
	cout << "Selection Sorting..." << endl;
	starting = clock();
	fw.CreateAlgoFile(sort.selectionSort(temp, arrayLength), "Selection.txt");
	ending = clock();
	cout << "Done" << endl;
	cout << "Selection Sort Time: " << ending - starting << endl;

	copy(unsortedArray, unsortedArray + 100000, temp);
	//insertion sort
	cout << "insertion Sorting..." << endl;
	starting = clock();
	fw.CreateAlgoFile(sort.insertionSort(temp, arrayLength), "insertion.txt");
	ending = clock();
	cout << "Done" << endl;
	cout << "insertion Sort Time: " << ending - starting << endl;

	copy(unsortedArray, unsortedArray + 100000, temp);
	//shell sort
	cout << "shell Sorting..." << endl;
	starting = clock();
	fw.CreateAlgoFile(sort.shellSort(temp, arrayLength), "shell.txt");
	ending = clock();
	cout << "Done" << endl;
	cout << "shell Sort Time: " << ending - starting << endl;

	copy(unsortedArray, unsortedArray + 100000, temp);
	//merge sort
	cout << "merge Sorting..." << endl;
	starting = clock();
	sort.mergeSort(temp, 0, arrayLength);
	ending = clock();
	fw.CreateAlgoFile(temp, "merge.txt");
	cout << "Done" << endl;
	cout << "merge Sort Time: " << ending - starting << endl;

	copy(unsortedArray, unsortedArray + 100000, temp);
	//quick sort
	cout << "quick Sorting..." << endl;
	starting = clock();
	sort.quickSort(temp, 0, arrayLength);
	ending = clock();
	fw.CreateAlgoFile(temp, "quick.txt");
	cout << "Done" << endl;
	cout << "quick Sort Time: " << ending - starting << endl;*/

	//Create unsorted file
	fw.CreateUnsortedFile(unsortedArray, "unsortedFile.txt");

	//sort the file
	cout << "External Merge Sorting..." << endl;
	starting = clock();
	sort.externalMergeBase();
	ending = clock();
	cout << "Done" << endl;
	cout << "External Merge Sort Time: " << ending - starting << endl;

	getch();
}