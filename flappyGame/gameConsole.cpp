#include "gameConsole.h"
#include "Scoreboard.h"

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

	console[12][30] = 'V';
	player.setX(12);
	player.setY(30);
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
	out << "Score : " << c.player.getScore() << endl;

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
	int r;

	srand((unsigned)time(NULL));
	r = (rand() % ((MAX_X - 4) - 4)) + 4;

	//Haut gauche
	for (i = 1; i < r - 2; i++)
	{
		setConsole(i, y, '|');
	}
	//Bas gauche
	for (int j = r + 2; j < MAX_X - 1; j++)
	{
		setConsole(j, y, '|');
	}

	//Haut droit
	for (i = 1; i < r - 2; i++)
	{
		setConsole(i, y + 6, '|');
	}

	//Bas droit
	for (int j = r + 2; j < MAX_X - 1; j++)
	{
		setConsole(j, y + 6, '|');
	}

	//Met les lignes horizontales
	for (int j = y; j <= y + 6; j++)
	{
		setConsole(i, j, '-');
	}
	//Met les lignes horizontales
	for (int j = y; j <= y + 6; j++)
	{
		setConsole(i + 4, j, '-');
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
				if (console[i][j] == 'V')
				{
					tmp[i][j - 1] = ' ';
				}
				else
				{
					tmp[i][j - 1] = console[i][j];
				}
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

	if (tmp[player.getX()][player.getY()] != '|' && tmp[player.getX()][player.getY()] != '-')
	{
		tmp[player.getX()][player.getY()] = 'V';
	}
	else
	{
		player.setDeaths(1);
		
	}

	for (int i = 0; i < MAX_X; i++)
	{
		for (int j = 0; j < MAX_Y; j++)
		{
		 console[i][j] = tmp[i][j];
		}
	}
}
void gameConsole::movePlayerUp()
{
	player.setX(player.getX() - 1);
}
void gameConsole::movePlayerDown()
{
	player.setX(player.getX() + 1);
}
bool gameConsole::isObstacle()
{
	for (int i = 1; i < MAX_X - 1; i++)
	{
		if (console[i][player.getY()] == '|' && console[i][player.getY() + 6] == '|')
		{
			createObstacle(50);
			return true;
		}
	}
}
void gameConsole::setScore()
{
	player.setScore(player.getScore() + 1);
}
void gameConsole::playConsole()
{
	/*char typing;

	createObstacle(50);
	do
	{
		//isObstacle();
		cout << this;
		//sleep_for(milliseconds(250));
		typing = _getch();
		if (typing == ' ')
		{
			movePlayerUp();
		}
		else
		{
			movePlayerDown();
		}
		system("cls");
		refreshConsole();

	} while (typing != 'e');*/
}
bool gameConsole::isDead()
{
	if (player.getDeaths() > 0)
	{
		string name;
		player.setHighscore();
		cout << "Enter your username (max 15 characters)" << endl;
		cin >> name;
		if(name.length()>15)
			name = "UnknownUser";
		player.setName(name);
		myScoreBoard.addScore(player.getInfo());
		myScoreBoard.print();
		return true;
	}
	else
		return false;
}
