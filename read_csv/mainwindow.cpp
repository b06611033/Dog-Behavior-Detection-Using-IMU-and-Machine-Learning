#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <QFile>
#include <QTextStream>
#include "QVector"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
        ui->setupUi(this);
        QFile file("morning_test.csv");
        file.open(QIODevice::ReadWrite);

        QTextStream stream(&file);
        QStringList list;
        QList<double> accx;
        QList<double> accy;
        QList<double> accz;
        QList<double> gyrox;
        QList<double> gyroy;
        QList<double> gyroz;
        QList<double> magx;
        QList<double> magy;
        QList<double> magz;
        QList<QString> classification;
        accx.clear();
        accy.clear();
        accz.clear();
        gyrox.clear();
        gyroy.clear();
        gyroz.clear();
        magx.clear();
        magy.clear();
        magz.clear();
        classification.clear();

        QString separator(",");
        stream.readLine();
        while (stream.atEnd() == false)
        {
            QString line = stream.readLine();
            for(int i=0;i<10;i++)
            {
             list.append(line.split(separator).at(i));
            }
        }



        for (int i=0;i<list.size();i=i+10)
        {
               accx.append(list.at(i).toDouble()) ;
        }
        for (int i=1;i<list.size();i=i+10)
        {
               accy.append(list.at(i).toDouble()) ;
        }
        for (int i=2;i<list.size();i=i+10)
        {
               accz.append(list.at(i).toDouble()) ;
        }
        for (int i=3;i<list.size();i=i+10)
        {
               gyrox.append(list.at(i).toDouble()) ;
        }
        for (int i=4;i<list.size();i=i+10)
        {
               gyroy.append(list.at(i).toDouble()) ;
        }
        for (int i=5;i<list.size();i=i+10)
        {
               gyroz.append(list.at(i).toDouble()) ;
        }
        for (int i=6;i<list.size();i=i+10)
        {
               classification.append(list.at(i)) ;
        }
        for (int i=7;i<list.size();i=i+10)
        {
              magx.append(list.at(i).toDouble()) ;
        }
        for (int i=8;i<list.size();i=i+10)
        {
               magy.append(list.at(i).toDouble()) ;
        }
        for (int i=9;i<list.size();i=i+10)
        {
               magz.append(list.at(i).toDouble()) ;
        }



        QList<double> accx_avg;
        QList<double> accy_avg;
        QList<double> accz_avg;
        QList<double> gyrox_avg;
        QList<double> gyroy_avg;
        QList<double> gyroz_avg;
        QList<double> magx_avg;
        QList<double> magy_avg;
        QList<double> magz_avg;
        QList<double> accx_std;
        QList<double> accy_std;
        QList<double> accz_std;
        QList<double> gyrox_std;
        QList<double> gyroy_std;
        QList<double> gyroz_std;
        QList<double> magx_std;
        QList<double> magy_std;
        QList<double> magz_std;

        QList<double> accx_max;
        QList<double> accy_max;
        QList<double> accz_max;
        QList<double> gyrox_max;
        QList<double> gyroy_max;
        QList<double> gyroz_max;
        QList<double> magx_max;
        QList<double> magy_max;
        QList<double> magz_max;
        QList<double> accx_min;
        QList<double> accy_min;
        QList<double> accz_min;
        QList<double> gyrox_min;
        QList<double> gyroy_min;
        QList<double> gyroz_min;
        QList<double> magx_min;
        QList<double> magy_min;
        QList<double> magz_min;

        QList<QString> classification2;

        accx_avg.clear();
        accy_avg.clear();
        accz_avg.clear();
        gyrox_avg.clear();
        gyroy_avg.clear();
        gyroz_avg.clear();
        magx_avg.clear();
        magy_avg.clear();
        magz_avg.clear();
        accx_std.clear();
        accy_std.clear();
        accz_std.clear();
        gyrox_std.clear();
        gyroy_std.clear();
        gyroz_std.clear();
        magx_std.clear();
        magy_std.clear();
        magz_std.clear();

        accx_max.clear();
        accy_max.clear();
        accz_max.clear();
        gyrox_max.clear();
        gyroy_max.clear();
        gyroz_max.clear();
        magx_max.clear();
        magy_max.clear();
        magz_max.clear();
        accx_min.clear();
        accy_min.clear();
        accz_min.clear();
        gyrox_min.clear();
        gyroy_min.clear();
        gyroz_min.clear();
        magx_min.clear();
        magy_min.clear();
        magz_min.clear();

        classification2.clear();

        double sum_accx = 0;
        double sum_accy = 0;
        double sum_accz = 0;
        double sum_gyrox = 0;
        double sum_gyroy = 0;
        double sum_gyroz = 0;
        double sum_magx = 0;
        double sum_magy = 0;
        double sum_magz = 0;
        double var_accx = 0;
        double var_accy = 0;
        double var_accz = 0;
        double var_gyrox = 0;
        double var_gyroy = 0;
        double var_gyroz = 0;
        double var_magx = 0;
        double var_magy = 0;
        double var_magz = 0;

        double max_accx = 0;
        double max_accy = 0;
        double max_accz = 0;
        double max_gyrox = 0;
        double max_gyroy = 0;
        double max_gyroz = 0;
        double max_magx = 0;
        double max_magy = 0;
        double max_magz = 0;
        double min_accx = 1000;
        double min_accy = 1000;
        double min_accz = 1000;
        double min_gyrox = 1000;
        double min_gyroy = 1000;
        double min_gyroz = 1000;
        double min_magx = 1000;
        double min_magy = 1000;
        double min_magz = 1000;

        bool classified = true;
        int sample_fold = 8;

        for (int i = 0; i < accx.size()-sample_fold;i = i+sample_fold )
        {
            for (int j = i; j<i+sample_fold-1; j++)
            {
                if (classification.at(j) == classification.at(j+1) )
                {
                    classified = true;
                }
                else
                {
                    classified = false;
                    break;
                }
            }

            if (classified == true)
            {

               for(int j = i; j<i+sample_fold; j++)
                 {
                   sum_accx = sum_accx + accx.at(j);
                   sum_accy = sum_accy + accy.at(j);
                   sum_accz = sum_accz + accz.at(j);
                   sum_gyrox = sum_gyrox + gyrox.at(j);
                   sum_gyroy = sum_gyroy + gyroy.at(j);
                   sum_gyroz = sum_gyroz + gyroz.at(j);
                   sum_magx = sum_magx + magx.at(j);
                   sum_magy = sum_magy + magy.at(j);
                   sum_magz = sum_magz + magz.at(j);

                 }

                accx_avg.append(sum_accx/sample_fold);
                accy_avg.append(sum_accy/sample_fold);
                accz_avg.append(sum_accz/sample_fold);
                gyrox_avg.append(sum_gyrox/sample_fold);
                gyroy_avg.append(sum_gyroy/sample_fold);
                gyroz_avg.append(sum_gyroz/sample_fold);
                magx_avg.append(sum_magx/sample_fold);
                magy_avg.append(sum_magy/sample_fold);
                magz_avg.append(sum_magz/sample_fold);
                classification2.append(classification.at(i));

                for(int j = i; j<i+sample_fold; j++)
                  {
                    var_accx = var_accx + pow(accx.at(j)-sum_accx/sample_fold,2);
                    var_accy = var_accy + pow(accy.at(j)-sum_accy/sample_fold,2);
                    var_accz = var_accz + pow(accz.at(j)-sum_accz/sample_fold,2);
                    var_gyrox = var_gyrox + pow(gyrox.at(j)-sum_gyrox/sample_fold,2);
                    var_gyroy = var_gyroy + pow(gyroy.at(j)-sum_gyroy/sample_fold,2);
                    var_gyroz = var_gyroz + pow(gyroz.at(j)-sum_gyroz/sample_fold,2);
                    var_magx = var_magx + pow(magx.at(j)-sum_magx/sample_fold,2);
                    var_magy = var_magy + pow(magy.at(j)-sum_magy/sample_fold,2);
                    var_magz = var_magz + pow(magz.at(j)-sum_magz/sample_fold,2);
                  }

                accx_std.append(pow(var_accx/sample_fold,0.5));
                accy_std.append(pow(var_accy/sample_fold,0.5));
                accz_std.append(pow(var_accz/sample_fold,0.5));
                gyrox_std.append(pow(var_gyrox/sample_fold,0.5));
                gyroy_std.append(pow(var_gyroy/sample_fold,0.5));
                gyroz_std.append(pow(var_gyroz/sample_fold,0.5));
                magx_std.append(pow(var_magx/sample_fold,0.5));
                magy_std.append(pow(var_magy/sample_fold,0.5));
                magz_std.append(pow(var_magz/sample_fold,0.5));

                for (int j=i; j<i+sample_fold; j++)
                  {
                    if (abs(accx.at(j)) > max_accx)
                    {
                        max_accx = abs(accx.at(j));
                    }
                    if (abs(accy.at(j)) > max_accy)
                    {
                        max_accy = abs(accy.at(j));
                    }
                    if (abs(accz.at(j)) > max_accz)
                    {
                        max_accz = abs(accz.at(j));
                    }
                    if (abs(gyrox.at(j)) > max_gyrox)
                    {
                        max_gyrox = abs(gyrox.at(j));
                    }
                    if (abs(gyroy.at(j)) > max_gyroy)
                    {
                        max_gyroy = abs(gyroy.at(j));
                    }
                    if (abs(gyroz.at(j)) > max_gyroz)
                    {
                        max_gyroz = abs(gyroz.at(j));
                    }
                    if (abs(magx.at(j)) > max_magx)
                    {
                        max_magx = abs(magx.at(j));
                    }
                    if (abs(magy.at(j)) > max_magy)
                    {
                        max_magy = abs(magy.at(j));
                    }
                    if (abs(magz.at(j)) > max_magz)
                    {
                        max_magz = abs(magz.at(j));
                    }
                  }

                  accx_max.append(max_accx);
                  accy_max.append(max_accy);
                  accz_max.append(max_accz);
                  gyrox_max.append(max_gyrox);
                  gyroy_max.append(max_gyroy);
                  gyroz_max.append(max_gyroz);
                  magx_max.append(max_magx);
                  magy_max.append(max_magy);
                  magz_max.append(max_magz);

                  for (int j=i; j<i+sample_fold; j++)
                    {
                      if (abs(accx.at(j)) < min_accx)
                      {
                          min_accx = abs(accx.at(j));
                      }
                      if (abs(accy.at(j)) < min_accy)
                      {
                          min_accy = abs(accy.at(j));
                      }
                      if (abs(accz.at(j)) < min_accz)
                      {
                          min_accz = abs(accz.at(j));
                      }
                      if (abs(gyrox.at(j)) < min_gyrox)
                      {
                          min_gyrox = abs(gyrox.at(j));
                      }
                      if (abs(gyroy.at(j)) < min_gyroy)
                      {
                          min_gyroy = abs(gyroy.at(j));
                      }
                      if (abs(gyroz.at(j)) < min_gyroz)
                      {
                          min_gyroz = abs(gyroz.at(j));
                      }
                      if (abs(magx.at(j)) < min_magx)
                      {
                          min_magx = abs(magx.at(j));
                      }
                      if (abs(magy.at(j)) < min_magy)
                      {
                          min_magy = abs(magy.at(j));
                      }
                      if (abs(magz.at(j)) < min_magz)
                      {
                          min_magz = abs(magz.at(j));
                      }
                    }

                    accx_min.append(min_accx);
                    accy_min.append(min_accy);
                    accz_min.append(min_accz);
                    gyrox_min.append(min_gyrox);
                    gyroy_min.append(min_gyroy);
                    gyroz_min.append(min_gyroz);
                    magx_min.append(min_magx);
                    magy_min.append(min_magy);
                    magz_min.append(min_magz);


                 sum_accx = 0;
                 sum_accy = 0;
                 sum_accz = 0;
                 sum_gyrox = 0;
                 sum_gyroy = 0;
                 sum_gyroz = 0;
                 sum_magx = 0;
                 sum_magy = 0;
                 sum_magz = 0;
                 var_accx = 0;
                 var_accy = 0;
                 var_accz = 0;
                 var_gyrox = 0;
                 var_gyroy = 0;
                 var_gyroz = 0;
                 var_magx = 0;
                 var_magy = 0;
                 var_magz = 0;

                 max_accx = 0;
                 max_accy = 0;
                 max_accz = 0;
                 max_gyrox = 0;
                 max_gyroy = 0;
                 max_gyroz = 0;
                 max_magx = 0;
                 max_magy = 0;
                 max_magz = 0;
                 min_accx = 1000;
                 min_accy = 1000;
                 min_accz = 1000;
                 min_gyrox = 1000;
                 min_gyroy = 1000;
                 min_gyroz = 1000;
                 min_magx = 1000;
                 min_magy = 1000;
                 min_magz = 1000;

            }
            classified = true;

        }


        QList<double> accx_avg2;
        QList<double> accy_avg2;
        QList<double> accz_avg2;
        QList<double> gyrox_avg2;
        QList<double> gyroy_avg2;
        QList<double> gyroz_avg2;
        QList<double> magx_avg2;
        QList<double> magy_avg2;
        QList<double> magz_avg2;
        QList<double> accx_std2;
        QList<double> accy_std2;
        QList<double> accz_std2;
        QList<double> gyrox_std2;
        QList<double> gyroy_std2;
        QList<double> gyroz_std2;
        QList<double> magx_std2;
        QList<double> magy_std2;
        QList<double> magz_std2;

        QList<double> accx_max2;
        QList<double> accy_max2;
        QList<double> accz_max2;
        QList<double> gyrox_max2;
        QList<double> gyroy_max2;
        QList<double> gyroz_max2;
        QList<double> magx_max2;
        QList<double> magy_max2;
        QList<double> magz_max2;
        QList<double> accx_min2;
        QList<double> accy_min2;
        QList<double> accz_min2;
        QList<double> gyrox_min2;
        QList<double> gyroy_min2;
        QList<double> gyroz_min2;
        QList<double> magx_min2;
        QList<double> magy_min2;
        QList<double> magz_min2;

        QList<QString> classification3;

        accx_avg2.clear();
        accy_avg2.clear();
        accz_avg2.clear();
        gyrox_avg2.clear();
        gyroy_avg2.clear();
        gyroz_avg2.clear();
        magx_avg2.clear();
        magy_avg2.clear();
        magz_avg2.clear();
        accx_std2.clear();
        accy_std2.clear();
        accz_std2.clear();
        gyrox_std2.clear();
        gyroy_std2.clear();
        gyroz_std2.clear();
        magx_std2.clear();
        magy_std2.clear();
        magz_std2.clear();

        accx_max2.clear();
        accy_max2.clear();
        accz_max2.clear();
        gyrox_max2.clear();
        gyroy_max2.clear();
        gyroz_max2.clear();
        magx_max2.clear();
        magy_max2.clear();
        magz_max2.clear();
        accx_min2.clear();
        accy_min2.clear();
        accz_min2.clear();
        gyrox_min2.clear();
        gyroy_min2.clear();
        gyroz_min2.clear();
        magx_min2.clear();
        magy_min2.clear();
        magz_min2.clear();

        classification3.clear();

        int half_sample_fold = 0;

        if (sample_fold%2 == 1)
        {
            half_sample_fold = (sample_fold-1)/2;
        }
        else
        {
            half_sample_fold = sample_fold/2;
        }


        for (int i = half_sample_fold; i < accx.size()-sample_fold;i = i+sample_fold )
        {
            for (int j = i; j<i+sample_fold-1; j++)
            {
                if (classification.at(j) == classification.at(j+1) )
                {
                    classified = true;
                }
                else
                {
                    classified = false;
                    break;
                }
            }

            if (classified == true)
            {

               for(int j = i; j<i+sample_fold ; j++)
                 {
                   sum_accx = sum_accx + accx.at(j);
                   sum_accy = sum_accy + accy.at(j);
                   sum_accz = sum_accz + accz.at(j);
                   sum_gyrox = sum_gyrox + gyrox.at(j);
                   sum_gyroy = sum_gyroy + gyroy.at(j);
                   sum_gyroz = sum_gyroz + gyroz.at(j);
                   sum_magx = sum_magx + magx.at(j);
                   sum_magy = sum_magy + magy.at(j);
                   sum_magz = sum_magz + magz.at(j);
                 }

                accx_avg2.append(sum_accx/sample_fold);
                accy_avg2.append(sum_accy/sample_fold);
                accz_avg2.append(sum_accz/sample_fold);
                gyrox_avg2.append(sum_gyrox/sample_fold);
                gyroy_avg2.append(sum_gyroy/sample_fold);
                gyroz_avg2.append(sum_gyroz/sample_fold);
                magx_avg2.append(sum_magx/sample_fold);
                magy_avg2.append(sum_magy/sample_fold);
                magz_avg2.append(sum_magz/sample_fold);
                classification3.append(classification.at(i));

                for(int j = i; j<i+sample_fold; j++)
                  {
                    var_accx = var_accx + pow(accx.at(j)-sum_accx/sample_fold,2);
                    var_accy = var_accy + pow(accy.at(j)-sum_accy/sample_fold,2);
                    var_accz = var_accz + pow(accz.at(j)-sum_accz/sample_fold,2);
                    var_gyrox = var_gyrox + pow(gyrox.at(j)-sum_gyrox/sample_fold,2);
                    var_gyroy = var_gyroy + pow(gyroy.at(j)-sum_gyroy/sample_fold,2);
                    var_gyroz = var_gyroz + pow(gyroz.at(j)-sum_gyroz/sample_fold,2);
                    var_magx = var_magx + pow(magx.at(j)-sum_magx/sample_fold,2);
                    var_magy = var_magy + pow(magy.at(j)-sum_magy/sample_fold,2);
                    var_magz = var_magz + pow(magz.at(j)-sum_magz/sample_fold,2);
                  }

                accx_std2.append(pow(var_accx/sample_fold,0.5));
                accy_std2.append(pow(var_accy/sample_fold,0.5));
                accz_std2.append(pow(var_accz/sample_fold,0.5));
                gyrox_std2.append(pow(var_gyrox/sample_fold,0.5));
                gyroy_std2.append(pow(var_gyroy/sample_fold,0.5));
                gyroz_std2.append(pow(var_gyroz/sample_fold,0.5));
                magx_std2.append(pow(var_magx/sample_fold,0.5));
                magy_std2.append(pow(var_magy/sample_fold,0.5));
                magz_std2.append(pow(var_magz/sample_fold,0.5));


                for (int j=i; j<i+sample_fold; j++)
                  {
                    if (abs(accx.at(j)) > max_accx)
                    {
                        max_accx = abs(accx.at(j));
                    }
                    if (abs(accy.at(j)) > max_accy)
                    {
                        max_accy = abs(accy.at(j));
                    }
                    if (abs(accz.at(j)) > max_accz)
                    {
                        max_accz = abs(accz.at(j));
                    }
                    if (abs(gyrox.at(j)) > max_gyrox)
                    {
                        max_gyrox = abs(gyrox.at(j));
                    }
                    if (abs(gyroy.at(j)) > max_gyroy)
                    {
                        max_gyroy = abs(gyroy.at(j));
                    }
                    if (abs(gyroz.at(j)) > max_gyroz)
                    {
                        max_gyroz = abs(gyroz.at(j));
                    }
                    if (abs(magx.at(j)) > max_magx)
                    {
                        max_magx = abs(magx.at(j));
                    }
                    if (abs(magy.at(j)) > max_magy)
                    {
                        max_magy = abs(magy.at(j));
                    }
                    if (abs(magz.at(j)) > max_magz)
                    {
                        max_magz = abs(magz.at(j));
                    }
                  }

                  accx_max2.append(max_accx);
                  accy_max2.append(max_accy);
                  accz_max2.append(max_accz);
                  gyrox_max2.append(max_gyrox);
                  gyroy_max2.append(max_gyroy);
                  gyroz_max2.append(max_gyroz);
                  magx_max2.append(max_magx);
                  magy_max2.append(max_magy);
                  magz_max2.append(max_magz);

                  for (int j=i; j<i+sample_fold; j++)
                    {
                      if (abs(accx.at(j)) < min_accx)
                      {
                          min_accx = abs(accx.at(j));
                      }
                      if (abs(accy.at(j)) < min_accy)
                      {
                          min_accy = abs(accy.at(j));
                      }
                      if (abs(accz.at(j)) < min_accz)
                      {
                          min_accz = abs(accz.at(j));
                      }
                      if (abs(gyrox.at(j)) < min_gyrox)
                      {
                          min_gyrox = abs(gyrox.at(j));
                      }
                      if (abs(gyroy.at(j)) < min_gyroy)
                      {
                          min_gyroy = abs(gyroy.at(j));
                      }
                      if (abs(gyroz.at(j)) < min_gyroz)
                      {
                          min_gyroz = abs(gyroz.at(j));
                      }
                      if (abs(magx.at(j)) < min_magx)
                      {
                          min_magx = abs(magx.at(j));
                      }
                      if (abs(magy.at(j)) < min_magy)
                      {
                          min_magy = abs(magy.at(j));
                      }
                      if (abs(magz.at(j)) < min_magz)
                      {
                          min_magz = abs(magz.at(j));
                      }
                    }

                    accx_min2.append(min_accx);
                    accy_min2.append(min_accy);
                    accz_min2.append(min_accz);
                    gyrox_min2.append(min_gyrox);
                    gyroy_min2.append(min_gyroy);
                    gyroz_min2.append(min_gyroz);
                    magx_min2.append(min_magx);
                    magy_min2.append(min_magy);
                    magz_min2.append(min_magz);



                 sum_accx = 0;
                 sum_accy = 0;
                 sum_accz = 0;
                 sum_gyrox = 0;
                 sum_gyroy = 0;
                 sum_gyroz = 0;
                 sum_magx = 0;
                 sum_magy = 0;
                 sum_magz = 0;
                 var_accx = 0;
                 var_accy = 0;
                 var_accz = 0;
                 var_gyrox = 0;
                 var_gyroy = 0;
                 var_gyroz = 0;
                 var_magx = 0;
                 var_magy = 0;
                 var_magz = 0;

                 max_accx = 0;
                 max_accy = 0;
                 max_accz = 0;
                 max_gyrox = 0;
                 max_gyroy = 0;
                 max_gyroz = 0;
                 max_magx = 0;
                 max_magy = 0;
                 max_magz = 0;
                 min_accx = 1000;
                 min_accy = 1000;
                 min_accz = 1000;
                 min_gyrox = 1000;
                 min_gyroy = 1000;
                 min_gyroz = 1000;
                 min_magx = 1000;
                 min_magy = 1000;
                 min_magz = 1000;
            }
            classified = true;

        }


       stream << "accx_avg" << "," << "accy_avg" << "," << "accz_avg" << "," << "gyrox_avg" << "," << "gyroy_avg" << "," << "gyroz_avg" << "," << "magx_avg" << "," << "magy_avg" << "," << "magz_avg" << "," << "accx_std" << "," << "accy_std" << "," << "accz_std" << "," << "gyrox_std" << "," << "gyroy_std" << "," << "gyroz_std" << "," << "magx_std" << "," << "magy_std" << "," << "magz_std" << "," << "accx_max" << "," << "accy_max" << "," << "accz_max" << "," << "gyrox_max" << "," << "gyroy_max" << "," << "gyroz_max" << "," << "magx_max" << "," << "magy_max" << "," << "magz_max" << "," << "accx_min" << "," << "accy_min" << "," << "accz_min" << "," << "gyrox_min" << "," << "gyroy_min" << "," << "gyroz_min" << "," << "magx_min" << "," << "magy_min" << "," << "magz_min" << "," << "classification" << endl;
       for (int i=0;i<accx_avg.size();i++)
        {  
           stream << accx_avg.at(i) <<"," << accy_avg.at(i) <<","  << accz_avg.at(i) <<"," << gyrox_avg.at(i) <<"," << gyroy_avg.at(i) <<"," << gyroz_avg.at(i) <<"," << magx_avg.at(i) <<"," << magy_avg.at(i) <<"," << magz_avg.at(i) << "," << accx_std.at(i) <<"," << accy_std.at(i) <<","  << accz_std.at(i) <<"," << gyrox_std.at(i) <<"," << gyroy_std.at(i) <<"," << gyroz_std.at(i) <<"," << magx_std.at(i) <<"," << magy_std.at(i) <<"," << magz_std.at(i) << "," << accx_max.at(i) <<"," << accy_max.at(i) <<","  << accz_max.at(i) <<"," << gyrox_max.at(i) <<"," << gyroy_max.at(i) <<"," << gyroz_max.at(i) <<"," << magx_max.at(i) <<"," << magy_max.at(i) <<"," << magz_max.at(i) << "," << accx_min.at(i) <<"," << accy_min.at(i) <<","  << accz_min.at(i) <<"," << gyrox_min.at(i) <<"," << gyroy_min.at(i) <<"," << gyroz_min.at(i) <<"," << magx_min.at(i) <<"," << magy_min.at(i) <<"," << magz_min.at(i) << ","<< classification2.at(i) << endl;

        }
       for (int i=0;i<accx_avg2.size();i++)
        {

           stream << accx_avg2.at(i) <<"," << accy_avg2.at(i) <<","  << accz_avg2.at(i) <<"," << gyrox_avg2.at(i) <<"," << gyroy_avg2.at(i) <<"," << gyroz_avg2.at(i) <<"," << magx_avg2.at(i) <<"," << magy_avg2.at(i) <<"," << magz_avg2.at(i)<< "," << accx_std2.at(i) <<"," << accy_std2.at(i) <<","  << accz_std2.at(i) <<"," << gyrox_std2.at(i) <<"," << gyroy_std2.at(i) <<"," << gyroz_std2.at(i) <<"," << magx_std2.at(i) <<"," << magy_std2.at(i) <<"," << magz_std2.at(i) << "," << accx_max2.at(i) <<"," << accy_max2.at(i) <<","  << accz_max2.at(i) <<"," << gyrox_max2.at(i) <<"," << gyroy_max2.at(i) <<"," << gyroz_max2.at(i) <<"," << magx_max2.at(i) <<"," << magy_max2.at(i) <<"," << magz_max2.at(i)<< "," << accx_min2.at(i) <<"," << accy_min2.at(i) <<","  << accz_min2.at(i) <<"," << gyrox_min2.at(i) <<"," << gyroy_min2.at(i) <<"," << gyroz_min2.at(i) <<"," << magx_min2.at(i) <<"," << magy_min2.at(i) <<"," << magz_min2.at(i) << "," << classification3.at(i) << endl;

        }


       file.close();

}

MainWindow::~MainWindow()
{


    delete ui;
}

