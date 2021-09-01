/********************************************************************************
** Form generated from reading UI file 'chartdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTDIALOG_H
#define UI_CHARTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_chartDialog
{
public:

    void setupUi(QDialog *chartDialog)
    {
        if (chartDialog->objectName().isEmpty())
            chartDialog->setObjectName(QString::fromUtf8("chartDialog"));
        chartDialog->resize(400, 300);

        retranslateUi(chartDialog);

        QMetaObject::connectSlotsByName(chartDialog);
    } // setupUi

    void retranslateUi(QDialog *chartDialog)
    {
        chartDialog->setWindowTitle(QCoreApplication::translate("chartDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chartDialog: public Ui_chartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTDIALOG_H
