#pragma once
#include "Player.h"
#include <math.h>
#include <iostream>
#include <algorithm>
#include <fstream>

class scoreboard
{
public:
	scoreboard();
	void addScore(playerInfo myScore);
	string getName(int position); // pas code encore
	int getScore(int position); // pas code encore
	void print();
	playerInfo& operator[](int position);

private:
	playerInfo scores[10];
};