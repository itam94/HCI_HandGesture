#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    camImg = new videothread(this);

    //połączenie sygnał slot
    connect(camImg, SIGNAL(NewCamImg(QImage)), this, SLOT(onNewCamImg(QImage)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewCamImg(QImage qimg)
{
    ui->img->setPixmap(QPixmap::fromImage(qimg).scaled(ui->img->width(),ui->img->height()));
}

void MainWindow::on_pushButton_clicked()
{
    camImg->videoInit();
}
