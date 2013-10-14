#include "game.h"
#include <gamefield.h>
#include <QMainWindow>
#include <qlabel.h>
//#include <player.h>

#define W 500
#define H 500

#define OBSTN 21
#define PARAMS 5

Game::Game(QWidget *parent) :
    QWidget(parent)
{
        textures = new QMap<QString, int>;
        //initializeLevel();
        initializeGame();
        setAutoFillBackground(true);
        setFixedSize (W,H);
        QPalette p;
        p.setBrush(this->backgroundRole(),QBrush(QImage(":/GameField/textures/Gamefield/ramka.png")));
        setPalette(p);


        /*QTimer *passageof = new QTimer(this);
        connect(passageof, SIGNAL(timeout()), this, SLOT(pushpassageof()));
        fireTimer->start(2);*/
}

void Game::initializeGame()
{
    bar = new StatusBar(this);
    field = new GameField(this,textures);
    connect(this, SIGNAL(linkSingnal()), parent(), SLOT(openMenu()));

}

/*void Game::PassageOf(){

    for(int i=0; i < tanks->size(); i++)
        for(int j=0; j < objlist->size(); j++){
            if(tanks->at(i).collide(objlist->at(j)) == 0) continue;
            else
                if(objlist->at(j).obj_id == 2) delete tanks->removeAt(i);
                else
                    if(tanks->at(i).collide(objlist->at(j)) == tanks.at(i).direction) tanks->at(i).speed = 0;
        }
    }


    for(int j=0; j < objlist.size(); j++){
    if(player->tank.collide(objlist->at(j)) == 0) continue;
    else
        if(objlist->at(j).obj_id == 2) delete player.tank;
        else
            if(player.tank.collide(objlist->at(j)) == player.tank.direction) player.tank.speed = 0;


    }


}*/

void Game::pushmovement()
{
   /* for(int i = 0; i < n; i++){
        tanks->at(i)->move(enemy->movement)*/
}

void Game::pushpassageof()
{
    //PassageOf(objlist,tanks);
}

/*void Game::initializeLevel()
{

    enemy = new enemy();

    for(int i = 10; i < 20; ++i){//Цикл для заполнения списка препятствиями


        float bul_size = 0.5;
        x = level[i][0];
        y = level[i][1];
        size = level[i][2];
        texture_tank_id = level[i][3];
        texture_bullet_id = level[i][4];

        Tank tank(size, speed , enemy.move(), x, y,  texture_tank_id, bul_size,texture_bullet_id);//size, speed, direction, x, y, tex_id, bul_size, bul_tex_id

        tanks->append(tank);

    }

    x = level[21][0];
    y = level[21][1];
    size = level[21][2];
    texture_id = level[21][3];

    player = new player(texture_id, id_texture_bullet);//взять все у леши
}*/

Game::~Game()
{
    delete bar;
    delete field;
}

void Game::keyPressEvent(QKeyEvent *event)
{
    field->keyPressEvent(event);
}

void Game::pushPauseButton()
{
    doSignal();
}


