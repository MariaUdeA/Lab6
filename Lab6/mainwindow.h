#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include "bolagraf.h"
#include <QDebug>
#include <QTimer>

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

private slots:
    void actualizar();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    bolagraf *obj;
    int v_limit;
    int h_limit;

    QTimer *timer_movimiento;

};

#endif // MAINWINDOW_H
