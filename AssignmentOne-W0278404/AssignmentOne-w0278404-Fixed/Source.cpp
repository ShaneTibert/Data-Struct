#include <iostream>
#include <conio.h>
#include <fstream>
#include "List.h"

using namespace std;

int currentlySelected = 6;
int value[7];

char** filename;

bool saveBool = false;
bool run = true;

List combo;

void mainDisplay();
void commands(char arg, int value);
void helpScreen();

int main(int argc, char** argv) {
	if (argc > 1) {
		filename[0] = argv[0];
	}
	char** filename = argv;
	currentlySelected = 1;

	char input[4];
	char inCommand;

	int value = 0;

	mainDisplay();

	while (run) {
		value = 0;

		cout << ">>";

		cin.getline(input, 16);

		inCommand = input[0];

		if (input[1] == ' ') {
			if (isdigit(input[2])) {

				value = 0;

				if (input[2] == '1') {
					value += 10;
				}
				if (input[2] == '2') {
					value += 20;
				}
				if (input[2] == '3') {
					value += 30;
				}
				if (input[2] == '4') {
					value += 40;
				}
				if (input[2] == '5') {
					value += 50;
				}
				if (input[2] == '6') {
					value += 60;
				}
				if (input[2] == '7') {
					value += 70;
				}
				if (input[2] == '8') {
					value += 80;
				}
				if (input[2] == '9') {
					value += 90;
				}
				if (isdigit(input[3])) {
					value += input[3] - 48;
				}
				else {
					value = value / 10;
				}
			}
		}
		commands(inCommand, value);
	}
}

void commands(char arg, int value)
{
	if (toupper(arg) == 'D'){
		combo.DeletePosition(currentlySelected - 1);
		mainDisplay();
	}
	else if (toupper(arg) == 'R'){
		combo.DeleteAll();
		mainDisplay();
	}
	else if (toupper(arg) == 'G'){
		if (value > 0 && value < 8){
			currentlySelected = value - 1;
		}
		else cout << "Invalueid Value to goto" << endl;
	}
	else if (toupper(arg) == 'E'){
		run = false;
		saveBool = true;
	}
	else if (toupper(arg) == 'S'){
		if (value > -1) {
			if (value < 50){
				combo.InsertAtPosition(currentlySelected, value);
				mainDisplay();
			}
		}
		else
		{
			mainDisplay();
			cout << "please enter a value id number (0-49)" << endl;
		}
	}
	else if (toupper(arg) == 'Q'){
		run = false;
	}
	else if (toupper(arg) == 'H'){
		helpScreen();
		mainDisplay();
	}
}

void mainDisplay() 
{
	system("cls");

	for (int i = 0; i < 7; i++)
	{
		value[i] = combo.RetrievePosition(i + 1);
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
			if (currentlySelected == i) {
				cout << ">" << "R" << value[i] << "<";
			}
			else cout << "R" << value[i];
			
		}
		else {
			if (currentlySelected == i) {
				cout << ">" << "L" << value[i] << "<";
			}
			else cout << "L" << value[i];
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

				cout << "R" << value[i];

			}
			else {
				if (currentlySelected == i) {
					cout << ">" << "L" << value[i] << "<";
				}
				else cout << "L" << value[i];
			}
		}
		cout << "File Succesfully Saved" << endl;
	}
	catch (exception e) {
		cout << e.what();
	}
	dataForFile.close();
	
}