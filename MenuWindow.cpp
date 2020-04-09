#include "MenuWindow.h"


MenuWindow::MenuWindow()
{
	QFont fontTitle("Impact", 20);
	QFont fontButton("Impact", 14);
	QFont fontMenu("Impact", 10);

	QAction *playAction = new QAction("Play");
	connect(playAction, SIGNAL(triggered()), SLOT(playFunc()));

	QAction *creditAction = new QAction("Credits");
	connect(creditAction, SIGNAL(triggered()), SLOT(creditFunc()));

	QAction *quitAction = new QAction("Quit");
	connect(quitAction, SIGNAL(triggered()), SLOT(quitFunc()));

	//Creation de la scene graphique
	view = new QGraphicsView(this);
	view->setFixedSize(width, height);
	view->setSceneRect(0, 0, width, height);

	//Ajout fond scene
	auto background = QBrush(QImage("./Images/background.jpg").scaled(width, height));
	view->setBackgroundBrush(background);

	//Enleve les scrollbars
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//Création des boutons
	play = new QPushButton();
	play->setGeometry(QRect(175, 200, 100, 50));
	play->setText("Play");
	play->setFont(fontButton);
	play->setAttribute(Qt::WA_TranslucentBackground);

	credits = new QPushButton();
	credits->setGeometry(QRect(175, 275, 100, 50));
	credits->setText("Credits");
	credits->setFont(fontButton);
	credits->setAttribute(Qt::WA_TranslucentBackground);

	quit = new QPushButton();
	quit->setGeometry(QRect(175, 350, 100, 50));
	quit->setText("Quit");
	quit->setFont(fontButton);
	quit->setAttribute(Qt::WA_TranslucentBackground);

	title = new QLabel();
	title->setAttribute(Qt::WA_TranslucentBackground);
	title->setGeometry(QRect(100, 10, 250, 200));
	title->setText("Flappy Game");
	title->setFont(fontTitle);
	title->setAlignment(Qt::AlignCenter);

	//Connection des bouttons à leur action

	connect(play, SIGNAL(released()), this, SLOT(playFunc()));
	connect(credits, SIGNAL(released()), this, SLOT(creditFunc()));
	connect(quit, SIGNAL(released()), this, SLOT(quitFunc()));
		
	//Ajout des boutons et du titre
	addWidget(play);
	addWidget(credits);
	addWidget(quit);
	addWidget(title);
	
	//Ajout du menu qui descend
	QMenuBar* menuBar = new QMenuBar();
	QMenu* menu = new QMenu();

	menu->setTitle("Menu");
	menu->addAction(playAction);
	menu->addAction(creditAction);
	menu->addAction(quitAction);
	
	menu->setFont(fontMenu);
	menuBar->setFont(fontMenu);
	menuBar->addMenu(menu);

	//Ajout du message au bas de la page
	QLabel* statusMessage = new QLabel();
	statusMessage->setText("Created by Jonathan, Maxence, Martin and Emile.");
	QStatusBar* status = new QStatusBar();
	status->addPermanentWidget(statusMessage);

	//Création du main window
	main = new QMainWindow();
	main->setCentralWidget(view);
	main->setWindowTitle("Flappy game");
	main->setStatusBar(status);
	main->setMenuBar(menuBar);
	main->show();
}

MenuWindow::~MenuWindow()
{

}

void MenuWindow::playFunc()
{
	if (!isGameOn)
	{
		main->setCentralWidget(window.returnView());
		window.start();
		isGameOn = true;
	}
	else 
	{
		window.getBird()->reset();
		window.getPillars("pillarsL")->reset();
		window.getPillars("pillarsM")->reset();
		window.getPillars("pillarsR")->reset();
	}
}

void MenuWindow::creditFunc()
{
	QMessageBox* message = new QMessageBox();
	message->setWindowTitle("Credits for Flappy game");
	message->setText("This application is a project made by Jonathan, Maxence, Martin and Emile.\nThis game was created in the context of the APP7 of GI.\nThe game is based on the viral game called Flappy Bird.");
	message->show();
}

void MenuWindow::quitFunc()
{
	QApplication::quit();
}
