/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *connect;
    QPushButton *close;
    QPushButton *std;
    QTextBrowser *display;
    QPushButton *classify;
    QPushButton *draw;
    QTextEdit *textEdit;
    QPushButton *set_time;
    QPushButton *fourier;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        connect = new QPushButton(centralwidget);
        connect->setObjectName(QString::fromUtf8("connect"));
        connect->setGeometry(QRect(50, 240, 93, 61));
        close = new QPushButton(centralwidget);
        close->setObjectName(QString::fromUtf8("close"));
        close->setGeometry(QRect(270, 430, 93, 51));
        std = new QPushButton(centralwidget);
        std->setObjectName(QString::fromUtf8("std"));
        std->setGeometry(QRect(200, 240, 93, 61));
        display = new QTextBrowser(centralwidget);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(50, 30, 256, 192));
        classify = new QPushButton(centralwidget);
        classify->setObjectName(QString::fromUtf8("classify"));
        classify->setGeometry(QRect(360, 240, 93, 61));
        draw = new QPushButton(centralwidget);
        draw->setObjectName(QString::fromUtf8("draw"));
        draw->setGeometry(QRect(510, 237, 93, 61));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(660, 110, 104, 87));
        set_time = new QPushButton(centralwidget);
        set_time->setObjectName(QString::fromUtf8("set_time"));
        set_time->setGeometry(QRect(670, 237, 93, 61));
        fourier = new QPushButton(centralwidget);
        fourier->setObjectName(QString::fromUtf8("fourier"));
        fourier->setGeometry(QRect(430, 427, 93, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
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
        connect->setText(QCoreApplication::translate("MainWindow", "connect", nullptr));
        close->setText(QCoreApplication::translate("MainWindow", "close", nullptr));
        std->setText(QCoreApplication::translate("MainWindow", "std", nullptr));
        classify->setText(QCoreApplication::translate("MainWindow", "classify", nullptr));
        draw->setText(QCoreApplication::translate("MainWindow", "draw", nullptr));
        set_time->setText(QCoreApplication::translate("MainWindow", "set_time", nullptr));
        fourier->setText(QCoreApplication::translate("MainWindow", "fourier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
