/*
  APP7 - Informatique : interfaces graphiques

  Universit� de sherbrooke - G�nie informatique

	�mile Chartray � chae3211
	Maxence C�t� � cotm3032
	Jonathan Degoede � degj2706
	Martin Giroux � girm1002
*/

#include <QApplication>
#include "MenuWindow.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	
	MenuWindow window;

	return app.exec();
}