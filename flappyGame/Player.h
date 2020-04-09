#pragma once
#include <string>
#include <iostream>


using namespace std;

struct playerInfo
{
	std::string name;
	int highscore;
};

class Player
{
public:
	Player();
	~Player();

	unsigned int getDeaths();
	void setDeaths(unsigned int i);
	unsigned int getScore();
	void setScore(unsigned int i);
	int getX();
	void setX(int i);
	int getY();
	void setY(int i);
	void setHighscore();
	void setName(string name);
	playerInfo getInfo();

private:
	unsigned int deaths;
	unsigned int score;
	int position_x;
	int position_y;
	playerInfo info;
};
