#include <iostream>
#include <conio.h>
#include "Chain.h"

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

	sel = 1;

	char input[16];
	char cnd;

	int val = 0;

	display();

	while (run) {
		val = 0;

		cout << ">>";
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
		val[i] = combo.RetrivePosition(i + 1);
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
void saveToFile(){

}