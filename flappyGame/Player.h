#pragma once

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

private:
	unsigned int deaths;
	unsigned int highscore;
	int position_x;
	int position_y;
};
