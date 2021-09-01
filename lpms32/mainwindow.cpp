#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "LpmsSensorManagerI.h"
#include "LpmsSensorI.h"
#include "ImuData.h"
#include "DeviceListItem.h"
#include "LpmsDefinitions.h"
#include "QDebug"
#include "QMessageBox"
#include "QTime"
#include "QVector"
#include "QtCharts"
#include "QChartView"
#include "QLineSeries"
#include "chartdialog.h"
#include <QVBoxLayout>
#include <QKeyEvent>
#include<QTextStream>
#include<QScatterSeries>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include<QPointF>
#include <complex>
#include <iostream>
#include <QtMath>
#include <QFile>
#include <QTextStream>
#include <QTime>

//double total ;
//double average ;
//double variance ;
int num ;
//double dev;
int connect_time;
//double real_time;
QVector<double>acc_x ;
QVector<double>acc_y ;
QVector<double>acc_z ;
QVector<double>gyro_x ;
QVector<double>gyro_y ;
QVector<double>gyro_z ;
QVector<double>mag_x ;
QVector<double>mag_y ;
QVector<double>mag_z ;
QVector<QString>data_timestamp ;
QVector<double>timestamp;
bool esc_was_pressed ;
using namespace std;
using namespace QtCharts;
using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setText("please set time on a new line and press set_time button");
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_connect_clicked()
{
    //total = 0;
    num = 0;
    acc_x.clear();
    acc_y.clear();
    acc_z.clear();
    gyro_x.clear();
    gyro_y.clear();
    gyro_z.clear();
    mag_x.clear();
    mag_y.clear();
    mag_z.clear();
    data_timestamp.clear();
    timestamp.clear();
    manager = LpmsSensorManagerFactory();
    LpmsSensorI* lpms = manager->addSensor(DEVICE_LPMS_B2,"00:04:3E:9B:A3:62");
    QTimer *timer = new QTimer(this);
    timer->start(connect_time);
    esc_was_pressed = false;
    while(1)
    {
    if (timer->remainingTime()==0)
    {
        break;
    }
    else if (lpms->getConnectionStatus() == SENSOR_CONNECTION_CONNECTED)
    {
        d = lpms->getCurrentData();
        QTime time = QTime::currentTime();
        if (d.timeStamp - timestamp[num-1] < 0.03 )
        {

        }
        else
        {
            ui->display->append( QString::number(d.a[0]) + " " + time.toString("hh:mm:ss ")) ;
            //total = total+d.a[0];
            acc_x.push_back(d.a[0]);
            acc_y.push_back(d.a[1]);
            acc_z.push_back(d.a[2]);
            gyro_x.push_back(d.g[0]);
            gyro_y.push_back(d.g[1]);
            gyro_z.push_back(d.g[2]);
            mag_x.push_back(d.b[0]);
            mag_y.push_back(d.b[1]);
            mag_z.push_back(d.b[2]);
            data_timestamp.push_back(time.toString("hh:mm:ss "));
            timestamp.push_back(d.timeStamp);
            num = num+1;
        }


    }

    else if (lpms->getConnectionStatus() == SENSOR_CONNECTION_FAILED)
    {
        QMessageBox::warning(NULL,  "warning",  "unconnected", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }    
    }
    MainWindow f;
    f.save(acc_x,acc_y,acc_z,gyro_x,gyro_y,gyro_z,mag_x,mag_y,mag_z,data_timestamp);
    manager->removeSensor(lpms);
    delete manager;
}

void MainWindow::on_close_clicked()
{
    acc_x.clear();
    acc_y.clear();
    acc_z.clear();
    gyro_x.clear();
    gyro_y.clear();
    gyro_z.clear();
    mag_x.clear();
    mag_y.clear();
    mag_z.clear();
    timestamp.clear();
    data_timestamp.clear();
    close();
}

void MainWindow::on_set_time_clicked()
{
    QString text = ui->textEdit->toPlainText();
    QTextStream str(&text, QIODevice::ReadOnly);
    QString line;
    for (int n = 0; !str.atEnd() && n < 3; ++n)
      line = str.readLine();
   ui->textEdit->setText("the time is " + line + " seconds");
   connect_time = line.toInt()*1000;
}

void MainWindow::save(QVector<double>a,QVector<double>b,QVector<double>c,QVector<double>d,QVector<double>e,QVector<double>f,QVector<double>g,QVector<double>h,QVector<double>j,QVector<QString>k)
{
    QString filename = "data.csv";
        QFile file(filename);
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            stream << "accx" << "," << "accy" << "," << "accz" << "," << "gyrox" << "," << "gyroy" << "," << "gyroz" << "," << "magx" << "," << "magy" << "," << "magz" << ","  << "timestamp" << endl;
           for (int i=0; i < a.size(); i++ )
            stream << a[i] << "," << b[i] << "," << c[i] << "," << d[i] << "," << e[i] << "," << f[i] << "," << g[i] << "," << h[i] << "," << j[i] << ","  << k[i] << endl;
        }
}



//f = i * Fs / N,  f is the bin frequency in Hz and i is the bin index and N is the number of points in the FFT and Fs is the sampling rate
//for walking, f = 7*100/793 = 0.89 hz
//for running, f = 33*100/793 = 4.16 hz

