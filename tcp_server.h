#ifndef TCP_SERVER_H
#define TCP_SERVER_H
#if defined (WIN32)
#include <winsock2.h>
typedef int socklen_t;
#elif defined (linux)
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
#include <QString>
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
#endif
#include <QThread>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "clientthread.h"
class TCP_Server : public QThread
{
    Q_OBJECT
public:
    TCP_Server(int connectionPort,SOCKET sock);
    ~TCP_Server();
    void stopServer();
    void startServer();
    virtual void run();
signals:
    void accessCodeReceived(const QString &data);
    void sendDataToClientSignal();
    void sendDinieAccessToClientSignal();
    void onPhotoReceivedSignal(QString &image);
private slots:
    void accessCodeReceivedSlot(const QString &data);
    void sendDataToClient();
    void sendDinieAccessToClient();
    void onPhotoReceived(QString &image);
private :
    int port_;
    SOCKET sock_;
    SOCKET clientSocket_;
    int sock_err;
};

#endif // TCP_SERVER_H
