#include "Pillars.h"

Pillars::Pillars(int startingXPos)
{
	//Recuperation de la largeur de la fenetre (point de respawn)
	resetXValue = startingXPos;

	//Creation des pillars et redimension

	top = new QGraphicsPixmapItem(QPixmap("./Images/Bepip.png").scaled(width,height)); //pt ancrage est en haut a gauche
	bottom = new QGraphicsPixmapItem(QPixmap("./Images/Bpipe.png").scaled(width,height)); //pt ancrage est en haut a gauche

	//Ajout des 2 pilliers dans un groupe (pour gerer les collisions plus tard)
	addToGroup(top);
	addToGroup(bottom);
}

Pillars::~Pillars()
{
	//qDebug() << "Pillars destroyed" << endl;
	delete top; // pas sur si cest necessaire ??
	delete bottom; // pas sur si cest necessaire ??
}

qreal Pillars::x() const
{
	return m_x;
}

void Pillars::stop()
{
	xAnimation->stop();
}

void Pillars::reset()
{
	slide();
	stop();
	isFirstSlide = true;
	scoreFlag = true;
}

void Pillars::setX(qreal x)
{
	moveBy(x - m_x,0);
	m_x = x;
	if (isBirdHit())
	{
		emit birdHit();
	}
	else
	{
		if (x <= 300 && x>0 && scoreFlag)
		{
			scoreFlag = false;
			emit upScore();
		}
		else if (x <=0)
		{
			scoreFlag = true;
		}
	}
}

void Pillars::slide()
{
	//Choix de la position du pillier du bas au hasard
	randomizeHeight();

	int start = resetXValue;
	if (!isFirstSlide)
	{
		start = 800;
	}
	else
	{
		isFirstSlide = false;
	}
	//Animation du slide vers la gauche
	xAnimation = new QPropertyAnimation(this, "x", this);
	xAnimation->setStartValue(start);
	xAnimation->setEndValue(-width);
	xAnimation->setEasingCurve(QEasingCurve::Linear);
	xAnimation->setDuration(4*(start+width)); //deplacement total * un certain facteur de vitesse, diminuer pour augmenter la vitesse
	xAnimation->start();

	//Rappel de lanimation lorsquelle termine
	connect(xAnimation, &QPropertyAnimation::finished, [=]() {
		slide();
	});
}

bool Pillars::isBirdHit()
{
	//liste qui contient tous les objects qui entrent en collision avec le top et le bottom
	QList<QGraphicsItem*> listFoundCollisions = top->collidingItems();
	listFoundCollisions.append(bottom->collidingItems());

	//Parcoure tous les elements de la liste et on tente dynamic_cast lobjet en un Bird*, si ce nest pas un Bird* , alors le cast echoue et bird=0
	for (QGraphicsItem* something : listFoundCollisions)
	{
		Bird* bird = dynamic_cast<Bird*> (something);

		if (bird)
		{
			return true; // something etait un bird*
		}
	}
	return false; // aucun objet dans la liste nest de type bird*

}

void Pillars::randomizeHeight()
{
	std::uniform_int_distribution<int> range(botMaxPos, botMinPos); //(0,0) de la scene est en haut a gauche, donc les coordonnees sont inversees
	std::random_device randomHeight;

	int bottomY = range(randomHeight);
	int topY = bottomY - spaceBetween - height;

	bottom->setPos(0, bottomY);
	top->setPos(0, topY);
}