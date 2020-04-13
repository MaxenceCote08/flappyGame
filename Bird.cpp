#include "Bird.h"
#include <QDebug>

Bird::Bird(int windowWidth, int windowHeight)
{
	//Recupere les dimensions de la scene
	sceneHeight = windowHeight;
	sceneWidth = windowWidth;
	groundDistance = sceneHeight - y() - height;

	//Creation de loiseau
	auto bird = QPixmap("./Images/Bird.png");
	setPixmap(bird.scaled(width,height));

	//SetUp son
	jumpSound = new QSound("./Sounds/jump.wav");
	deathSound = new QSound("./Sounds/death.wav");
	
	//Positionnement de loiseau (separement pour pas chier les coordonnees de lanimation)
	setY(sceneHeight / 2);
	setPos(sceneWidth/2-width/2,y());
	
	//Rend loiseau reactif aux signals (touche pesee)
	setFlag(QGraphicsItem::ItemIsFocusable);
	setFocus();

	//Animation de la chute
	yAnimation = new QPropertyAnimation(this, "y", this);
}

Bird::~Bird()
{
	//qDebug() << "Bird Destroyed" << endl;
	delete jumpSound;
	delete deathSound;
	delete yAnimation;
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
	}
}

void Bird::fly()
{
	if (y() >= 5)
	{
		if (firstJump) {
			emit hasMoved();
			firstJump = false;
		}

		//Son
		if (sound)
		{
			if (isAlive)
			{
				jumpSound->play();
			}
			else
			{
				deathSound->play();
			}
		}

		//Animation du vol

		yAnimation->stop();
		yAnimation->setStartValue(y());
		yAnimation->setEndValue(y() - sceneHeight / 8.25);
		yAnimation->setEasingCurve(QEasingCurve::OutQuad);
		yAnimation->setDuration(300);
		yAnimation->start();
	}

	//Lorsque lanimation finit, appelle lanimation de chute
	connect(yAnimation, &QPropertyAnimation::finished, [=]() {fall(); });
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

void Bird::soundToggle()
{
	if (sound)
	{
		sound = false;
	}
	else
	{
		sound = true;
	}
}