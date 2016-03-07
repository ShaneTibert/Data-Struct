#pragma once
#ifndef _SORTMC_H
#define _SORTMC_H

#include <iostream>

using namespace std;

class SortMC
{
private:
	static int partition(int a[], int left, int right);
	static void mergeSort(int a[], int left, int middle, int right);
public:
	SortMC();
	virtual ~SortMC();
	static int* bubbleSort(int a[], int length);
	static int* selectionSort(int a[], int length);
	int* insertionSort(int a[], int length);
	int* shellSort(int a[], int length);
	static void mergeSort(int a[], int left, int right);

	static void quickSort(int a[], int left, int right);
};

#endif