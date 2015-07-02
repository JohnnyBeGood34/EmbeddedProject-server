#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "tcp_server.h"
#include <QMainWindow>
#include <QStringListModel>
#include <QImage>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void populateListOfCodes();
    void setPhoto(QImage &image);
signals:
    void accessCodeReceived(QString &data);
    void sendGranttAccessToClient();
    void sendDinieAccessToClient();
private slots:

    void on_startServerButton_clicked();

    void on_grantAccessButton_clicked();

    void on_denieAccess_clicked();
    void onPhotoReceived(QImage &image);
private:
    Ui::MainWindow *ui;
    TCP_Server *server;
    QStringListModel *stringListModel_;
};

#endif // MAINWINDOW_H
