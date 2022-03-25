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
    sesion=true;
    startAction();
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
        timer_movimiento->stop();
        /*float vx=(a->getesfera()->getVx()*-0.9);
        float vy=(a->getesfera()->getVy()*-0.9);
        float bx=(b->getesfera()->getVx()*-0.9);
        float by=(b->getesfera()->getVx()*-0.9);*/
        int suma=a->getesfera()->getMasa()+b->getesfera()->getMasa();
        float vx=((b->getesfera()->getMasa()*(1+coe)*b->getesfera()->getVx()) + (((a->getesfera()->getMasa())-(coe*b->getesfera()->getMasa()))*a->getesfera()->getVx()))/suma;
        float vy=((b->getesfera()->getMasa()*(1+coe)*b->getesfera()->getVy()) + (((a->getesfera()->getMasa())-(coe*b->getesfera()->getMasa()))*a->getesfera()->getVy()))/suma;
        float bx=((a->getesfera()->getMasa()*(1+coe)*a->getesfera()->getVx()) + (((b->getesfera()->getMasa())-(coe*a->getesfera()->getMasa()))*b->getesfera()->getVx()))/suma;
        float by=((a->getesfera()->getMasa()*(1+coe)*a->getesfera()->getVy()) + (((b->getesfera()->getMasa())-(coe*a->getesfera()->getMasa()))*b->getesfera()->getVy()))/suma;
        a->getesfera()->setVx(vx);
        a->getesfera()->setVy(vy);
        b->getesfera()->setVx(bx);
        b->getesfera()->setVy(by);
        while (a->collidesWithItem(b)){
            a->actualizar2(v_limit);
            b->actualizar2(v_limit);
        }
        timer_movimiento->start(speed);
        }
}
void MainWindow::startAction() // falta lo del dial
{
    if (sesion){
    timer_movimiento = new QTimer(this);
    timer_movimiento->stop();
    connect(timer_movimiento,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer_movimiento->start(speed); //speed
    //qDebug()<<speed<<' ';
    }
    else{
        timer_movimiento->stop();
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
        int x_=event->x()-75;
        int y_=v_limit-(event->y()-35);
        bolagraf *help=new bolagraf(x_,y_);
        if (checkPlacement(help) && y_>=50){
        scene->addItem(help);
        bolas.push_back(help);
        help->pos(v_limit);
        //agregar coefs
        createCoef();
        //mostrar en line
        showLine();
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
    if (b->getesfera()->getRad()>b->getesfera()->getPy())
        return false;
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
void MainWindow::showLine()
{
    int size = bolas.size();
    QString rad=QString::number(bolas[size-1]->getesfera()->getRad(),'g',4);
    QString masa=QString::number(bolas[size-1]->getesfera()->getMasa(),'g',4);
    QString vx=QString::number(bolas[size-1]->getesfera()->getVx(),'g',4);
    QString vy=QString::number(bolas[size-1]->getesfera()->getVy(),'g',4);
    if (!WriteRad) ui->radLineEdit->setText(rad);
    if (!WriteVx) ui->vxLineEdit->setText(vx);
    if (!WriteVy) ui->vyLineEdit->setText(vy);
    if (!WriteMasa) ui->masLineEdit->setText(masa);

}
void MainWindow::actualizar(){
    int ii=0;
    int ib=0;
    for (auto i=bolas.begin();i!=bolas.end();i++){
        bolagraf *e=*i;
        e->actualizar(v_limit);
        showLine();
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
        showLine();
}
void MainWindow::on_Apply_clicked()
{
    int size=bolas.size();
    QString r=ui->radLineEdit->text();
    float rad=r.toFloat();
    QString x=ui->vxLineEdit->text();
    float vx=x.toFloat();
    QString y=ui->vyLineEdit->text();
    float vy=y.toFloat();
    QString m=ui->masLineEdit->text();
    float mas=m.toFloat();
    int posx=bolas[size-1]->getesfera()->getPx();
    int posy=bolas[size-1]->getesfera()->getPy();
    bolagraf *help=new bolagraf(posx,posy,vx,vy,rad,mas);
    bolagraf *placeholder=bolas[size-1];
    scene->removeItem(bolas[size-1]);
    bolas.pop_back();
    if (checkPlacement(help) && abs(vy)<=300 && abs(vx)<=300 && mas>=50 && mas<=600 && rad>=5 && rad<=30){
            scene->addItem(help);
            bolas.push_back(help);
            help->pos(v_limit);
            showLine();
    }
    else{
            scene->addItem(placeholder);
            bolas.push_back(placeholder);
            placeholder->pos(v_limit);
            showLine();
        }
    WriteMasa=false;
    WriteRad=false;
    WriteVx=false;
    WriteVy=false;

}
void MainWindow::on_Restart_clicked()
{
   for (auto i=bolas.begin();i!=bolas.end();i++){
       bolagraf *e=*i;
       scene->removeItem(e);
   }
   bolas.clear();
   sesion=false;
   startAction();
}
void MainWindow::on_vyLineEdit_textEdited(const QString &arg1)
{
    WriteVy=true;
}
void MainWindow::on_vxLineEdit_textEdited(const QString &arg1)
{
    WriteVx=true;
}
void MainWindow::on_radLineEdit_textEdited(const QString &arg1)
{
    WriteRad=true;
}
void MainWindow::on_masLineEdit_textEdited(const QString &arg1)
{
    WriteMasa=true;
}
