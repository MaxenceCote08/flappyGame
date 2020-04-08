#include "GameWindow.h"

GameWindow::GameWindow()
{
	//Creation de la scene graphique
	view = new QGraphicsView(this);
	view->setFixedSize(width,height);
	view->setSceneRect(0, 0, width, height);

	//Ajout fond scene
	auto background = QBrush(QImage("./Images/background.jpg").scaled(width,height));
	view->setBackgroundBrush(background);

	//Creation objets
	bird = new Bird(width,height);
	pillarsL = new Pillars(825);
	pillarsM = new Pillars(1125);
	pillarsR = new Pillars(1425);

	//Ajouts objets a la scene
	addItem(pillarsL);
	addItem(pillarsM);
	addItem(pillarsR);
	addItem(bird);

	//Connections des signaux pour detection des collisions
	connect(pillarsL, &Pillars::birdHit, [=] { end(); });
	connect(pillarsM, &Pillars::birdHit, [=] { end(); });
	connect(pillarsR, &Pillars::birdHit, [=] { end(); });

	//Enleve les scrollbars
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//Affichage de la scene
	view->show();
}

GameWindow::~GameWindow()
{
	qDebug() << "Window Destroyed" << endl;
}

void GameWindow::end()
{
	pillarsL->stop();
	pillarsM->stop();
	pillarsR->stop();
	bird->kill();
}
