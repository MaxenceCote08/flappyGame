/*
  APP7 - Informatique : interfaces graphiques

  Université de sherbrooke - Génie informatique

	Émile Chartray – chae3211
	Maxence Côté – cotm3032
	Jonathan Degoede – degj2706
	Martin Giroux – girm1002
*/

#include <QApplication>
#include "MenuWindow.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	
	MenuWindow window;

	return app.exec();
}