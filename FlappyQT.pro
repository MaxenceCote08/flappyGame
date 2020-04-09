TEMPLATE     = vcapp
TARGET       = FlappyQT
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += GameWindow.h Bird.h Pillars.h
SOURCES     += Main.cpp GameWindow.cpp Bird.cpp Pillars.cpp
INCLUDEPATH += ../flappyGame

#LIBS	      += 
QT += widgets
