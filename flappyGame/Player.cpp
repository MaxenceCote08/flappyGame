#include "Player.h"

//SET AND GET
unsigned int Player::getLives()
{
	return lives;
}
void Player::setLives(unsigned int i)
{
	lives = i;
}
unsigned int Player::getScore()
{
	return highscore;
}
void Player::setScore(unsigned int i)
{
	highscore = i;
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

//Constructeur and destructeur

Player::Player() : lives(0), highscore(0) {

}

Player::~Player(){

}