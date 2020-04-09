#include "Scoreboard.h"

scoreboard::scoreboard()
{
	ifstream nomFichier("highscore.txt", ios::in);

	if(nomFichier.is_open())
	{
		int i = 0;
		std::string line;
		while (getline(nomFichier, line))
		{
			nomFichier >> scores[i].name >> scores[i].highscore;
			i++;
		}
		nomFichier.close();
	}
	else
	{
		std::cout << "Impossible douvrir le scoreboard" << endl;
		system("pause");
	}
}

playerInfo& scoreboard:: operator[](int position)
{
	return scores[position];
}

void scoreboard::addScore(playerInfo myScore)
{
	for (int i = 0; i < 10; i++)
	{
		if (myScore.highscore > scores[i].highscore)
		{
			for (int j = 9; j >= i ; j--)
			{
				scores[j] = scores[j-1];
			}
			scores[i] = myScore;
			break;
		}
	}

	ofstream fichierSortie("highscore.txt", ios::out);

	if (fichierSortie.is_open())
	{
		fichierSortie << "//NE PAS MODIFIER CE FICHIER\\" << endl;
		for (int i = 0; i < 10; i++)
		{
			fichierSortie << scores[i].name << " " << scores[i].highscore << endl;
		}
		fichierSortie.close();
	}
	else
	{
		std::cout << "Impossible douvrir le scoreboard" << endl;
		system("pause");
	}
}

void scoreboard::print()
{
	system("cls");
	cout << "+------------------------------------------------------------------------+" << endl
		 << "|                             SCOREBOARD                                 |" << endl
		 << "+------------------------------------------------------------------------+" << endl
	   	 << "|               Name                |               Score                |" << endl
		 << "+------------------------------------------------------------------------+" << endl
		;

	for (int i = 0; i < 10; i++) // PLZ MAXENCE DIS MOI QUE YA UNE FACON PLUS SIMPLE DE FAIRE UN BEAU TABLEAU
	{	
		string spaces_name = "                "; 
		string spaces_score = "                ";

		int count_spaces = scores[i].name.length();
		if (count_spaces > 4)
		{
			for (int i = 0; i < count_spaces-4; i++)
			{
				spaces_name.pop_back();
			}
		}
		else if (count_spaces < 4)
		{
			for (int i = 0; i < 4 - count_spaces; i++)
			{
				spaces_name+=' ';
			}
		}

		count_spaces = (int)log10(scores[i].highscore) + 1;

		if (count_spaces < 5)
		{
			for (int i = 0; i < 5-count_spaces; i++)
			{
				spaces_score+=' ';
			}
		}
		else if (count_spaces > 5)
		{
			for (int i = 0; i < count_spaces - 5; i++)
			{
				spaces_name.pop_back();
			}
		}

		cout << "|               " << scores[i].name << spaces_name << "|               " << scores[i].highscore << spaces_score << "|" << endl;
	}
	cout << "+------------------------------------------------------------------------+" << endl;
	system("pause");
	system("cls");
}