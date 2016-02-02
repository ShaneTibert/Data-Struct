#include <iostream>
#include <conio.h>
#include <fstream>
#include "List.h"

using namespace std;

int sel = 6;
int val[7];

char** filename;

bool saveflag = false;
bool run = true;

List combo;

void display();
void commands(char arg, int val);
void help();

int main(int argc, char** argv) {
	if (argc > 1) {
		filename[0] = argv[0];
	}
	char** filename = argv;
	sel = 1;

	char input[4];
	char cmd;
	char** filename = argv;

	int val = 0;

	display();

	while (run) {
		val = 0;

		cout << ">>";

		cin.getline(input, 16);

		cmd = input[0];

		if (input[1] == ' ') {
			if (isdigit(input[2])) {

				val = 0;

				if (input[2] == '1') {
					val += 10;
				}
				if (input[2] == '2') {
					val += 20;
				}
				if (input[2] == '3') {
					val += 30;
				}
				if (input[2] == '4') {
					val += 40;
				}
				if (input[2] == '5') {
					val += 50;
				}
				if (input[2] == '6') {
					val += 60;
				}
				if (input[2] == '7') {
					val += 70;
				}
				if (input[2] == '8') {
					val += 80;
				}
				if (input[2] == '9') {
					val += 90;
				}
				if (isdigit(input[3])) {
					val += input[3] - 48;
				}
				else {
					val = val / 10;
				}
			}
		}
		commands(cmd, val);
	}
}

void commands(char arg, int val)
{
}

void mainDisplay() 
{
	system("cls");

	for (int i = 0; i < 7; i++)
	{
		val[i] = combo.RetrievePosition(i + 1);
	}

	cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191 << endl;
	cout << (char)179 << "                                        " << (char)179 << endl;
	cout << (char)179 << "                                        " << (char)179 << endl;
	cout << (char)179 << "                                        " << (char)179 << endl;
	cout << (char)179 << "                                        " << (char)179 << endl;
	cout << (char)179 << "                                        " << (char)179 << endl;

	// chunks through a for loop printing Rs on odd interations and Ls on evens
	for (int i = 0; i < 7; i++) {
		if (i & 1) {
			if (sel == i) {
				cout << ">" << "R" << val[i] << "<";
			}
			else cout << "R" << val[i];
			
		}
		else {
			if (sel == i) {
				cout << ">" << "L" << val[i] << "<";
			}
			else cout << "L" << val[i];
		}
	}
	cout << (char)179 << "                                        " << (char)179 << endl;
	cout << (char)179 << "                                        " << (char)179 << endl;
	cout << (char)179 << "                                        " << (char)179 << endl;
	cout << (char)179 << "                                        " << (char)179 << endl;
	cout << (char)179 << "                                        " << (char)179 << endl;
}
void helpScreen()
{
	cout << "D = Delete | R = Reset | E = Exit And Save" << endl;
	cout << "G = Goto | S = Subsitute | Q = Quit And Do Not Save" << endl;

	_getch();
}
void saveToFile(string filename){


		ofstream dataForFile;
	try {

		dataForFile.open(filename);
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
	dataForFile.close();
	
}