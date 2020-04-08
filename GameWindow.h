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
	void end();

private:
	int width = 800;
	int height = 500;
	QGraphicsView* view;
	Bird* bird;
	Pillars* pillarsL,*pillarsM, *pillarsR;
	QPushButton* reset;
	QGraphicsProxyWidget *proxy;
};