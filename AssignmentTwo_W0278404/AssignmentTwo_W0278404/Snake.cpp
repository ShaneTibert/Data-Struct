#include <iostream>
#include <conio.h>
#include "Snake.h"
#include "Jenga.h"

using namespace std;

int posX;
int posY;

int lastMove;
bool unsolved;
bool deadEnd;

Jenga path;

void isValidMove(char** maze, int move);
void weNeedBackup(char** maze, int sel, int lines);

Snake::Snake(){

}
Snake::~Snake(){

}

char** Snake::searchAndDistroy(char** maze, int sel, int lines){
	posX = 1;
	posY = 1;
	lastMove = 0;

	deadEnd = false;
	unsolved = true;

	path.Push(posX, posY);
	while (unsolved == true){
		int posXDelta;
		int posYDelta;

		for (int i = 0; i < 4; i++){
			posXDelta = posX;
			posYDelta = posY;
			isValidMove(maze, i);
			if (posXDelta != posX || posYDelta != posY){
				break;
			}
		}
		if (posXDelta == posX && posYDelta == posY){
			if (posX == sel-1 && posY == lines - 1){
				unsolved = false;
				break;
			}
			deadEnd = true;
			weNeedBackup(maze, sel, lines);

		}
		
		/*system("cls");
		for (int i = 0; i < lines; i++) {
			for (int c = 0; c < sel; c++) {
				cout << maze[i][c];
			}
			cout << endl;
		}
		_getch();*/

		if (posX == sel-2 && posY == lines - 2){
			unsolved = false;
		}
	}
	return maze;
}
void Snake::isValidMove(char** maze, int move){
	if (move == 0 && maze[posY][posX+1] == ' '){
		posX++;
		maze[posY][posX-1] = '#';
		path.Push(posX-1, posY);
		deadEnd = false;
	}
	else if (move == 1 && maze[posY+1][posX] == ' '){
		posY++;
		maze[posY-1][posX] = '#';
		path.Push(posX, posY-1);
		deadEnd = false;
	}
	else if (move == 2 && maze[posY][posX - 1] == ' '){
		posX--;
		maze[posY][posX+1] = '#';
		path.Push(posX+1, posY);
		deadEnd = false;
	}
	else if (move == 3 && maze[posY-1][posX] == ' '){
		posY--;
		maze[posY+1][posX] = '#';
		path.Push(posX, posY+1);
		deadEnd = false;
	}
}
void Snake::weNeedBackup(char** maze, int sel, int lines){
	while (deadEnd == true){
		if (posX == sel&&posY == lines - 1){
			unsolved = false;
		}
		maze[posY][posX] = 'X';
		posX = path.PeekX();
		posY = path.PeekY();
		maze[posY][posX] = 'X';
		path.Pop();
		posX = path.PeekX();
		posY = path.PeekY();
		for (int c = 0; c < 4; c++){
			isValidMove(maze, c);
			if (deadEnd == false){
				break;
			}
		}
	}
}