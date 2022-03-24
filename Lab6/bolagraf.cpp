#include "bolagraf.h"
bolagraf::bolagraf(float px_,float py_, float vx_, float vy_, float rad_,float masa_)
{
    esfera = new bola(px_,py_,vx_,vy_,rad_,masa_);
}

bolagraf::bolagraf(float px_, float py_)
{
    float  vx_=(rand()%600)-300;
    float vy_=(rand()%600)-300;
    float rad_=rand()%26+5;
    float masa_=rand()%551+50;
    esfera=new bola(px_,py_,vx_,vy_,rad_,masa_);
}

bolagraf::~bolagraf()
{

}

QRectF bolagraf::boundingRect() const
{
    return QRectF(-1*esfera->getRad(),-1*esfera->getRad(),2*esfera->getRad(),2*esfera->getRad());
}

void bolagraf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkBlue);        //asigna el color
    painter->drawEllipse(boundingRect());    //dibuja una elipse encerrada en la boundingRect
}

void bolagraf::pos(int v_lim)
{
    setPos(esfera->getPx(),v_lim-(esfera->getPy()));
}

void bolagraf::actualizar(int v_lim)
{
    esfera->mover(DT);
    pos(v_lim);
}

bola *bolagraf::getesfera()
{
    return esfera;
}
