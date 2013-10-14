#-------------------------------------------------
#
# Project created by QtCreator 2013-05-21T23:26:42
#
#-------------------------------------------------

QT       += core gui opengl


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tank
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    menu.cpp \
    tank.cpp \
    game.cpp \
    statusbar.cpp \
    gamefield.cpp \
    options.cpp \
    about.cpp \
    player.cpp \
    enemy.cpp

HEADERS  += mainwindow.h \
    menu.h \
    tank.h \
    game.h \
    statusbar.h \
    gamefield.h \
    options.h \
    about.h \
    enemy.h \
    player.h

RESOURCES += \
    Menu.qrc \
    GameField.qrc
