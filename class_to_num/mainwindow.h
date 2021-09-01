#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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




private:
    Ui::MainWindow *ui;
    void class_to_num(QString filename);
    void class_to_one_hot_vec(QString filename);
    void num_to_class (QString filename);
    void test();
};
#endif // MAINWINDOW_H
