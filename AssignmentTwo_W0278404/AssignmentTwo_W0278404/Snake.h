#ifndef _SNAKE_H
#define _SNAKE_H

class Snake
{
private:

public:
	Snake();
	virtual ~Snake();

	int posX;
	int posY;
	int lastMove;
	bool unsolved;
	bool deadEnd;

	void isValidMove(char** maze, int move);
	char** searchAndDistroy(char** maze, int sel, int lines);
	void weNeedBackup(char** maze, int sel, int lines);
};

#endif