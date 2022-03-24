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
    vel=(vx*vx)+(vy*vy);
    if (vx==0){
        ax=0;
        if (vy>=0)
            ay=-G-((k*vel*rad*rad)/masa);
        if (vy<0)
            ay=-G+((k*vel*rad*rad)/masa);
        }
    /*if (vy==0){
        if (vx>=0)
            ax=-((k*vel*rad*rad)/masa);
        if (vx<0)
            ax=((k*vel*rad*rad)/masa);
        if (py==rad)
            ay=0;
        if(py!=rad)
            ay=-G;
        }*/
    if (vx!=0) { //problema
        angulo=abs(atan(vy/vx));
        if (vy>=0) ay=-G-((k*vel*rad*rad*sin(angulo))/masa);
        if (vy<0) ay=-G+((k*vel*rad*rad*sin(angulo))/masa);
        if (vx>0) ax=-((k*vel*rad*rad*cos(angulo))/masa);
        if (vx<0) ax=((k*vel*rad*rad*cos(angulo))/masa);
        if (vy==0 && py==rad) ay=0;
        }
    if (vy>=0 && py<rad && ay<=0){ //fricción con suelo
        vy=0;
        ay=0;
        encima=true;
        if (vx>0)
            ax=-((k*vel*rad*rad)/masa)-G*ROZ;
        if (vx<=0)
            ax=((k*vel*rad*rad)/masa)+G*ROZ;
    }
    if (encima){
        if (vx>0)
            ax=-((k*vel*rad*rad)/masa)-G*ROZ;
        if (vx<=0)
            ax=((k*vel*rad*rad)/masa)+G*ROZ;
    }
    //if (ax==0) vx=0;
    vx = vx+(dt*ax);
    vy = vy+(dt*ay);
    px += vx*dt+ax*dt*dt*0.5;
    py += vy*dt+ay*dt*dt*0.5;
}

float bola::getMasa() const
{
    return masa;
}

void bola::setEncima(bool newEncima)
{
    encima = newEncima;
}

bool bola::getEncima() const
{
    return encima;
}

void bola::setMasa(float newMasa)
{
    masa = newMasa;
}

void bola::setRad(float newRad)
{
    rad = newRad;
}
