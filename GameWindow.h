#pragma once
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include <QPushButton>
#include <QColor>
#include <QGraphicsProxyWidget>
#include <QSound>
#include <QMessageBox>
#include "Bird.h"
#include "Pillars.h"


class GameWindow : public QGraphicsScene
{
	Q_OBJECT
public:
	GameWindow();
	~GameWindow();
	QGraphicsView* returnView();
	void end();
	void start();
	void keyPressEvent(QKeyEvent* event);
	void updateScore();
	void resetScore();
	void playAgainMessage();
	void soundToggle();

private:
	int width = 800;
	int height = 500;
	int score = 0;
	bool sound = true;
	QGraphicsView* view;
	Bird* bird;
	Pillars* pillarsL,*pillarsM, *pillarsR;
	QGraphicsProxyWidget *proxy;
	QGraphicsTextItem* affichageScore, *affichageScoreOutline, *gameOver, *gameOverOutline;
	QSound* music, *scoreSound;
	QGraphicsPixmapItem* mute, *unmute;
};