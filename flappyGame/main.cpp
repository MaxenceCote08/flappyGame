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
	int i = 0;

	game.createObstacle(50);
	do
	{
		cout << game;
		sleep_for(milliseconds(250));
		system("cls");
		game.refreshConsole();
		i++;
	} while (i < 100);

	cout << endl;
	system("Pause");

	return 0;
}