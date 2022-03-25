#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include "bolagraf.h"
#include <QDebug>
#include <QTimer>
#include <QPushButton>
#include <vector>
#include <QMouseEvent>
#include <stdlib.h> //random

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void bordercollision(bolagraf *b);
    void objectcollision(bolagraf *a,bolagraf *b,int a_,int b_);
    void startAction();
    void mousePressEvent(QMouseEvent *event);
    bool checkPlacement(bolagraf *b);
    void createCoef();
    void showLine();

private slots:
    void actualizar();
    void on_Pause_clicked();
    void on_Start_clicked();
    void on_Random_clicked();
    void on_Apply_clicked();
    void on_Restart_clicked();
    void on_vyLineEdit_textEdited(const QString &arg1);
    void on_vxLineEdit_textEdited(const QString &arg1);
    void on_radLineEdit_textEdited(const QString &arg1);
    void on_masLineEdit_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    bolagraf *obj1;
    bolagraf *obj2;
    bolagraf *obj3;
    int v_limit;
    int h_limit;
    bool sesion=false;
    QTimer *timer_movimiento;
    std::vector <bolagraf*> bolas;
    std::vector <std::vector<int>> coef;
    bool WriteVy=false;
    bool WriteVx=false;
    bool WriteRad=false;
    bool WriteMasa=false;
    int speed=30; //para el dial
};

#endif // MAINWINDOW_H
