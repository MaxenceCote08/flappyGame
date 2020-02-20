#include "Player.h"

//SET AND GET
unsigned int Player::getDeaths()
{
	return deaths;
}
void Player::setDeaths(unsigned int i)
{
	deaths = i;
}
unsigned int Player::getScore()
{
	return score;
}
void Player::setScore(unsigned int i)
{
	score = i;
}
int Player::getX()
{
	return position_x;
}
void Player::setX(int i)
{
	position_x = i;
}
int Player::getY()
{
	return position_y;
}
void Player::setY(int i)
{
	position_y = i;
}

void Player::setHighscore()
{
		info.highscore = score;
}

void Player::setName(string name)
{
	info.name = name;
}

playerInfo Player:: getInfo()
{
	return info;
}

//Constructeur and destructeur

Player::Player() : deaths(0), score(0), position_x(12), position_y(30) {

}

Player::~Player(){

}