/*
  APP7 - Informatique : interfaces graphiques

  Université de sherbrooke - Génie informatique

	Émile Chartray – chae3211
	Maxence Côté – cotm3032
	Jonathan Degoede – degj2706
	Martin Giroux – girm1002
*/

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

	//Ajout Musique
	music = new QSound("./Sounds/music.wav");
	music->setLoops(QSound::Infinite);
	music->play();

	scoreSound = new QSound("./Sounds/score.wav");

	//Logos son
	auto muteLogo = QPixmap("./Images/mute.png");
	mute = new QGraphicsPixmapItem;
	mute->setPixmap(muteLogo.scaled(50,50));
	mute->setPos(740, 10);

	auto unmuteLogo = QPixmap("./Images/unmute.png");
	unmute = new QGraphicsPixmapItem;
	unmute->setPixmap(unmuteLogo.scaled(50,50));
	unmute->setPos(740, 10);

	//Ajout score en haut à gauche
	QFont fontScore("Impact", 20);
	affichageScore = new QGraphicsTextItem;
	affichageScoreOutline = new QGraphicsTextItem;
	affichageScoreOutline->setDefaultTextColor(QColor(255, 255, 255));
	affichageScore->setPlainText("Score : " + QString::number(score));
	affichageScoreOutline->setPlainText("Score : " + QString::number(score));
	affichageScore->setPos(4, 0);
	affichageScoreOutline->setPos(1, 0);
	affichageScore->setFont(fontScore);
	affichageScoreOutline->setFont(fontScore);


	//GameOver
	gameOver = new QGraphicsTextItem;
	gameOverOutline = new QGraphicsTextItem;
	gameOverOutline->setDefaultTextColor(QColor(255, 255, 255));
	gameOver->setPlainText("\t       Game Over\nPress any key to play again...");
	gameOverOutline->setPlainText("\t       Game Over\nPress any key to play again...");
	gameOver->setPos(175, height / 2 - 40);
	gameOverOutline->setPos(175 - 4, height / 2 - 40);
	gameOver->setFont(fontScore);
	gameOverOutline->setFont(fontScore);

	//Creation objets
	bird = new Bird(width,height);
	pillarsL = new Pillars(815);
	pillarsM = new Pillars(1125);
	pillarsR = new Pillars(1435);

	//Ajouts objets a la scene
	addItem(pillarsL);
	addItem(pillarsM);
	addItem(pillarsR);
	addItem(bird);
	addItem(affichageScore);
	addItem(affichageScoreOutline);
	addItem(gameOver);
	addItem(gameOverOutline);
	addItem(mute);
	addItem(unmute);

	//Connections des signaux pour detection des collisions
	connect(pillarsL, &Pillars::birdHit, [=] { end(); playAgainMessage(); });
	connect(pillarsM, &Pillars::birdHit, [=] { end(); playAgainMessage(); });
	connect(pillarsR, &Pillars::birdHit, [=] { end(); playAgainMessage(); });

	//Connections depart des pilliers
	connect(bird, &Bird::hasMoved, [=] {
		pillarsL->slide();
		pillarsM->slide();
		pillarsR->slide(); });

	//Connections des signaux pour lupdate du score
	connect(pillarsL, &Pillars::upScore, [=] {score++; if (sound) { scoreSound->play(); } updateScore(); });
	connect(pillarsM, &Pillars::upScore, [=] {score++; if (sound) { scoreSound->play(); } updateScore(); });
	connect(pillarsR, &Pillars::upScore, [=] {score++; if (sound) { scoreSound->play(); } updateScore(); });

	//Enleve les scrollbars
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

GameWindow::~GameWindow()
{
	//qDebug() << "Window Destroyed" << endl;
	delete scoreSound;
	delete music;
	delete affichageScore;
	delete affichageScoreOutline;
	delete gameOver;
	delete gameOverOutline;
	delete mute;
	delete unmute;
}

void GameWindow::end()
{
	score = 0;
	pillarsL->stop();
	pillarsM->stop();
	pillarsR->stop();
	bird->kill();
	bird->fly();
}

void GameWindow::start()
{
	gameOver->hide();
	gameOverOutline->hide();

	if (sound)
	{
		unmute->show();
		mute->hide();
	}
	else
	{
		mute->show();
		unmute->hide();
	}

	bird->reset();
	pillarsL->reset();
	pillarsM->reset();
	pillarsR->reset();
}

QGraphicsView* GameWindow::returnView()
{
	return view;
}

void GameWindow::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Escape)
	{
		QApplication::quit();
	}

	if (bird->getBirdState())
	{
		bird->keyPressEvent(event);
	}
	else
	{
		resetScore();
		updateScore();
		start();
	}
}

void GameWindow::updateScore()
{
	affichageScore->setPlainText("Score : " + QString::number(score));
	affichageScoreOutline->setPlainText("Score : " + QString::number(score));
}

void GameWindow::resetScore()
{
	affichageScore->setPlainText("Score : " + QString::number(score));
	affichageScoreOutline->setPlainText("Score : " + QString::number(score));
}

void GameWindow::playAgainMessage()
{
	gameOver->show();
	gameOverOutline->show();
}

void GameWindow::soundToggle()
{
	if (sound)
	{
		unmute->hide();
		mute->show();
		music->stop();
		sound = false;
	}
	else
	{
		mute->hide();
		unmute->show();
		music->play();
		sound = true;
	}
	bird->soundToggle();
}