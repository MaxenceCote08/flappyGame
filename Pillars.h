/*
  APP7 - Informatique : interfaces graphiques

  Universit� de sherbrooke - G�nie informatique

	�mile Chartray � chae3211
	Maxence C�t� � cotm3032
	Jonathan Degoede � degj2706
	Martin Giroux � girm1002
*/

#pragma once

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <Qdebug>
#include <random>
#include <QPropertyAnimation>
#include "Bird.h"

class Pillars :public QObject, public QGraphicsItemGroup
{
	Q_OBJECT
	Q_PROPERTY(qreal x	READ x WRITE setX)
public:
	Pillars(int startingXPos);
	~Pillars();
	qreal x() const;
	void stop();
	void reset();
public slots:
	void setX(qreal x);
	void slide();
signals:
	void birdHit();
	void upScore();
private:
	bool isBirdHit();
	void randomizeHeight();
	QGraphicsPixmapItem* top;
	QGraphicsPixmapItem* bottom;

	int width = 125;
	int height = 335;
	int botMaxPos = 215;
	int botMinPos = 410;
	int spaceBetween = 145;
	int resetXValue;
	bool isFirstSlide = true;
	bool scoreFlag = true;
	QPropertyAnimation* xAnimation;
	qreal m_x =0 ;
};