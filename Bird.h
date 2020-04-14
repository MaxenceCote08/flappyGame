/*
  APP7 - Informatique : interfaces graphiques

  Université de sherbrooke - Génie informatique

	Émile Chartray – chae3211
	Maxence Côté – cotm3032
	Jonathan Degoede – degj2706
	Martin Giroux – girm1002
*/

#pragma once
#include <QKeyEvent>
#include <iostream>
#include <QTimer>
#include <QSound>
#include <QPropertyAnimation>
#include <QGraphicsPixmapItem>

class Bird : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
	Q_PROPERTY(qreal y	READ y WRITE setY)
public :
	Bird(int windowWidth, int windowHeight);
	~Bird();
	qreal y() const;
	void keyPressEvent(QKeyEvent*);
	void fly();
	void fall();
	void kill();
	bool getBirdState();
	void reset();
	void soundToggle();

public slots:
	void setY(qreal y);

signals:
	void hasMoved();

private:
	int height = 50;
	int width = 50;
	int sceneHeight;
	int sceneWidth;
	bool isAlive = true;
	bool firstJump = true;
	bool sound = true;
	qreal groundDistance;
	qreal m_y=0;
	QPropertyAnimation* yAnimation;
	QSound* jumpSound, *deathSound;
	void setGroundDistance();
};