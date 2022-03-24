#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    h_limit=1000;
    v_limit=500;
    scene->setSceneRect(0,0,h_limit,v_limit);
    scene->addRect(scene->sceneRect());
    ui->graphicsView->setScene(scene);
    //inicializacion de objetos se hace con el clic
    /*obj1=new bolagraf(160,60,40,40,11,200);
    bolas.push_back(obj1);
    scene->addItem(obj1);
    obj1->pos(v_limit);
    createCoef();
    obj2=new bolagraf(150,11,40,40,11,200);
    bolas.push_back(obj2);
    scene->addItem(obj2);
    obj2->pos(v_limit);
    createCoef();
    obj3=new bolagraf(150,11,40,40,11,200);
    bolas.push_back(obj3);
    scene->addItem(obj3);
    obj3->pos(v_limit);
    createCoef();
    sesion=true;
    startAction();*/
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete timer_movimiento;
}
void MainWindow::bordercollision(bolagraf *b)
{
    if (b->getesfera()->getPx()<b->getesfera()->getRad()){
        b->getesfera()->setVx(b->getesfera()->getVx()*-0.9);
        b->getesfera()->setPx(b->getesfera()->getRad());
    }
    if (b->getesfera()->getPx()>h_limit-b->getesfera()->getRad()){
        b->getesfera()->setVx(b->getesfera()->getVx()*-0.9);
        b->getesfera()->setPx(h_limit-b->getesfera()->getRad());
    }
    if (b->getesfera()->getPy()<b->getesfera()->getRad() && b->getesfera()->getVy()!=0){ //este es el de abajo
        b->getesfera()->setVy(b->getesfera()->getVy()*-0.9);
        b->getesfera()->setPy(b->getesfera()->getRad());
     }
     if (b->getesfera()->getPy()>v_limit-b->getesfera()->getRad()){
        b->getesfera()->setVy(b->getesfera()->getVy()*-0.9);
        b->getesfera()->setPy(v_limit-b->getesfera()->getRad());
    }
     b->actualizar(v_limit);
}
void MainWindow::objectcollision(bolagraf *a, bolagraf *b,int a_, int b_) //arreglar vs iguales
{
    float coe;
    if (a_>b_) coe=float(coef[a_][b_])/100;
    if (a_<b_) coe=float(coef[b_][a_])/100;
    if (a->collidesWithItem(b)){
        //if (a->getesfera()->getVy()<=0 && a->getesfera()->getPy()>b->getesfera()->getPy()){
        //    a->getesfera()->setPy(b->getesfera()->getPy()+b->getesfera()->getRad()+a->getesfera()->getRad());
        //    a->getesfera()->setVx(a->getesfera()->getVx()*-1);
        //    a->getesfera()->setEncima(true);
        //}
        //else{
        a->getesfera()->setVx(a->getesfera()->getVx()*-coe);
        a->getesfera()->setVy(a->getesfera()->getVy()*-coe);
        }
}
void MainWindow::startAction() // falta lo del dial
{
    if (sesion){
    timer_movimiento = new QTimer(this);
    timer_movimiento->stop();
    connect(timer_movimiento,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer_movimiento->start(10); //speed
    }
    else{
        timer_movimiento->stop();
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (!sesion){
        int x_=event->x()-75;
        int y_=v_limit-(event->y()-35);
        bolagraf *help=new bolagraf(x_,y_);
        if (checkPlacement(help) && y_>=50){
        scene->addItem(help);
        bolas.push_back(help);
        help->pos(v_limit);
        //agregar coefs
        createCoef();
        }
    }
}
bool MainWindow::checkPlacement(bolagraf *b)
{
    for (auto i=bolas.begin();i!=bolas.end();i++){
        bolagraf *e=*i;
        if (abs(e->getesfera()->getPx()-b->getesfera()->getPx()) <= e->getesfera()->getRad() + b->getesfera()->getRad() &&
            abs(e->getesfera()->getPy()-b->getesfera()->getPy()) <= e->getesfera()->getRad()+b->getesfera()->getRad())
            return false;
    }
    return true;

}
void MainWindow::createCoef()
{
    int size=bolas.size();
    std::vector <int> vec;
    for (int i=0;i<size;i++){
        if (i==size-1) vec.push_back(0);
        else vec.push_back((rand()%51)+50);
    }
    coef.push_back(vec);
    vec.clear();
}
void MainWindow::actualizar(){
    int ii=0;
    int ib=0;
    for (auto i=bolas.begin();i!=bolas.end();i++){
        bolagraf *e=*i;
        e->actualizar(v_limit);
        bordercollision(e);
        for (auto b=bolas.begin();b!=bolas.end();b++){
            bolagraf *f=*b;
            if (ii!=ib) objectcollision(f,e,ii,ib);
            ib++;
        }
        ii++;
        ib=0;
    }
}
void MainWindow::on_Pause_clicked()
{
    sesion=false;
    startAction();
}
void MainWindow::on_Start_clicked()
{
    sesion=true;
    startAction();
}
void MainWindow::on_Random_clicked()
{
    if (!sesion){
        int size=bolas.size();
        int x_=bolas[size-1]->getesfera()->getPx();
        int y_=bolas[size-1]->getesfera()->getPy();
        scene->removeItem(bolas[size-1]);
        bolas.pop_back();
        bolagraf *help=new bolagraf(x_,y_);
        while (!checkPlacement(help)) help->getesfera()->setRad(rand()%26+5);
        scene->addItem(help);
        bolas.push_back(help);
        help->pos(v_limit);
    }
}

