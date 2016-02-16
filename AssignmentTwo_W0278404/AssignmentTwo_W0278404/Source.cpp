#include <iostream>
#include <conio.h>
#include <fstream>
#include "Snake.h"

using namespace std;

int sel = 0;
int lines = 0;

char** filename = new char *[255];
char** maze = new char *[255];

void mainDisplay();
void readFromFile(char**);
void help();
void saveToFile();

int main(int argc, char** argv) {
	if (argc > 1) {
		readFromFile(argv);
	}

	mainDisplay();
	_getch();

	Snake solid;
	maze = solid.searchAndDistroy(maze,lines,sel);
	mainDisplay();
	cout << "Problem Solved!" << endl;

	saveToFile();
	_getch();
	return 0;

}

void mainDisplay()
{
	system("cls");
	for (int i = 0; i < lines; i++) {
		for (int c=0; c < sel; c++) {
			cout << maze[i][c];
		}
		cout << endl;
	}

}

void readFromFile(char** filename) {

	ifstream read;

	try {
		if (filename[1] != nullptr)
		{
			read.open(filename[1]);
			char i = ' ';
			
			if (read.is_open()) {
				char i = ' ';
				char *vals = new char[255];
				while (!read.eof()) {
					i = read.get();
					if (i == '\n') {
						vals[sel] = '\0';
						maze[lines] = vals;
						lines++;
						vals = new char[255];
						sel = 0;
					}
					else { vals[sel] = i; sel++; }
				}
				maze[lines] = vals;
				lines++;
			}
			
		}
	}
	catch (exception e) {
		cout << e.what();
	}
	read.close();
}
void saveToFile(){

	// saves data to a specified file.
	ofstream dataForFile;
	try {

		dataForFile.open("output.txt");
		dataForFile << "The finished maze: " << '\n';
		for (int i = 0; i < lines; i++) {
			for (int c = 0; c < sel; c++) {
				if (maze[i][c] == 'X'){
					maze[i][c] = ' ';
				}
				dataForFile << maze[i][c];
			}
			dataForFile <<'\n';
		}
	}
	catch (exception e) {
		cout << e.what();
	}
	dataForFile.close();

}

		/*dataForFile.open(filename);
		dataForFile << "The Saved Combo is: ";
		for (int i = 0; i < 7; i++) {
			if (i & 1) {

				cout << "R" << val[i];

			}
			else {
				if (sel == i) {
					cout << ">" << "L" << val[i] << "<";
				}
				else cout << "L" << val[i];
			}
		}
		cout << "File Succesfully Saved" << endl;
	}
	catch (exception e) {
		cout << e.what();
	}
	dataForFile.close();*/