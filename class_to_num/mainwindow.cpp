#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <QFile>
#include <QTextStream>
#include "QVector"
#include <iostream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString file = "combined data v5.csv";

    test();
    //class_to_num(file);
   // class_to_one_hot_vec(file);
    num_to_class(file);
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::class_to_one_hot_vec(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadWrite);
    QTextStream stream(&file);

    QStringList list;
    QList<QString> classification;
    classification.clear();


    QString separator(",");
    stream.readLine();
    while (stream.atEnd() == false)
    {
        QString line = stream.readLine();
        for(int i=0;i<37;i++)
        {
         list.append(line.split(separator).at(i));
        }
    }


    for (int i=36;i<list.size();i=i+37)
    {
           classification.append(list.at(i)) ;
    }


     QList<QString> rest;
     QList<QString> eat;
     QList<QString> stand;
     QList<QString> walk;
     QList<QString> run;

    for (int i = 0; i < classification.size();i = i++ )
    {
        if (classification.at(i) == "0")
        {
           rest.append("1");
           eat.append("0");
           stand.append("0");
           walk.append("0");
           run.append("0");
        }
        if (classification.at(i) == "1")
        {
            rest.append("0");
            eat.append("1");
            stand.append("0");
            walk.append("0");
            run.append("0");
        }
        if (classification.at(i) == "2")
        {
            rest.append("0");
            eat.append("0");
            stand.append("1");
            walk.append("0");
            run.append("0");
        }
        if (classification.at(i) == "3")
        {
            rest.append("0");
            eat.append("0");
            stand.append("0");
            walk.append("1");
            run.append("0");
        }
        if (classification.at(i) == "4")
        {
            rest.append("0");
            eat.append("0");
            stand.append("0");
            walk.append("0");
            run.append("1");
        }
    }
    for (int i=0;i<rest.size();i++)
     {
        stream << rest.at(i) << "," << eat.at(i) << "," << stand.at(i) << "," << walk.at(i) << "," << run.at(i)  << endl;

     }
    file.close();

}

void MainWindow::class_to_num(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadWrite);
    QTextStream stream(&file);

    QStringList list;

    QList<QString> classification;
    classification.clear();

    QString separator(",");
    stream.readLine();
    while (stream.atEnd() == false)
    {
        QString line = stream.readLine();
        for(int i=0;i<19;i++)
        {
         list.append(line.split(separator).at(i));
        }
    }


    for (int i=18;i<list.size();i=i+19)
    {
           classification.append(list.at(i)) ;
    }


     QList<double> classification2;

    for (int i = 0; i < classification.size();i = i++ )
    {
        if (classification.at(i) == "resting")
        {
           classification2.append(0);
        }
        if (classification.at(i) == "eating")
        {
            classification2.append(1);
        }
        if (classification.at(i) == "standing")
        {
            classification2.append(2);
        }
        if (classification.at(i) == "walking")
        {
            classification2.append(3);
        }
        if (classification.at(i) == "running")
        {
            classification2.append(4);
        }
    }
    for (int i=0;i<classification2.size();i++)
     {
        stream << classification2.at(i) << endl;

     }
    file.close();
}

void MainWindow::num_to_class(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadWrite);
    QTextStream stream(&file);

    QStringList list;

    QList<QString> classification;
    QList<QString> classification2;
    classification.clear();

    QString separator(",");
    stream.readLine();
    while (stream.atEnd() == false)
    {
        QString line = stream.readLine();
        for(int i=0;i<37;i++)
        {
         list.append(line.split(separator).at(i));
        }
    }


    for (int i=36;i<list.size();i=i+37)
    {
           classification2.append(list.at(i)) ;
    }




    for (int i = 0; i < classification2.size();i = i++ )
    {
        if (classification2.at(i) == "0")
        {
           classification.append("resting");
        }
        if (classification2.at(i) == "1")
        {
            classification.append("eating");
        }
        if (classification2.at(i) == "2")
        {
            classification.append("standing");
        }
        if (classification2.at(i) == "3")
        {
            classification.append("walking");
        }
        if (classification2.at(i) == "4")
        {
            classification.append("running");
        }
    }
    for (int i=0;i<classification.size();i++)
     {
        stream << classification.at(i) << endl;

     }
    file.close();
}

void MainWindow::test()
{
    qDebug() << "success";
}




