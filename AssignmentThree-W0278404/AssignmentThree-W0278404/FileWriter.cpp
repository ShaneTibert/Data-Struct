#include "FileWriter.h"
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include <time.h>

FileWriter::FileWriter()
{
}

FileWriter::~FileWriter()
{
}

void FileWriter::CreateAlgoFile(int sortedList[], char * Filename)
{
	ofstream dataForFile;
	try {

		dataForFile.open(Filename + '.txt');
		dataForFile << "The " << Filename << "Algorythm: " << '\n';
		for (int i = 0; i < 100000; i++) {
			dataForFile << sortedList[i];
		}
		
	}
	catch (exception e) {
		cout << e.what();
	}
	dataForFile.close();
}
