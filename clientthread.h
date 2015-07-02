#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H
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
#include "tcp_server.h"

class ClientThread:public QThread
{
    Q_OBJECT
public:
    ClientThread( int clientSocket);
    virtual void run();
signals:
    void accessCodeReceived(const QString &data);
    void onPhotoReceivedSignal(QString &image);
private slots:
    void sendDataToClient(void);
    void sendDinieAccessToClient(void);
private:
    void sendData(char buffer[256]);
    void receiveData();
    int clientSocket_;
    int sock_err;
};

#endif // CLIENTTHREAD_H
