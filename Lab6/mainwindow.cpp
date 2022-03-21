#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "random"
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

    obj=new bolagraf(150,300,0,0,11,300);
    scene->addItem(obj);
    obj->pos(v_limit);

    timer_movimiento = new QTimer(this);
    timer_movimiento->stop();
    connect(timer_movimiento,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer_movimiento->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete obj;
    delete scene;
    delete timer_movimiento;
}

void MainWindow::bordercollision(bolagraf *b)
{
    if (b->getesfera()->getPx()<b->getesfera()->getRad()){
        b->getesfera()->setVx(b->getesfera()->getVx()*-1);
        b->getesfera()->setPx(b->getesfera()->getRad());
    }
    if (b->getesfera()->getPx()>h_limit-b->getesfera()->getRad()){
        b->getesfera()->setVx(b->getesfera()->getVx()*-1);
        b->getesfera()->setPx(h_limit-b->getesfera()->getRad());
    }
    if (b->getesfera()->getPy()<b->getesfera()->getRad()){
        b->getesfera()->setVy(b->getesfera()->getVy()*-1);
        b->getesfera()->setPy(b->getesfera()->getRad());
     }
     if (b->getesfera()->getPy()>v_limit-b->getesfera()->getRad()){
        b->getesfera()->setVy(b->getesfera()->getVy()*-1);
        b->getesfera()->setPy(v_limit-b->getesfera()->getRad());
    }
    b->actualizar(v_limit);
}

void MainWindow::actualizar(){
    obj->actualizar(v_limit);
    bordercollision(obj);
}

