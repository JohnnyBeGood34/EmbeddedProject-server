#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "tcp_server.h"
#include <QMainWindow>
#include <QStringListModel>
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
signals:
    void accessCodeReceived(QString &data);
    void sendGranttAccessToClient();
    void sendDinieAccessToClient();
private slots:

    void on_startServerButton_clicked();

    void on_grantAccessButton_clicked();

    void on_denieAccess_clicked();

    void on_stopServerButton_clicked();
private:
    Ui::MainWindow *ui;
    TCP_Server *server;
    QStringListModel *stringListModel_;
};

#endif // MAINWINDOW_H
