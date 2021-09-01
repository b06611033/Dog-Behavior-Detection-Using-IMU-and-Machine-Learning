#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <LpmsSensorI.h>
#include <LpmsSensorManagerI.h>
#include <QTimer>
#include <QtMath>
#include <QString>
#include <QQuaternion>
#include <QFileDialog>
#include <QDir>
#include <QStandardPaths>
#include <QSettings>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_connect_clicked();

    void on_close_clicked();



    void on_set_time_clicked();


private:
    Ui::MainWindow *ui;
    LpmsSensorManagerI *manager;
    ImuData d;
    //void keyPressEvent(QKeyEvent* event);
    void save(QVector<double>a,QVector<double>b,QVector<double>c,QVector<double>d,QVector<double>e,QVector<double>f,QVector<double>g,QVector<double>h,QVector<double>j,QVector<QString>k);

};
#endif // MAINWINDOW_H
