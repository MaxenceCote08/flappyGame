#include "Bird.h"
#include <QDebug>
#include <QMediaPlayer>


Bird::Bird(int windowWidth, int windowHeight)
{
	//Recupere les dimensions de la scene
	sceneHeight = windowHeight;
	sceneWidth = windowWidth;
	groundDistance = sceneHeight - y() - height;

	//Creation de loiseau
	auto Bird = QPixmap("./Images/Bird.png");
	setPixmap(Bird.scaled(width,height));
	
	//Positionnement de loiseau (separement pour pas chier les coordonnees de lanimation)
	setY(sceneHeight / 2);
	setPos(sceneWidth/2-width/2,y());
	
	//Rend loiseau reactif aux signals (touche pesee)
	setFlag(QGraphicsItem::ItemIsFocusable);
	setFocus();

	//Animation de la chute
	yAnimation = new QPropertyAnimation(this, "y", this);
	//sound 
	birdDead = new QSound("./sound/dead.wav");
	birdFly = new QSound("./sound/jump.wav");
}

Bird::~Bird()
{
	//qDebug() << "Bird Destroyed" << endl;
}

qreal Bird::y() const
{
	return m_y;
}
void Bird::setY(qreal y)
{
	moveBy(0, y-m_y);
	m_y = y;
	setGroundDistance();
}

void Bird::keyPressEvent(QKeyEvent*)
{
	if (isAlive)
	{
		
		fly();
		birdFly->play();
	}
}

void Bird::fly()
{
	if (firstJump) {
		emit hasMoved();
		firstJump = false;
	}

	//Animation du vol
	yAnimation->stop();
	yAnimation->setStartValue(y());
	yAnimation->setEndValue(y()-sceneHeight/8.25);
	yAnimation->setEasingCurve(QEasingCurve::OutQuad);
	yAnimation->setDuration(275);
	yAnimation->start();

	//Lorsque lanimation finit, appelle lanimation de chute
	connect(yAnimation, &QPropertyAnimation::finished, [=]() {fall(); });
	//sound
	
}

void Bird::fall()
{
	//Animation de chute
	yAnimation->setStartValue(y());
	yAnimation->setEndValue(groundDistance);
	yAnimation->setEasingCurve(QEasingCurve::InQuad);
	yAnimation->setDuration(575);
	yAnimation->start();
}

void Bird::setGroundDistance()
{
	groundDistance = sceneHeight - height;
}

void Bird::kill()
{
	birdDead->play();
	QSound::play("./sound/dead.wav");
	isAlive = false;
}

bool Bird::getBirdState()
{
	return isAlive;
}

void Bird::reset()
{
	isAlive = true;
	firstJump = true;
	setY(sceneHeight / 2);
	setPos(sceneWidth / 2 - width / 2, y());
	yAnimation->stop();
}