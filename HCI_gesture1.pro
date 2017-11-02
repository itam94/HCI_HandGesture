#-------------------------------------------------
#
# Project created by QtCreator 2016-10-06T21:05:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HCI_gesture1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    videothread.cpp

HEADERS  += mainwindow.h \
    videothread.h

FORMS    += mainwindow.ui

unix {
    INCLUDEPATH += /usr/local/include/opencv
    LIBS += -L/usr/local/lib \
    -lopencv_core\
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_features2d \
    -lopencv_calib3d \
 -lopencv_videoio
}

win32{
    INCLUDEPATH += D:\opencv\build\include\opencv \
                    D:\opencv\build\include\opencv2
    LIBS += "D:\opencv\bin\bin\libopencv_videoio331.dll" \
        "D:\opencv\bin\bin\libopencv_core331.dll" \
        "D:\opencv\bin\bin\libopencv_highgui331.dll" \
        "D:\opencv\bin\bin\libopencv_calib3d331.dll" \
        "D:\opencv\bin\bin\libopencv_imgproc331.dll"
}

