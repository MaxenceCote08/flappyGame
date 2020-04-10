#pragma once
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QStatusBar>
#include <QMenuBar>
#include <QMenu>
#include <QApplication>
#include <QMessageBox>
#include <QFrame>

#include "GameWindow.h"

class MenuWindow : public QGraphicsScene
{
	Q_OBJECT
public:
	MenuWindow();
	~MenuWindow();

private:
	int width = 450;
	int height = 500;
	bool isGameOn = false;

	QGraphicsView* view;
	QMainWindow* main;

	QPushButton* play;
	QPushButton* quit;
	QPushButton* credits;
	QPushButton* how;

	QLabel* title,*titleOutline;

	GameWindow window;

private slots:
	void playFunc();
	void creditFunc();
	void quitFunc();
	void howFunc();
};
