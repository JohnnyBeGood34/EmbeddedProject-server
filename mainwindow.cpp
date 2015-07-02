#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filemanager.h"
#include <QStringListModel>
#include <iostream>
#include <memory>
#include "pthread.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    SOCKET sock;
    ui->setupUi(this);
    server = new TCP_Server(1234,sock);

    populateListOfCodes();
    connect(this->server,SIGNAL(accessCodeReceived(QString)),this->ui->codeReceived, SLOT(setText(QString)));
    connect(this->server,SIGNAL(onPhotoReceivedSignal(QString&)),this,SLOT(onPhotoReceived(QString&)),Qt::DirectConnection);
    connect(this,SIGNAL(sendGranttAccessToClient(void)),this->server,SLOT(sendDataToClient(void)));
    connect(this,SIGNAL(sendDinieAccessToClient(void)),this->server,SLOT(sendDinieAccessToClient(void)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete server;
    delete stringListModel_;
}

void MainWindow::populateListOfCodes(){
    // Create model

    QString path = "/home/guest/EmbeddedProject-server/codes.txt";
    FileManager fileManager(path);
    QPair<bool,AccessCodesList> qPair;
    qPair = fileManager.getAccessCodes();
    if(qPair.first){
        AccessCodesList accessCodesList = qPair.second;
        stringListModel_ = new QStringListModel(accessCodesList);
        // Glue model and view together
        ui->listView->setModel(stringListModel_);

    }else{

    }


}

void MainWindow::onPhotoReceived(QString &image){
    setPhoto(image);
}

void MainWindow::setPhoto(QString &image){

    QGraphicsScene* scene = new QGraphicsScene();
    QPixmap pixmap("/home/guest/Desktop/test.jpg");
    scene->addPixmap(pixmap.scaled(ui->graphicsView->width(),ui->graphicsView->height(),Qt::IgnoreAspectRatio, Qt::FastTransformation));

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHints(QPainter::Antialiasing);

    //scene->setSceneRect(0,0, fondPhoto.width(), fondPhoto.height());
    //scene->addPixmap(item.scaled(ui->graphicsView->width(),ui->graphicsView->height(),Qt::IgnoreAspectRatio, Qt::FastTransformation));

}

void MainWindow::on_startServerButton_clicked()
{
    server->start();
}

void MainWindow::on_grantAccessButton_clicked()
{
    emit sendGranttAccessToClient();
}

void MainWindow::on_denieAccess_clicked()
{
    emit sendDinieAccessToClient();
}
