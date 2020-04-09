#pragma once
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsProxyWidget>
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
	Bird* getBird();
	Pillars* getPillars(QString pillarName);


private:
	int width = 800;
	int height = 500;
	int score = 0;
	QGraphicsView* view;
	Bird* bird;
	Pillars* pillarsL,*pillarsM, *pillarsR;
	QGraphicsProxyWidget *proxy;
};