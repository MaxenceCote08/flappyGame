#pragma once
#include "Player.h"
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

	void createObstacle(int y);
	void refreshConsole();

	friend ostream & operator << (ostream &out, gameConsole &c);
private:
	Player player;
	char console[MAX_X][MAX_Y];
};