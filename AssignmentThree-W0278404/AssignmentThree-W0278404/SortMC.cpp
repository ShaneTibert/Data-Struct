#include <iostream>
#include "SortMC.h"

using namespace std;


SortMC::~SortMC()
{

}
void SortMC::bubbleSort(int a[], int length) {
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
}
void SortMC::selectionSort(int a[], int length) {
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
}
void SortMC::insertionSort(int a[], int length)
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
	}
void SortMC::shellSort(int a[], int length)
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
}
void SortMC::mergeSort(int a[], int left, int middle, int right){
	int temp[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int i, left_end, num_elements, tmp_pos;

	left_end = (middle - 1);
	tmp_pos = left;
	num_elements = (right - left + 1);

	while ((left <= left_end) && (middle <= right))
	{
		if (a[left] <= a[middle])
			temp[tmp_pos++] = a[left++];
		else
			temp[tmp_pos++] = a[middle++];
	}

	while (left <= left_end)
		temp[tmp_pos++] = a[left++];

	while (middle <= right)
		temp[tmp_pos++] = a[middle++];

	for (i = 0; i < num_elements; i++)
	{
		a[right] = temp[right];
		right--;
	}
}
void SortMC::mergeSort(int a[], int left, int right){

	if (right > left)
	{
		int mid = (right + left) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, (mid + 1), right);

		mergeSort(a, left, (mid + 1), right);
	}
}