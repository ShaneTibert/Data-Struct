#pragma once
#ifndef _FILEWRITER_H
#define _FILEWRITER_H

#include <iostream>

using namespace std;

class FileWriter
{
private:

public:
	FileWriter();
	virtual ~FileWriter();
	static void CreateAlgoFile(int sortedList[], char* Filename);
	static void CreateUnsortedFile(int unsortedList[], char* Filename);
	static void CreateMergeFile(int** unsortedList, char* Filename);
};

#endif