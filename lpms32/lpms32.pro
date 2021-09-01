QT       += core gui
QT += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chartdialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    chartdialog.h \
    mainwindow.h

FORMS += \
    chartdialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lLpSensor
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lLpSensord
else:unix: LIBS += -L$$PWD/lib/ -lLpSensor

LIBS += C:\opencv\build\x86\vc12\lib\opencv_core2410.lib\
        C:\opencv\build\x86\vc12\lib\opencv_core2410d.lib\
        C:\opencv\build\x86\vc12\lib\opencv_highgui2410.lib\
        C:\opencv\build\x86\vc12\lib\opencv_highgui2410d.lib\
        C:\opencv\build\x86\vc12\lib\opencv_imgproc2410.lib\
        C:\opencv\build\x86\vc12\lib\opencv_imgproc2410d.lib\


INCLUDEPATH += $$PWD/include

INCLUDEPATH += C:\opencv\build\include
               C:\opencv\build\include\opencv
               C:\opencv\build\include\opencv2

DEPENDPATH += $$PWD/include

DISTFILES +=


