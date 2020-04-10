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

	QAction *howAction = new QAction("How To Play");
	connect(howAction, SIGNAL(triggered()), SLOT(howFunc()));

	//Creation de la scene graphique
	view = new QGraphicsView(this);
	view->setFixedSize(width+10, height);
	view->setSceneRect(0, 0, width+10, height);

	//Ajout fond scene
	auto background = QBrush(QImage("./Images/background.jpg").scaled(width, height));
	view->setBackgroundBrush(background);

	//Restrictions usager
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//Création des boutons
	play = new QPushButton();
	play->setGeometry(QRect(150, 160, 150, 50));
	play->setText("Play");
	play->setFont(fontButton);
	play->setAttribute(Qt::WA_TranslucentBackground);

	how = new QPushButton();
	how->setGeometry(QRect(150, 235, 150, 50));
	how->setText("How To Play");
	how->setFont(fontButton);
	how->setAttribute(Qt::WA_TranslucentBackground);

	credits = new QPushButton();
	credits->setGeometry(QRect(150, 310, 150, 50));
	credits->setText("Credits");
	credits->setFont(fontButton);
	credits->setAttribute(Qt::WA_TranslucentBackground);


	quit = new QPushButton();
	quit->setGeometry(QRect(150, 385, 150, 50));
	quit->setText("Quit");
	quit->setFont(fontButton);
	quit->setAttribute(Qt::WA_TranslucentBackground);

	title = new QLabel();
	title->setAttribute(Qt::WA_TranslucentBackground);
	title->setGeometry(QRect(100, 0, 250, 200));
	title->setText("Flappy Game");
	title->setFont(fontTitle);
	title->setAlignment(Qt::AlignCenter);

	titleOutline = new QLabel();
	titleOutline->setAttribute(Qt::WA_TranslucentBackground);
	titleOutline->setGeometry(QRect(97,0,250,200));
	titleOutline->setText("<font color='white'>Flappy Game");
	titleOutline->setFont(fontTitle);
	titleOutline->setAlignment(Qt::AlignCenter);

	//Connection des bouttons à leur action
	connect(play, SIGNAL(released()), this, SLOT(playFunc()));
	connect(credits, SIGNAL(released()), this, SLOT(creditFunc()));
	connect(quit, SIGNAL(released()), this, SLOT(quitFunc()));
	connect(how, SIGNAL(released()), this, SLOT(howFunc()));
		
	//Ajout des boutons et du titre
	addWidget(play);
	addWidget(how);
	addWidget(credits);
	addWidget(quit);
	addWidget(title);
	addWidget(titleOutline);
	
	
	//Ajout du menu qui descend
	QMenuBar* menuBar = new QMenuBar();
	QMenu* menu = new QMenu();

	menu->setTitle("Menu");
	menu->addAction(playAction);
	menu->addAction(howAction);
	menu->addAction(creditAction);
	menu->addAction(quitAction);
	
	menu->setFont(fontMenu);
	menuBar->setFont(fontMenu);
	menuBar->addMenu(menu);

	//Ajout du message au bas de la page
	QLabel* statusMessage = new QLabel();
	statusMessage->setText("Created by Jonathan D, Maxence C, Martin G and Emile C.");
	QStatusBar* status = new QStatusBar();
	status->addPermanentWidget(statusMessage);

	//Création du main window
	main = new QMainWindow();
	main->setCentralWidget(view);
	main->setWindowTitle("Flappy game");
	main->setStatusBar(status);
	main->setMenuBar(menuBar);
	main->statusBar()->setSizeGripEnabled(false);
	main->setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint | Qt::CustomizeWindowHint);
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
		isGameOn = true;
	}
	else 
	{
		window.end();
		window.resetScore();
		window.updateScore();
	}
	window.start();
}

void MenuWindow::howFunc()
{
	QMessageBox* message = new QMessageBox();
	message->setWindowTitle("How To Play");
	message->setIcon(QMessageBox::Information);
	message->setText("- Press any key to make the bird fly.\n- Avoid the pipes to stay alive!\n- Done playing? Press the escape key to quit or menu->quit.\n\n ****If nothing happens when you press a key, make sure to click on the game window to set your keyboard focus there.****\n\n");	message->show();
}

void MenuWindow::quitFunc()
{
	QApplication::quit();
}

void MenuWindow::creditFunc()
{
	QMessageBox* message = new QMessageBox();
	message->setWindowTitle("Credits for Flappy game");
	message->setIcon(QMessageBox::Information);
	message->setText("This application is a project made by Jonathan D, Maxence C, Martin G and Emile C.\nThis game was created in the context of the APP7 of GI.\nThe game is based on the viral game called Flappy Bird.");
	message->show();
}
