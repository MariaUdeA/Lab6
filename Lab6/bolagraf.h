#ifndef BOLAGRAF_H
#define BOLAGRAF_H
#include <QPainter>
#include <QGraphicsItem>
#include <stdlib.h> //random
#include "bola.h"
#define DT 0.1

class bolagraf : public QGraphicsItem
{
public:
    bolagraf(float px_,float py_, float vx_, float vy_, float rad_,float masa_);
    bolagraf(float px_,float py_); //para entrada random
    ~bolagraf();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void pos(int v_lim);
    void actualizar(int v_lim);
    bola* getesfera();

private:
    bola *esfera;
};

#endif // BOLAGRAF_H
