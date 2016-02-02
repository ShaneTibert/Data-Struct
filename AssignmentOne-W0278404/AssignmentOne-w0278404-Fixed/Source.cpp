#include <iostream>
#include <conio.h>
#include <fstream>
#include "List.h"

// Shane.J.Tibert - W0278404
// Class PROG2400

using namespace std;

int currentlySelected = 6;
int value[7];

char** filename;

bool saveBool = false;
bool run = true;

// creates a list to use with the program
List Lock;

void mainDisplay();
void commands(char arg, int value);
void helpScreen();
void saveToFile();

//main take any arg and uses it as the save file
int main(int args, char** fileArg) {

	if (args > 1) {
		filename = fileArg;
	}

	currentlySelected = 1;

	// uses a 16 char long array to recieve input
	char input[16];
	char inCommand;

	int value = 0;

	mainDisplay();

	while (run) {
		value = 0;

		cout << ">";

		cin.getline(input, 16);

		inCommand = input[0];

		// checks if the value entered is correct
		if (input[1] == ' ') {
			if (isdigit(input[2])) {

				value = 0;

				// values of input are ascii, -48 corrects the values nicely
				if (isdigit(input[3])) {
					value = (((int)input[2]-48) * 10) + ((int)input[3] - 48);
				}
				else{
					value = (int)input[2] - 48;
				}
			}
		}
		commands(inCommand, value);
	}

	// checks if the user has pressed e, and if an arg was given
	if (saveBool == true && args > 1){
		saveToFile();
	}
}

void commands(char arg, int value)
{
	// deletes the currently selected item (sets to zero)
	if (toupper(arg) == 'D'){
		Lock.DeletePosition(currentlySelected);
		mainDisplay();
	}
	// resets the entire linked list
	else if (toupper(arg) == 'R'){
		Lock.DeleteAll();
		mainDisplay();
	}
	// goes to a certain link
	else if (toupper(arg) == 'G'){
		if (value > 0 && value < 8){
			currentlySelected = value;
			mainDisplay();
		}
		else cout << "Invalueid Value to goto" << endl;
	}
	// exits with saving
	else if (toupper(arg) == 'E'){
		run = false;
		saveBool = true;
	}
	// subsitutes current value
	else if (toupper(arg) == 'S'){
		if (value > -1) {
			if (value < 50){
				Lock.InsertAtPosition(currentlySelected, value);
				mainDisplay();
			}
		}
		else
		{
			// if its out of range, display error
			mainDisplay();
			cout << "please enter a valid number" << endl;
		}
	}
	// quits without saving
	else if (toupper(arg) == 'Q'){
		run = false;
	}
	// starts help
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
		value[i] = Lock.RetrievePosition(i + 1);
	}
	// very nice display if i do say so myself :)
	cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191 << endl;
	cout << (char)179 << "                Combination Lock                  " << (char)179 << endl;
	cout << (char)179 << "           type help for more details             " << (char)179 << endl;
	cout << (char)179 << "                                                  " << (char)179 << endl;
	cout << (char)179 << "                                                  " << (char)179 << endl;
	cout << (char)179 << "                                                  " << (char)179 << endl;
	cout << (char)179 << "         ";
	// chunks through a for loop printing Rs on odd interations and Ls on evens
	for (int i = 0; i < 7; i++) {
		cout << " ";
		if (i & 1) {
			if (currentlySelected == i+1) {
				cout << ">" << "L" << value[i] << "<";
			}
			else cout << "L" << value[i];
			
		}
		else {
			if (currentlySelected == i +1) {
				cout << ">" << "R" << value[i] << "<";
			}
			else cout << "R" << value[i];
		}
	}
	cout   << "                  " << (char)179 << endl;
	cout << (char)179 << "                                                  " << (char)179 << endl;
	cout << (char)179 << "                                                  " << (char)179 << endl;
	cout << (char)179 << "                                                  " << (char)179 << endl;
	cout << (char)179 << "                                                  " << (char)179 << endl;
	cout << (char)179 << "                                                  " << (char)179 << endl;
	cout << (char)192 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)217 << endl;
}
void helpScreen()
{
	cout << "D = Delete | R = Reset | E = Exit And Save                |" << endl;
	cout << "G (value[1-7]) = Goto | S (value[1-49]) = Subsitue        | " << endl; 
	cout << "Q = Quit And Do Not Save                                  |" << endl;
	cout << "If no value is given, the commands that require a    " << endl;
	cout << "will not work." << endl;
	cout << "" << endl;
	cout << "Remember to include a space between the command and value!." << endl;

	_getch();
}
void saveToFile(){

	// saves data to a specified file.
		ofstream dataForFile;
	try {

		dataForFile.open(filename[1]);
		dataForFile << "The Saved Lock is: ";
		for (int i = 0; i < 7; i++) {
			if (i & 1) {
				dataForFile << "L" << value[i];
			}
			else {
				dataForFile << "R" << value[i];
			}
		}
		cout << "File Succesfully Saved" << endl;
	}
	catch (exception e) {
		cout << e.what();
	}
	dataForFile.close();
	
}