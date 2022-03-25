/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Start;
    QPushButton *Pause;
    QPushButton *Random;
    QPushButton *Restart;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *vyLineEdit;
    QLabel *label_2;
    QLineEdit *vxLineEdit;
    QLabel *label_3;
    QLineEdit *radLineEdit;
    QLabel *label_4;
    QLineEdit *masLineEdit;
    QPushButton *Apply;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1145, 667);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 10, 1100, 550));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 550, 340, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Start = new QPushButton(horizontalLayoutWidget);
        Start->setObjectName(QString::fromUtf8("Start"));

        horizontalLayout->addWidget(Start);

        Pause = new QPushButton(horizontalLayoutWidget);
        Pause->setObjectName(QString::fromUtf8("Pause"));

        horizontalLayout->addWidget(Pause);

        Random = new QPushButton(horizontalLayoutWidget);
        Random->setObjectName(QString::fromUtf8("Random"));

        horizontalLayout->addWidget(Random);

        Restart = new QPushButton(horizontalLayoutWidget);
        Restart->setObjectName(QString::fromUtf8("Restart"));

        horizontalLayout->addWidget(Restart);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(390, 550, 571, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        vyLineEdit = new QLineEdit(horizontalLayoutWidget_2);
        vyLineEdit->setObjectName(QString::fromUtf8("vyLineEdit"));

        horizontalLayout_2->addWidget(vyLineEdit);

        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        vxLineEdit = new QLineEdit(horizontalLayoutWidget_2);
        vxLineEdit->setObjectName(QString::fromUtf8("vxLineEdit"));

        horizontalLayout_2->addWidget(vxLineEdit);

        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        radLineEdit = new QLineEdit(horizontalLayoutWidget_2);
        radLineEdit->setObjectName(QString::fromUtf8("radLineEdit"));

        horizontalLayout_2->addWidget(radLineEdit);

        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        masLineEdit = new QLineEdit(horizontalLayoutWidget_2);
        masLineEdit->setObjectName(QString::fromUtf8("masLineEdit"));

        horizontalLayout_2->addWidget(masLineEdit);

        Apply = new QPushButton(horizontalLayoutWidget_2);
        Apply->setObjectName(QString::fromUtf8("Apply"));

        horizontalLayout_2->addWidget(Apply);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1145, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        Pause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        Random->setText(QCoreApplication::translate("MainWindow", "Random", nullptr));
        Restart->setText(QCoreApplication::translate("MainWindow", "Restart", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Vy:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Vx:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Radio:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Masa:", nullptr));
        Apply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
