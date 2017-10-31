#include "videothread.h"
#include <opencv2/opencv.hpp>
#include "opencv2/videoio.hpp"

videothread::videothread(QObject *parent) :
    QThread(parent)
{

}
//INICJALIZACJA WIDEO AVI
void videothread::videoInit()
{
    //capture.open(fname.toStdString());

    capture.open(1);
    if(capture.isOpened() == false)
    {
        qDebug()<<"No camera2";
        return;
    }

    this->start();
}

//Star naszego watku
void videothread::run()
{
    while(1)
    {
        //QMutex mutex;
        //mutex.lock();

        //mutex.unlock();
        capture.read(input_img);

        if(input_img.empty() == true) return;

        //TU WPISUJEMY WSZYSTKO CO DZIEJE SIE Z NASZYM OBRAZEM Z KAMERY


        //...

        //Konwersja do QImage
        QImage qimginput = qinputimage(input_img);

        //Emisja sygnału do watku głównego
        emit NewCamImg(qimginput);

    }
}

QImage videothread::qinputimage(const cv::Mat &mat)
{
    // 8-bits unsigned, NO. OF CHANNELS=1
    if(mat.type()==CV_8UC1)
    {
        // Set the color table (used to translate colour indexes to qRgb values)
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }
    // 8-bits unsigned, NO. OF CHANNELS=3
    if(mat.type()==CV_8UC3)
    {
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}

