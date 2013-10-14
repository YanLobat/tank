#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QKeyEvent>
#include "statusbar.h"
#include <menu.h>
#include <gamefield.h>

class Game : public QWidget
{
    Q_OBJECT

    StatusBar *bar;
    //Player *player;
    GameField *field;
    QMap<QString, int> * textures;
    void initializeGame();
public:
    explicit Game(QWidget *parent = 0);
    ~Game();
    void keyPressEvent(QKeyEvent *);
    void doSignal(){linkSingnal();}

signals:
    void linkSingnal();

public slots:
    void pushmovement();
    void pushPauseButton();
    void pushpassageof();

};

#endif // GAME_H
