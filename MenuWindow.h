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

#include "GameWindow.h"

class MenuWindow : public QGraphicsScene
{
	Q_OBJECT
public:
	MenuWindow();
	~MenuWindow();
	void keyPressEvent(QKeyEvent* event);

private:
	int width = 450;
	int height = 500;

	QGraphicsView* view;
	QMainWindow* main;

	QPushButton* play;
	QPushButton* quit;
	QPushButton* credit;

	QLabel* title;

	GameWindow window;

private slots:
	void playFunc();
	void creditFunc();
	void quitFunc();
	void menuFunc();

};
