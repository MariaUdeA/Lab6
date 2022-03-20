#include "bola.h"
#include <QDebug>

bola::bola(float px_,float py_, float vx_, float vy_, float rad_,float masa_):
    px(px_),py(py_),vx(vx_),vy(vy_),rad(rad_),masa(masa_)
{
    qDebug()<<px<<"  "<<py<<"  "<<vx<<"  "<<vy<<"  "<<rad<<" "<<masa;
}

bola::~bola()
{

}

float bola::getPx() const
{
    return px;
}

void bola::setPx(float newPx)
{
    px = newPx;
}

float bola::getPy() const
{
    return py;
}

void bola::setPy(float newPy)
{
    py = newPy;
}

float bola::getVx() const
{
    return vx;
}

void bola::setVx(float newVx)
{
    vx = newVx;
}

float bola::getVy() const
{
    return vy;
}

void bola::setVy(float newVy)
{
    vy = newVy;
}

float bola::getAx() const
{
    return ax;
}

void bola::setAx(float newAx)
{
    ax = newAx;
}

float bola::getAy() const
{
    return ay;
}

void bola::setAy(float newAy)
{
    ay = newAy;
}

float bola::getRad() const
{
    return rad;
}

void bola::mover(float dt)
{
    ax=0;
    //ay=0;
    float vel=(vx*vx)+(vy*vy);
    float k=0.5*DEN*FR*3.1416;
    float angulo;
    if (vx==0){
        if (vy>=0)
            ay=-G-((k*vel*rad*rad)/masa);
        if (vy<0)
            ay=-G+((k*vel*rad*rad)/masa);
    }
    if (vy==0){
        if (vx>0)
            ax=-((k*vel*rad*rad)/masa);
        if (vx<0)
            ax=((k*vel*rad*rad)/masa);
        ay=-G;
    }
    if (vy!=0 && vx!=0) {
    angulo=atan(vy/vx);
    if (vy>0)
        ay=-G-((k*vel*rad*rad*cos(angulo))/masa);
    if (vy<0)
        ay=-G+((k*vel*rad*rad*cos(angulo))/masa);
    if (vx>0)
        ax=-((k*vel*rad*rad*sin(angulo))/masa);
    if (vx<0)
        ax=((k*vel*rad*rad*sin(angulo))/masa);
    }
    vx = vx+(dt*ax);
    vy = vy+(dt*ay);
    px += vx*dt+ax*dt*dt*0.5;
    py += vy*dt+ay*dt*dt*0.5;
}

float bola::getMasa() const
{
    return masa;
}

