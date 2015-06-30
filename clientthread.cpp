#include "clientthread.h"

ClientThread::ClientThread(int clientSocket):clientSocket_(clientSocket)
{

}
void ClientThread::run() {

    verifyClient();
}

void ClientThread::verifyClient(){
    char control[4];
    char granttMessage[256] = "GRANTT";
    char denieMessage[256] = "DENIE";
    sock_err = recv(this->clientSocket_,control,4,0);
    //If the socket is okay
    if(sock_err != SOCKET_ERROR){
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
    char control[2];
    char buffer[256];


    /*sock_err = recv(this->clientSocket_,control,2,0);
    sock_err = recv(this->clientSocket_,(char*)&size,sizeof(long),0);*/


    sock_err = recv(this->clientSocket_,buffer,256,0);


    array.append(buffer,sock_err);
    if(sock_err != SOCKET_ERROR){
        buffer[sock_err] = '\0';
        std::cout << "Chaine Reçue : "<<buffer << std::endl;
        QString dataReceived = QString::fromUtf8(buffer);
        emit accessCodeReceived(dataReceived);
    }
    else{
        std::cout << "Erreur de transmission\n" << std::endl;
    }
}



void ClientThread::sendData(char buffer[256]){
    //char buffer[256] = "ALORS JUNITO";


    sock_err = send(this->clientSocket_, buffer, 256, 0);
    if(sock_err != SOCKET_ERROR){
        buffer[sock_err] = '\0';
        std::cout << "Chaine Envoyée : "<<buffer << std::endl;
    }
    else{
        std::cout << "Erreur de transmission\n" << std::endl;
    }
}

void ClientThread::sendDataToClient(){
    std::cout << "GRANT ACCESS YAH\n" << std::endl;

    //sendData();

}

void ClientThread::sendDinieAccessToClient(){
    std::cout << "DENI ACCESS YAH\n" << std::endl;

    //sendData();

}
