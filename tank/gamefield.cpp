#include "gamefield.h"
#include <qlabel.h>
#include <QTimer>
#include <time.h>
//#include <player.h>



GameField::GameField(QWidget *parent,
                     //Player *player,
                     //QList<Tank*> * tanks,
                     //QList<T_Obj*> * objlist
                     QMap<QString, int> * textures): QGLWidget(parent)
{
    setGeometry(25,25,400,400);
    tank.append(new Tank(40,60,1,50,50, 20, bullet, bulletId));
    //инициализация элементов
    //this->player = player;
    //this->tanks = tanks;
    this->textures = textures;
    //this->objlist = objlist;

    paintTimer = new QTimer(this);
    connect(paintTimer, SIGNAL(timeout()), this, SLOT(updateGL()));
    paintTimer->start(1000 / 30); // 30 кадров в секунду

    QTimer *modelTimer = new QTimer(this);
    connect(modelTimer, SIGNAL(timeout()), this, SLOT(updateModel()));
    modelTimer->start(1);

    this->updateGL();//вызовется инициалайджил
    drawField();


}

GameField::~GameField()
{
    //delete tank;
}

void GameField::initializeGL()
{
    //Включается полупрозрачность
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //Включаем текстуры и использование массивов вертексов и текстурных координат
    glEnable(GL_TEXTURE_2D);
    initializeTextures();

    GLuint texid = bindTexture(QPixmap(QString(":/Field/textures/Gamefield/Game/tank.jpg")), GL_TEXTURE_2D);
        tank[0]->setTextureId(texid);

    GLuint texid1 = bindTexture(QPixmap(QString(":/Field/textures/Gamefield/Game/bub.jpg")), GL_TEXTURE_2D);
        tank[0]->setBulTextureId(texid1);

    qglClearColor(Qt::blue);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);




}

void GameField::initializeTextures()
{
    //bindTexture возвращает id текстуры
    fieldTextureId = bindTexture(QPixmap(":/Field/textures/Gamefield/Game/field.jpg"), GL_TEXTURE_2D);
    //tankId = bindTexture(QPixmap(":/Field/textures/Gamefield/Game/tank.jpg"), GL_TEXTURE_2D);
    //bulletId = bindTexture(QPixmap(":/Field/textures/Gamefield/Game/bub.jpg"), GL_TEXTURE_2D);
    textures->insert("Enemy",
        bindTexture(QPixmap(":/Field/textures/Gamefield/Game/tank.jpg"), GL_TEXTURE_2D));
    textures->insert("Player",
        bindTexture(QPixmap(":/Field/textures/Gamefield/Game/tank.jpg"), GL_TEXTURE_2D));
    textures->insert("Bullet",
        bindTexture(QPixmap(":/Field/textures/Gamefield/Game/bub.jpg"), GL_TEXTURE_2D));
    textures->insert("Obstruction",
        bindTexture(QPixmap(":/Field/textures/Gamefield/Game/obs.jpg"), GL_TEXTURE_2D));
}

void GameField::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void GameField::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); //загружаем единичную матрицу, шоб в памяти мусора не было

    //размер экрана -1:1 по всем осям. В этом случае
    glOrtho(0, width(), 0, height(), -1, 1);
    glPushMatrix();
    drawField();//Нарисовать поле
    glPopMatrix();
    glPushMatrix();
    //tank[0]->paint();
    //obj[0]->paint();
    //отрисовать все списки



    if(bullet.size())
        for(int i = 0; i < bullet.size(); i++){
            glPopMatrix();
            glPushMatrix();
            bullet[i]->paint();
        }
    glPopMatrix();
    glPushMatrix();

    tank[0]->paint();


    /*for (int i = 0; i < objlist->count(); ++i) //Иду по всему списку с bullets
        objlist->at(i)->paint(); //Беру i-того bullet и говорю ему нарисуйся

    for (int i = 0; i < tanks->count(); ++i) //Иду по всему списку с bullets
        tanks>at(i)->paint(); //Беру i-того bullet и говорю ему нарисуйся*/
}

void GameField::drawField()
{
    glPushMatrix();
    glScalef(400, 400, 1);
    glBindTexture(GL_TEXTURE_2D, fieldTextureId);
    glTexCoordPointer(2, GL_FLOAT, 0, textcoords);
    glVertexPointer(2, GL_FLOAT, 0, textcoords);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, indexes);
    glPopMatrix();
}


void GameField::keyPressEvent(QKeyEvent *event)
{


        if (event->key() == Qt::Key_W)
            tank[0]->move(1);

        if (event->key() == Qt::Key_A) {
            tank[0]->move(3);
        }
        if (event->key() == Qt::Key_S) {
            tank[0]->move(2);
        }
        if (event->key() == Qt::Key_D) {
           tank[0]->move(4);
        }

        if(!(event->isAutoRepeat()))
        if (event->key() == Qt::Key_F && !(event->isAutoRepeat())) {
            bullet.append(new Bullet(tank[0]->getX(), tank[0]->getY(), tank[0]->getDirection(), 15, bulletId));
        }
}


void GameField::updateModel(){

    /*for (int i = 0; i < bullet.size(); ++i) {
        for (int j = i + 1; j < bullet.size(); ++j) {
            bullet[i]->collide(bullet[j]);
        }
        //bullet[i]->wallCollide(width(), height());
    }*/
    for(int i=0; i < bullet.size(); i++)
        if((bullet[i]->LeftWallCollide() == bullet[i]->direction) ||
           (bullet[i]->RightWallCollide() == bullet[i]->direction) ||
           (bullet[i]->UpWallCollide() == bullet[i]->direction) ||
           (bullet[i]->DownWallCollide() == bullet[i]->direction))  bullet.remove(i);

    for (int i = 0; i < bullet.size(); ++i) {
        bullet[i]->move();
    }

    for(int i=0; i < tank.size(); i++)
        if((tank[i]->LeftWallCollide() == tank[i]->getDirection()) ||
           (tank[i]->RightWallCollide() == tank[i]->getDirection()) ||
           (tank[i]->UpWallCollide() == tank[i]->getDirection()) ||
           (tank[i]->DownWallCollide() == tank[i]->getDirection())) tank[i]->setSpeed(0);
                    else
                    tank[i]->setSpeed(60);
}


