#include <iostream>
#include <fstream>
#include "SortMC.h"
#include "FileWriter.h"
#include <Conio.h>

using namespace std;

int arraysize = 100000;
int temp[100000];
int extTemp[2][1000];
int externalSortSize = 1000;

SortMC::SortMC()
{

}
SortMC::~SortMC()
{

}
int* SortMC::bubbleSort(int a[], int length) {
	int outer, inner;
	for (outer = length - 1; outer > 0; outer--)
	{ // counting down
		for (inner = 0; inner < outer; inner++)
		{ // bubbling up
			if (a[inner] > a[inner + 1])
			{ // if out of order...swap
				int temp = a[inner];
				a[inner] = a[inner + 1];
				a[inner + 1] = temp;
			}
		}
	}
	return a;
}
int* SortMC::selectionSort(int a[], int length) {
	int outer, inner, min;
	for (outer = 0; outer < length - 1; outer++)
	{ // outer counts down
		min = outer;
		for (inner = outer + 1; inner < length; inner++)
		{
			if (a[inner] < a[min]) {
				min = inner;
			}
		}
		// a[min] is least among a[outer]..a[a.length - 1]
		int temp = a[outer];
		a[outer] = a[min];
		a[min] = temp;
	}
	return a;
}
int* SortMC::insertionSort(int a[], int length)
	{
		int i, j, tmp;
		for (i = 1; i < length; i++)
		{
			j = i;
			while (j > 0 && a[j - 1] > a[j])
			{
				tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
				j--;
			} //end of while loop
		} //end of for loop
		return a;
	}
int* SortMC::shellSort(int a[], int length)
{
	int i, j, increment, temp;
	for (increment = length / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i<length; i++)
		{
			temp = a[i];
			for (j = i; j >= increment; j -= increment)
			{
				if (temp < a[j - increment])
				{
					a[j] = a[j - increment];
				}
				else
				{
					break;
				}
			}
			a[j] = temp;
		}
	}
	return a;
}

void SortMC::mergeSort(int a[], int left, int middle, int right){
	// creates temp array and needed variables
	int i, left_end, num_elements, tmp_pos;

	left_end = (middle);
	tmp_pos = left;
	num_elements = (right - left + 1);

	for (i = 0; tmp_pos < middle && left_end < right; i++)
		if (a[tmp_pos] <=a[left_end])
			temp[i] = a[tmp_pos++];
		else
			temp[i] = a[left_end++];
	for ( ; tmp_pos < middle; i++)
		temp[i] = a[tmp_pos++];
	for ( ; left_end < right; i++)
		temp[i] = a[left_end++];
	for (int index = 0; index < right - left; index++)
		a[left + index] = temp[index];
}
void SortMC::mergeSort(int a[], int left, int right){

	if (right - left > 1)
	{
		// Middle for splitting
		int mid = (right + left) / 2;

		//sorts left, recursivly
		mergeSort(a, left, mid);

		//sorts Right, recursivly
		mergeSort(a, (mid), right);

		mergeSort(a, left, (mid), right);
	}
}
void SortMC::quickSort(int a[], int left, int right)
{
	int middle;

	if (left < right)
	{
		middle = partition(a, left, right);
		quickSort(a, left, middle - 1);
		quickSort(a, middle + 1, right);
	}
}
int SortMC::partition(int a[], int left, int right)
{
	int  index = left;
	int temp;
	int middle = a[left];

	for (int i = left + 1; i <= right; i++)
	{
		if (a[i] <= middle)
		{
			index++;
			temp = a[i];
			a[i] = a[index];
			a[index] = temp;
		}
	}
	temp = a[index];
	a[index] = a[left];
	a[left] = temp;

	return index;
}
void SortMC::externalMergeSort(int a[2][1000], int left, int middle, int right) {
	// creates temp array and needed variables
	int i, left_end, num_elements, tmp_pos;

	left_end = (middle);
	tmp_pos = left;
	num_elements = (right - left + 1);

	for (i = 0; tmp_pos < middle && left_end < right; i++)
		if (a[0][tmp_pos] <= a[0][left_end]) {
			extTemp[0][i] = a[0][tmp_pos];
			extTemp[1][i] = a[1][tmp_pos++];
		}
		else {
			extTemp[0][i] = a[0][left_end];
			extTemp[1][i] = a[1][left_end++];
		}
	for (; tmp_pos < middle; i++) {
		extTemp[0][i] = a[0][tmp_pos];
		extTemp[1][i] = a[1][tmp_pos++];
	}
	for (; left_end < right; i++) {
		extTemp[0][i] = a[0][left_end];
		extTemp[1][i] = a[1][left_end++];
	}
	for (int index = 0; index < right - left; index++) {
		a[0][left + index] = extTemp[0][index];
		a[1][left + index] = extTemp[1][index];
	}
}
void SortMC::externalMergeSort(int a[2][1000], int left, int right) {

	if (right - left > 1)
	{
		// Middle for splitting
		int mid = (right + left) / 2;

		//sorts left, recursivly
		externalMergeSort(a, left, mid);

		//sorts Right, recursivly
		externalMergeSort(a, (mid), right);

		externalMergeSort(a, left, (mid), right);
	}
}
void SortMC::externalMergeBase() {
	int unsorted[2][1000];
	ifstream read;
	ifstream firstRead;
	ifstream secondRead;
	ifstream secondFirstRead;
	ifstream secondSecondRead;
	FileWriter fw;
	ofstream firstFile;
	ofstream secondFile;
	ofstream secondFirstFile;
	ofstream secondSecondFile;
	ofstream sortedFile;

	try {
		read.open("unsortedFile.txt");
		firstFile.open("firstFile.txt");
		secondFile.open("secondFile.txt");
		char i = NULL;
		string tempC;
			int index = 0;
			bool line = false;
			bool first = true;
			bool secondfirst = true;
			if (read.is_open()) {
				while (!read.eof()) {
					i = read.get();

					if (i != ';'&&i != ',') {
						tempC += i;
					}
					else {
						if (!line) {
							unsorted[0][index] = atoi(tempC.c_str());
							tempC = "";
						}
						else if (line) {
							unsorted[1][index] = atoi(tempC.c_str());
							tempC = "";
						}
					}


					if (i == ';') {
						index++;
						line = false;
					}
					else if (i == ',') 
						line = true;

					if (index == 1000-1) {
						externalMergeSort(unsorted, 0, 1000);
						if (!first) {
							for (int i = 0; i < 1000; i++) {
								secondFile << unsorted[0][i] << ',' << unsorted[1][i] << ';';
							}
							first = true;
						}
						else {
							for (int i = 0; i < 1000; i++) {
								firstFile << unsorted[0][i] << ',' << unsorted[1][i] << ';';
							}
							first = false;
						}
						index = 0;
					}
				}
			}
			index = 0;
			read.close();
			firstFile.close();
			secondFile.close();
			first = true;
			line = false;
			index = 0;
			secondFirstFile.open("secondFirstFile.txt");
			secondSecondFile.open("secondSecondFile.txt");
			firstRead.open("firstFile.txt");
			secondRead.open("secondFile.txt");
			if (secondRead.is_open()&&firstRead.is_open()) {
				while (!firstRead.eof()&& !secondRead.eof()) {

					if (!first) {
						i = secondRead.get();
					}
					else {
						i = firstRead.get();
					}


					if (i != ';'&&i != ',') {
						tempC += i;
					}
					else {
						if (i == ',') {
							unsorted[0][index] = atoi(tempC.c_str());
							tempC = "";
						}
						else if (i == ';') {
							unsorted[1][index] = atoi(tempC.c_str());
							tempC = "";
							first = !first;
							index++;
						}
					}

					if (index == 1000 - 1) {
						externalMergeSort(unsorted, 0, 1000);
						if (secondfirst) {
							for (int i = 0; i < 1000 - 1; i++) {
								secondSecondFile << unsorted[0][i] << ',' << unsorted[1][i] << ';';
							}
							secondfirst = false;
						}
						else {
							for (int i = 0; i < 1000 - 1; i++) {
								secondFirstFile << unsorted[0][i] << ',' << unsorted[1][i] << ';';
							}
							secondfirst = true;
						}
						index = 0;
					}

				}
			}
			secondRead.close();
			firstRead.close();
			secondSecondFile.close();
			secondFirstFile.close();

			first = true;
			secondFirstRead.open("secondFirstFile.txt");
			secondSecondRead.open("secondSecondFile.txt");
			sortedFile.open("sortedFile.txt");
			if (secondSecondRead.is_open()) {
				while (!secondFirstRead.eof() && !secondSecondRead.eof()) {

					if (!first) {
						i = secondSecondRead.get();
					}
					else {
						i = secondFirstRead.get();
					}


					if (i != ';'&&i != ',') {
						tempC += i;
					}
					else {
						if (i == ',') {
							unsorted[0][index] = atoi(tempC.c_str());
							tempC = "";
						}
						else if (i == ';') {
							unsorted[1][index] = atoi(tempC.c_str());
							tempC = "";
							index++;
							first = !first;
						}
					}

					if (index == 1000 - 1) {
						externalMergeSort(unsorted, 0, 1000);
							for (int i = 0; i < 1000 - 1; i++) {
								sortedFile << unsorted[0][i] << ',' << unsorted[1][i] << ';';
							}
						index = 0;
					}

				}
			}

	}
	catch (exception e) {
		cout << e.what();
	}
}