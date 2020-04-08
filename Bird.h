#pragma once
#include <QKeyEvent>
#include <iostream>
#include <QTimer>
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

public slots:
	void setY(qreal y);

private:
	int height = 50;
	int width = 50;
	int sceneHeight;
	int sceneWidth;
	bool isAlive = true;
	qreal groundDistance;
	qreal m_y=0;
	QPropertyAnimation* yAnimation;
	void setGroundDistance();
};