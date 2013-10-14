#ifndef GAMEFIELD_H
#define GAMEFIELD_H

const int indexes[4] = {0, 1, 2, 3};
const float vertexes[4][2] = {{-0.5, -0.5}, {0.5, -0.5}, {0.5, 0.5}, {-0.5, 0.5}};
const float textcoords[4][2] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};

#include <QKeyEvent>
#include <QGLWidget>
#include <QWidget>
#include <QTimer>
#include <time.h>
#include <tank.h>
//#include <player.h>
//#include <pole.h>

class GameField : public  QGLWidget
{
    Q_OBJECT
    QTimer * paintTimer; // Таймер отрисовки игрового поля
    //Player *player; //игрок
    QVector<Tank*> tank;
    QVector<Bullet*> bullet;
    int tankId;
    int bulletId;
    //int objid;
    //QList<Tank*> * tanks; //список танков
    //QList<T_Obj*> * objlist;    //список препятствий и пуль
    QMap<QString, int> * textures; //словать тестур
    int fieldTextureId; // текстура поля

public:

    GameField(QWidget *parent,
            //Player *player,
            //QList<Tank*> * tanks,
            //QList<T_Obj*> * objlist,
            QMap<QString, int> * textures);
    ~GameField();

    void keyPressEvent(QKeyEvent *);
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void initializeTextures();
    void drawField();

public slots:
    void updateModel();

};

#endif // GAMEFIELD_H
