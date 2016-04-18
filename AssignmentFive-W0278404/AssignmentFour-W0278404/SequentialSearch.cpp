#include "SequentialSearch.h"
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include <time.h>


SequentialSearch::SequentialSearch(){}
SequentialSearch::~SequentialSearch(){}
int SequentialSearch::search(int unsortedList[], int length,int searched){
	for (int i = 0; i < length; i++){
		if (unsortedList[i] == searched){
			return i;
		}
	}
	return 0;
}