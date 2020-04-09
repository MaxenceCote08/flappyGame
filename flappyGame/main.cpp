#include "gameConsole.h"
#include <chrono>
#include <thread>
#include "stdio.h"
#include "conio.h"

using namespace std::chrono;
using namespace std::this_thread;

int main()
{
	gameConsole game;
	bool score;
	char typing;

	game.createObstacle(50);
	do
	{
		score = game.isObstacle();
		if (score == true)
		{
			game.setScore();
		}
		cout << game;
		//sleep_for(milliseconds(250));
		typing = _getch();
		if (typing == ' ')
		{
			game.movePlayerUp();
		}
		else
		{
			game.movePlayerDown();
		}
		system("cls");
		game.refreshConsole();

	} while (typing != 'e' && game.isDead() == false);

	cout << game;
	cout << endl;
	system("Pause");

	return 0;
}