#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "random"
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
    /*
    obj1=new bolagraf(160,60,40,40,11,200);
    scene->addItem(obj1);
    obj1->pos(v_limit);
    obj2=new bolagraf(150,11,40,40,11,200);
    scene->addItem(obj2);
    obj2->pos(v_limit);*/
}

MainWindow::~MainWindow()
{
    delete ui;
    delete obj1;
    delete obj2;
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
void MainWindow::objectcollision(bolagraf *a, bolagraf *b) //arreglar
{
    if (a->collidesWithItem(b)){
        //if (a->getesfera()->getVy()<=0 && a->getesfera()->getPy()>b->getesfera()->getPy()){
        //    a->getesfera()->setPy(b->getesfera()->getPy()+b->getesfera()->getRad()+a->getesfera()->getRad());
        //    a->getesfera()->setVx(a->getesfera()->getVx()*-1);
        //    a->getesfera()->setEncima(true);
        //}
        //else{
        a->getesfera()->setVx(a->getesfera()->getVx()*-1);
        a->getesfera()->setVy(a->getesfera()->getVy()*-1);
        a->getesfera()->setEncima(false);}

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
void MainWindow::mousePressEvent(QMouseEvent *event) //coefs
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
        else vec.push_back((rand()%51+50));
    }
    coef.push_back(vec);
    vec.clear();
}
void MainWindow::actualizar(){
    for (auto i=bolas.begin();i!=bolas.end();i++){
        bolagraf *e=*i;
        e->actualizar(v_limit);
        bordercollision(e);
        for (auto b=bolas.begin();b!=bolas.end();b++){
            bolagraf *f=*b;
            if (f!=e) objectcollision(f,e);
        }
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
