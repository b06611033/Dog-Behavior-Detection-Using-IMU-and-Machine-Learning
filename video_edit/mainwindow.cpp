
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <QFile>
#include <QTextStream>
#include "QVector"
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/video.hpp>

using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile file("unlabeled prediction 10.18.csv");
    file.open(QIODevice::ReadWrite);
    QTextStream stream(&file);

    QString timestamp[3600] = {};
    QString classification[3600] = {};
    QString separator1(",");
    QString separator2(":");
    stream.readLine();
    int start_time = 60*11+5;

    while (stream.atEnd() == false)
    {
        QString line = stream.readLine();
        QString time;
        QString hour;
        QString minute;
        QString second;
        QString behavior;
        int converted_time = 0;
        int array_position = 0;
        time = line.split(separator1).at(0);
        hour = time.split(separator2).at(0);
        minute = time.split(separator2).at(1);
        second = time.split(separator2).at(2);
        behavior = line.split(separator1).at(1);


            converted_time = minute.toInt()*60 + second.toInt();


        array_position = converted_time - start_time;
        timestamp[array_position] = time;
        classification[array_position] = behavior;
    }
     file.close();

     for (int i=0; i<3600; i++)
     {

         ui->display->append(timestamp[i] + " " + classification[i] + " " + QString::number(i));

     }

    VideoCapture cap ("dog 2020.10.18.h264");
    //VideoWriter writer("20201018.avi", CV_FOURCC('M', 'J', 'P', 'G'), 30.0, Size(640, 480));
    double rate = cap.get(CV_CAP_PROP_FPS);  //fucking wrong, should be 24 instead of 25
    int count = cap.get(CV_CAP_PROP_FRAME_COUNT);
    ui->display->append(QString::number(count));


    //ui->display->append(QString::number(rate));

    while (cap.isOpened())
    {
        Mat frame;
        cap.read(frame);

        if (frame.empty())
              break;


        //int time = cap.get(CAP_PROP_POS_MSEC);
        int time2 = cap.get(CAP_PROP_POS_FRAMES)/24;


        int k = time2;
        if (classification[k].isEmpty() == 0)
        {
        putText(frame, classification[k].toStdString(), Point(0, 60), 2, 2, Scalar(0, 0, 255), 2);
        }
        //writer.write(frame);
       imshow("fuck",frame);
        char c = (char)waitKey(1000/150); //video fps(the value doesn't effect puttext, but effects how fast the video is played)
                    if (c == 27)
                        break;
    }
    cap.release();
    //writer.release();






}

MainWindow::~MainWindow()
{
    delete ui;
}

