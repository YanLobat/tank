#ifndef TANK_H
#define TANK_H

#include <QWidget>
#include <QGLWidget>
#include <QWidget>
#include <QTimer>
#include <time.h>

class T_Obj{//базовый класс
protected:
    int obj_id;
    float x,y;
    float size;
    GLuint texture_id;
public:
    virtual void paint();
    void setTextureId(GLuint id);
    int collide(T_Obj*);
    int LeftWallCollide();
    int RightWallCollide();
    int UpWallCollide();
    int DownWallCollide();
};

class Bullet: public T_Obj{

public:
    int direction;
    Bullet(float, float, int, float, int);//параметры: x, y, direction, size, texture_id
    void move();
    void paint();
};

class Tank: public T_Obj{

    float speed;
    int prev_d;

    int direction;
    int bullet_size;
    GLuint bullet_texture_id;
    int bulletId;
    float bul_size;
    QVector<Bullet*> bullet;
public:
    Tank(float, float, int, float, float, float, QVector<Bullet*>, int);//size, speed, direction, x, y, tex_id, bul_size, bul_tex_id
    void move(int);//передается направление движения
    void paint();
    void setBulTextureId(GLuint id);

    float getX();
    float getY();
    float getDirection();
    float setSpeed(float);

};



class Obstruction: public T_Obj{
public:
    Obstruction(float, float, float, int);//x, y, size, texture_id
};

#endif
