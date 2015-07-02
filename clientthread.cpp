#include "clientthread.h"
#include <QString>
#include <QStringList>
ClientThread::ClientThread(int clientSocket):clientSocket_(clientSocket)
{

}
void ClientThread::run() {

    receiveData();
}

void ClientThread::verifyClient(){
    char control[256];
    char granttMessage[256] = "GRANTT";
    char denieMessage[256] = "DENIE";
    sock_err = recv(this->clientSocket_,control,256,0);
    //If the socket is okay

    if(sock_err != SOCKET_ERROR){
        control[sock_err] = '\0';
        //If client is known
        if(QString::fromUtf8(control) == "SDJA"){
            sendData(granttMessage);
            receiveData();
        }else{
            std::cout << "CLIENT DENIED " << std::endl;
            sendData(denieMessage);
            //Close client socket
            shutdown(this->clientSocket_, 2);
        }
    }

}

void ClientThread::receiveData(){
    QByteArray array;

    char buffer[256];
    sock_err = recv(this->clientSocket_,buffer,256,0);
    std::cout<< " nouveau message"<<std::endl;

    array.append(buffer,sock_err);
    if(sock_err != SOCKET_ERROR){
        //Receive code
        buffer[sock_err] = '\0';
        std::cout << "MOTHER FUCKIN BUFFER : "<<buffer<< std::endl;
        QString bufferToString = QString::fromUtf8(buffer);
        QStringList list = bufferToString.split("|");
        if(list[0] == "CODE"){
            char code[256] = "BIEN RECUT GROS";
            std::cout << "Chaine Reçue : "<<list[1].toStdString() << std::endl;
            QString dataReceived = list[1];
            sendData(code);
            emit accessCodeReceived(dataReceived);
            buffer[0]='\0';
        }
        else if(list[0] == "SIZE"){
            char test[256] = "YOYOYO";
            std::cout << "SIZE RECUE : "<<list[1].toStdString() << std::endl;
            sendData(test);
            buffer[0]='\0';
        }
        else if(list[0] == "PHOTO"){
            std::cout << "PHOTO RECUE : "<<list[1].toStdString() << std::endl;
            buffer[0]='\0';
        }


    }
    else{
        std::cout << "Erreur de transmission\n" << std::endl;
    }
}



void ClientThread::sendData(char buffer[256]){

    sock_err = send(this->clientSocket_, buffer, 256, 0);
    if(sock_err != SOCKET_ERROR){
        buffer[sock_err] = '\0';
        std::cout << "Chaine Envoyée : "<<buffer << std::endl;
    }
    else{
        std::cout << "Erreur de transmission\n" << std::endl;
    }
    buffer[0]='\0';
}

void ClientThread::sendDataToClient(){
    std::cout << "GRANT ACCESS YAH\n" << std::endl;

    //sendData();

}

void ClientThread::sendDinieAccessToClient(){
    std::cout << "DENI ACCESS YAH\n" << std::endl;

    //sendData();

}
