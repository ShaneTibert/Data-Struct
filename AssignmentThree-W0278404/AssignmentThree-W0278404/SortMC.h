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
	static void bubbleSort(int a[], int length);
	static void selectionSort(int a[], int length);
	void insertionSort(int a[], int length);
	void shellSort(int a[], int length);
	static void mergeSort(int a[], int left, int right);

	static void quickSort(int a[], int left, int right);
};

#endif