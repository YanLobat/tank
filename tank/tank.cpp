
#include <tank.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define FIRE 5
using namespace std;

void T_Obj::paint(){
    GLfloat vertexes[][2] = {{-0.5,-0.5},{-0.5,0.5},{0.5,0.5},{0.5,-0.5}};
    GLuint indices[] = {0,1,2,3};
    GLfloat texcoords[][2] = {{0,0},{0,1},{1,1},{1,0}};
    glTranslatef(x, y, 0);
    glScalef(size, size, 0);
    glVertexPointer(2, GL_FLOAT, 0, vertexes);
    glTexCoordPointer(2, GL_FLOAT, 0, texcoords);
    GLenum drawMode;
   // if (texture_id != 0) {
        glBindTexture(GL_TEXTURE_2D, texture_id);
        drawMode = GL_POLYGON;
   /* } else {
        glColor3f(1, 0, 0);
        drawMode = GL_LINE_LOOP;*/
    //}
    glDrawElements(drawMode, 4, GL_UNSIGNED_INT, indices);

}

void Tank::paint(){


    GLfloat vertexes[][2] = {{-0.5,-0.5},{-0.5,0.5},{0.5,0.5},{0.5,-0.5}};
    GLuint indices[] = {0,1,2,3};
    GLfloat texcoords[][2] = {{0,0},{0,1},{1,1},{1,0}};
    GLfloat angle=0;
    /*switch(prev_d){
        case 1:switch(direction){
                    case 1: angle=0; break;
                    case 2: angle=180; break;
                    case 3: angle=270; break;
                    case 4: angle=90; break;
                }
        case 2:switch(direction){
                    case 1: angle=-180; break;
                    case 2: angle=0; break;
                    case 3: angle=90; break;
                    case 4: angle=-90; break;
                }
        case 3:switch(direction){
                    case 1: angle=-270; break;
                    case 2: angle=-90; break;
                    case 3: angle=0; break;
                    case 4: angle=-180; break;
                }
        case 4:switch(direction){
                    case 1: angle=-90; break;
                    case 2: angle=90; break;
                    case 3: angle=180; break;
                    case 4: angle=0; break;
                }
    }*/
    switch(direction){
        case 2: angle=180; break;
        case 3: angle=90; break;
        case 4: angle=270; break;

    };

    glTranslatef(x, y, 0);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    glScalef(size, size, 0);
    glVertexPointer(2, GL_FLOAT, 0, vertexes);
    glTexCoordPointer(2, GL_FLOAT, 0, texcoords);
    GLenum drawMode;
   // if (texture_id != 0) {
        glBindTexture(GL_TEXTURE_2D, texture_id);
        drawMode = GL_POLYGON;
   /* } else {
        glColor3f(1, 0, 0);
        drawMode = GL_LINE_LOOP;*/
    //}
    glDrawElements(drawMode, 4, GL_UNSIGNED_INT, indices);



}

void Bullet::paint(){

    //glLoadIdentity();


    GLfloat vertexes[][2] = {{-0.5,-0.5},{-0.5,0.5},{0.5,0.5},{0.5,-0.5}};
    GLuint indices[] = {0,1,2,3};
    GLfloat texcoords[][2] = {{0,0},{0,1},{1,1},{1,0}};

    glTranslatef(x, y, 0);
    //glRotatef(angle, 0.0f, 0.0f, 1.0f);

    glScalef(size, size, 0);
    glVertexPointer(2, GL_FLOAT, 0, vertexes);
    glTexCoordPointer(2, GL_FLOAT, 0, texcoords);
    GLenum drawMode;
    if (texture_id != 0) {
        glBindTexture(GL_TEXTURE_2D, texture_id);
        drawMode = GL_POLYGON;
    } else {
        glColor3f(1, 0, 0);
        drawMode = GL_LINE_LOOP;
    }
    glDrawElements(drawMode, 4, GL_UNSIGNED_INT, indices);

}

void T_Obj::setTextureId(GLuint id)
{
    this->texture_id = id;
}


void Tank::setBulTextureId(GLuint id)
{
    this->bullet_texture_id = id;
}

Bullet::Bullet(float x, float y, int direction, float size, int texture_id ){
    obj_id=2;	//РІСЃРµ СЃРЅР°СЂСЏРґС‹ РёРґРµРЅС‚РёС„РёС†РёСЂСѓСЋС‚СЃСЏ РґРІРѕРµС‡РєРѕР№
    this->x=x;
    this->y=y;
    this->direction=direction;
    this->size=size;
    this->texture_id=texture_id;
}

void Bullet::move(){
       switch(direction){
           case UP: if (y>=-0.5 || y<=0.5) y+=0.1; break;
           case DOWN: if (y>=-0.5 || y<=0.5) y-=0.1; break;
           case LEFT: if (x>=-0.5 || x<=0.5) x-=0.1; break;
           case RIGHT: if (x>=-0.5 || x<=0.5) x+=0.1; break;
       }
}

Tank::Tank(float size, float speed, int direction, float x, float y,  float bul_size, QVector<Bullet*>  bullet, int bulletId){//РєРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ РґР»СЏ СЃРѕР·РґР°РЅРёСЏ РѕР±СЉРµРєС‚РѕРІ, РїР°СЂР°РјРµС‚СЂС‹ РєРѕС‚РѕСЂРѕРіРѕ РїРµСЂРµРґР°СЋС‚СЃСЏ РёР· РїРѕР»СЏ
        this->size=size;
        this->speed=speed;
        this->direction=direction;
        this->x=x;
        this->y=y;
        obj_id=1;	//РІСЃРµ С‚Р°РЅРєРё РёРґРµРЅС‚РёС„РёС†РёСЂСѓСЋС‚СЃСЏ Р°Р№РґРё=1
        this->bul_size = bul_size;
        this->bullet = bullet;
        this->bulletId = bulletId;
    }

void Tank::move(int tmp_drct){//tmp_drct - РЅР°РїСЂР°РІР»РµРЅРёРµ РґРІРёР¶РµРЅРёСЏ; РїСЂРµРґСѓСЃРјРѕС‚СЂРµРЅРѕ СЃС‚РѕР»РєРЅРѕРІРµРЅРёРµ СЃРѕ СЃС‚РµРЅР°РјРё
       switch(tmp_drct){
           case UP: if (y>=-0.5 || y<=0.5) y+=0.1*speed; prev_d=direction; direction=tmp_drct; break;
           case DOWN: if (y>=-0.5 || y<=0.5) y-=0.1*speed; prev_d=direction; direction=tmp_drct; break;
           case LEFT: if (x>=-0.5 || x<=0.5) x-=0.1*speed; prev_d=direction; direction=tmp_drct; break;
           case RIGHT: if (x>=-0.5 || x<=0.5) x+=0.1*speed; prev_d=direction; direction=tmp_drct; break;
           case FIRE: bullet.append(new Bullet(x, y, this->direction, this->bul_size, bulletId));
       }
    }

float Tank::getX(){
    return this->x;
}

float Tank::getY(){
    return this->y;
}

float Tank::getDirection(){
    return this->direction;
}

float Tank::setSpeed(float speed){
    this->speed = speed;
}


int T_Obj::collide(T_Obj *another){//РІРѕР·РІСЂР°С‰Р°РµС‚ РЅРѕРјРµСЂ СЃС‚РѕСЂРѕРЅС‹, СЃ РєРѕС‚РѕСЂРѕР№ РїСЂРѕРёСЃС…РѕРґРёС‚ СЃС‚РѕР»РєРЅРѕРІРµРЅРёРµ

    float tmp_x=fabs(another->x-this->x);
    float tmp_y=fabs(another->y-this->y);
    std::cout<<tmp_x<<" "<<tmp_y<<" ";
    if(tmp_x<=(this->size+another->size) && tmp_y<=(this->size+another->size)){//РµСЃР»Рё РѕР±Рµ РєРѕРѕСЂРґРёРЅР°С‚С‹ РЅР°С…РѕРґСЏС‚СЃСЏ РІ РЅРµРѕР±С…РѕРґРёРјРѕР№ Р±Р»РёР·РѕСЃС‚Рё РґСЂСѓРі РѕС‚ РґСЂСѓРіР°
        if(tmp_x>tmp_y)//РµСЃР»Рё СЃС‚РѕР»РєРЅРѕРІРµРЅРёРµ РёРґС‘С‚ РїРѕ РєРѕРѕСЂРґРёРЅР°С‚Рµ РҐ
            if((another->x-this->x)<0)
                return LEFT;
            else
                return RIGHT;
        else			//РµСЃР»Рё СЃС‚РѕР»РєРЅРѕРІРµРЅРёРµ РёРґС‘С‚ РїРѕ РєРѕРѕСЂРґРёРЅР°С‚Рµ РЈ
            if((another->y-this->y)<0)
                return DOWN;
            else
                return UP;
    }
    return 0;//РµСЃР»Рё СЃС‚РѕР»РєРЅРѕРІРµРЅРёСЏ РЅРµ РїСЂРѕРёСЃС…РѕРґРёС‚, РІРѕР·РІСЂР°С‰Р°РµС‚СЃСЏ РЅРѕР»СЊ
}

int T_Obj::LeftWallCollide(){//РІРѕР·РІСЂР°С‰Р°РµС‚ РЅРѕРјРµСЂ СЃС‚РѕСЂРѕРЅС‹, СЃ РєРѕС‚РѕСЂРѕР№ РїСЂРѕРёСЃС…РѕРґРёС‚ СЃС‚РѕР»РєРЅРѕРІРµРЅРёРµ

            if((this->x-this->size)<0)
                return LEFT;

    return 0;//РµСЃР»Рё СЃС‚РѕР»РєРЅРѕРІРµРЅРёСЏ РЅРµ РїСЂРѕРёСЃС…РѕРґРёС‚, РІРѕР·РІСЂР°С‰Р°РµС‚СЃСЏ РЅРѕР»СЊ
}

int T_Obj::RightWallCollide(){//РІРѕР·РІСЂР°С‰Р°РµС‚ РЅРѕРјРµСЂ СЃС‚РѕСЂРѕРЅС‹, СЃ РєРѕС‚РѕСЂРѕР№ РїСЂРѕРёСЃС…РѕРґРёС‚ СЃС‚РѕР»РєРЅРѕРІРµРЅРёРµ

            if((this->x+this->size)>400)
                return RIGHT;

    return 0;//РµСЃР»Рё СЃС‚РѕР»РєРЅРѕРІРµРЅРёСЏ РЅРµ РїСЂРѕРёСЃС…РѕРґРёС‚, РІРѕР·РІСЂР°С‰Р°РµС‚СЃСЏ РЅРѕР»СЊ
}

int T_Obj::UpWallCollide(){//РІРѕР·РІСЂР°С‰Р°РµС‚ РЅРѕРјРµСЂ СЃС‚РѕСЂРѕРЅС‹, СЃ РєРѕС‚РѕСЂРѕР№ РїСЂРѕРёСЃС…РѕРґРёС‚ СЃС‚РѕР»РєРЅРѕРІРµРЅРёРµ

    if((this->y+this->size)>400)
        return UP;

return 0;//РµСЃР»Рё СЃС‚РѕР»РєРЅРѕРІРµРЅРёСЏ РЅРµ РїСЂРѕРёСЃС…РѕРґРёС‚, РІРѕР·РІСЂР°С‰Р°РµС‚СЃСЏ РЅРѕР»СЊ
}

int T_Obj::DownWallCollide(){//РІРѕР·РІСЂР°С‰Р°РµС‚ РЅРѕРјРµСЂ СЃС‚РѕСЂРѕРЅС‹, СЃ РєРѕС‚РѕСЂРѕР№ РїСЂРѕРёСЃС…РѕРґРёС‚ СЃС‚РѕР»РєРЅРѕРІРµРЅРёРµ

            if((this->y-this->size)<0)
                return DOWN;

    return 0;//РµСЃР»Рё СЃС‚РѕР»РєРЅРѕРІРµРЅРёСЏ РЅРµ РїСЂРѕРёСЃС…РѕРґРёС‚, РІРѕР·РІСЂР°С‰Р°РµС‚СЃСЏ РЅРѕР»СЊ
}





Obstruction::Obstruction(float x, float y, float size, int texture_id){
    obj_id=3;
    this->x=x;
    this->y=y;
    this->size=size;
    this->texture_id=texture_id;
}
