#ifndef VIDEOTHREAD_H
#define VIDEOTHREAD_H

#include <QThread>
#include <QtCore>
#include <QImage>
#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QMutex>
#include <QMutexLocker>
#include <algorithm>

//opencv
#include <cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/videoio.hpp"


class videothread : public QThread
{
    Q_OBJECT
public:
    explicit videothread(QObject *parent = 0);

    void run();
    void stop();
    void videoInit();

    cv::VideoCapture capture;
    cv::Mat input_img;

    //konversja cv::Mat na QImage
    QImage qinputimage(const cv::Mat &mat);
signals:
    void NewCamImg(QImage);
};

#endif // VIDEOTHREAD_H
