#pragma once

class Player
{
public:
	Player();
	~Player();

	unsigned int getLives();
	void setLives(unsigned int i);
	unsigned int getScore();
	void setScore(unsigned int i);
	int getX();
	void setX(int i);
	int getY();
	void setY(int i);

private:
	unsigned int lives;
	unsigned int highscore;
	int position_x;
	int position_y;
};
