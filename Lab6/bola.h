#ifndef BOLA_H
#define BOLA_H
#define G 10
#include <math.h>
#define DEN 1.3  //AIRE A NIVEL DEL MAR (KG/M3)
#define FR 0.0005
#define ROZ 0.03 //hielo sobre hielo
class bola
{
public:
    bola(float px_,float py_, float vx_, float vy_, float rad_,float masa_);
    ~bola();

    float getPx() const;
    void setPx(float newPx);

    float getPy() const;
    void setPy(float newPy);

    float getVx() const;
    void setVx(float newVx);

    float getVy() const;
    void setVy(float newVy);

    float getAx() const;
    void setAx(float newAx);

    float getAy() const;
    void setAy(float newAy);

    float getRad() const;

    void mover(float dt);

    float getMasa() const;

    void setEncima(bool newEncima);

    bool getEncima() const;

    void setMasa(float newMasa);

    void setRad(float newRad);
    void mover2(float dt);

private:
    float px;
    float py;
    float vx;
    float vy;
    float ax=0;
    float ay=0;
    float k=0.5*DEN*FR*3.1416;
    float vel;
    float angulo;
    bool encima=false;
    float masa;
    float rad;
};

#endif // BOLA_H
