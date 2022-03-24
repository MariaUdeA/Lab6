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
    void objectcollision(bolagraf *a,bolagraf *b);
    void startAction();
    void mousePressEvent(QMouseEvent *event);
    bool checkPlacement(bolagraf *b);
    void createCoef();

private slots:
    void actualizar();
    void on_Pause_clicked();
    void on_Start_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    bolagraf *obj1;
    bolagraf *obj2;
    int v_limit;
    int h_limit;
    bool sesion=false;
    QTimer *timer_movimiento;
    std::vector <bolagraf*> bolas;
    std::vector <std::vector<int>> coef;
    //int speed; //para el dial
};

#endif // MAINWINDOW_H
