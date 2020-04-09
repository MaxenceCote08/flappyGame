#include <QApplication>
#include "MenuWindow.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	
	MenuWindow window;

	return app.exec();
}