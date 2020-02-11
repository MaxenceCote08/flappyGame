#include "gameConsole.h"

//Constructeur and destructeur
gameConsole::gameConsole() {

	for (int i = 0; i < MAX_X; i++)
	{
		for (int j = 0; j < MAX_Y; j++)
		{
			console[i][j] = ' ';
		}
	}

	for (int i = 0; i < MAX_Y; i++)
	{
		console[0][i] = '-';
	}
	for (int i = 0; i < MAX_Y; i++)
	{
		console[MAX_X - 1][i] = '-';
	}

	Player player;
}
gameConsole::~gameConsole() {

}

//Set and Get
char gameConsole::getConsole(int x, int y)
{
	return console[x][y];
}
void gameConsole::setConsole(int x, int y, char c)
{
	console[x][y] = c;
}

//Operator
ostream & operator << (ostream &out, gameConsole &c)
{
	for (int i = 0; i < MAX_X; i++)
	{
		for (int j = 0; j < MAX_Y; j++)
		{
			out << c.getConsole(i, j);
		}
		out << endl;
	}
	return out;
}

//Fonction
void gameConsole::createObstacle(int y)
{
	//Met les lignes verticales
	int i;

	for (i = 1; i < (MAX_X - 6)/2; i++)
	{
		setConsole(i, y, '|');
	}

	for (int j = i + 4; j < MAX_X - 1; j++)
	{
		setConsole(j, y, '|');
	}

	for (i = 1; i < (MAX_X - 6) / 2; i++)
	{
		setConsole(i, y+6, '|');
	}

	for (int j = i + 4; j < MAX_X - 1; j++)
	{
		setConsole(j, y+6, '|');
	}

	//Met les lignes horizontales
	for (int j = y; j <= y + 6; j++)
	{
		setConsole(i, j, '-');
	}
	//Met les lignes horizontales
	for (int j = y; j <= y + 6; j++)
	{
		setConsole(i + 4
, j, '-');
	}

}
void gameConsole::refreshConsole()
{
	char tmp[MAX_X][MAX_Y];
	
	for (int i = 0; i < MAX_X; i++)
	{
		for (int j = 0; j < MAX_Y; j++)
		{
			if (j - 1 > 0)
			{
				tmp[i][j - 1] = console[i][j];
				if (i == 0 || i == MAX_X - 1)
				{
					tmp[i][MAX_Y - 1] = '-';
				}
				else
				{
					tmp[i][MAX_Y - 1] = ' ';
				}
			}
			else
			{
				if (i == 0 || i == MAX_X - 1)
				{
					tmp[i][0] = '-';
				}
				else
				{
					tmp[i][0] = ' ';
				}
			}
		}
	}

	for (int i = 0; i < MAX_X; i++)
	{
		for (int j = 0; j < MAX_Y; j++)
		{
		 console[i][j] = tmp[i][j];
		}
	}
}