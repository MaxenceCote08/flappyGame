#pragma once
#include "Player.h"
#include "conio.h"
#include <time.h>
#include <iostream>

using namespace std;

#define MAX_X 24
#define MAX_Y 72

class gameConsole
{
public:
	gameConsole();
	~gameConsole();

	char getConsole(int x, int y);
	void setConsole(int x, int y, char c);
	void setScore();
	void playConsole();
	bool isDead();
	void createObstacle(int y);
	bool isObstacle();
	void refreshConsole();
	void movePlayerUp();
	void movePlayerDown();
	friend ostream & operator << (ostream &out, gameConsole &c);
private:
	Player player;
	char console[MAX_X][MAX_Y];
};