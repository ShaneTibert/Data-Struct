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

		dataForFile.open(Filename);
		dataForFile << "The " << Filename << " Algorythm: " << '\n';
		for (int i = 0; i < 100000 - 1; i++) {
			dataForFile << " " <<sortedList[i] << ',' ;
		}
		
	}
	catch (exception e) {
		cout << e.what();
	}
	dataForFile.close();
}
void FileWriter::CreateUnsortedFile(int unsortedList[], char * Filename)
{
	ofstream dataForFile;
	try {

		dataForFile.open(Filename);
		for (int i = 0; i < 100000 - 1; i++) {
			dataForFile << unsortedList[i] << ',' << i+1 << ';';
		}

	}
	catch (exception e) {
		cout << e.what();
	}
	dataForFile.close();
}
void FileWriter::CreateMergeFile(int** unsortedList, char * Filename)
{
	ofstream dataForFile;
	try {

		dataForFile.open(Filename);
		for (int i = 0; i < 1000 - 1; i++) {
			dataForFile << unsortedList[0][i] << ',' << unsortedList[1][i] << ';';
		}

	}
	catch (exception e) {
		cout << e.what();
	}
	dataForFile.close();
}
