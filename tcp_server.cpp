#include "tcp_server.h"
#include "pthread.h"
#include "clientthread.h"
TCP_Server::TCP_Server(int connectionPort,SOCKET sock):port_(connectionPort),sock_(sock)
{
    startServer();
}

TCP_Server::~TCP_Server()
{

}

void TCP_Server::run(){

    while(true) {
        SOCKADDR_IN csin;
        socklen_t recsize = sizeof(csin);

        std::cout << "Patientez pendant que le client se connecte sur le port "+this->port_ << std::endl;
        this->clientSocket_ = accept(this->sock_, (SOCKADDR*)&csin, &recsize);
        std::cout << "Un client se connecte avec la socket "<<this->clientSocket_ <<" "<< inet_ntoa(csin.sin_addr) <<" " << htons(csin.sin_port) << std::endl;

        ClientThread *t = new ClientThread(this->clientSocket_);
        connect(t,SIGNAL(accessCodeReceived(QString)),this, SLOT(accessCodeReceivedSlot(QString)));
        connect(this,SIGNAL(sendDataToClientSignal(void)),t,SLOT(sendDataToClient(void)),Qt::DirectConnection);
        connect(this,SIGNAL(sendDinieAccessToClientSignal(void)),t,SLOT(sendDinieAccessToClient(void)),Qt::DirectConnection);
        connect(t,SIGNAL(onPhotoReceivedSignal(QString&)),this,SLOT(onPhotoReceived(QString&)),Qt::DirectConnection);
        t->start();
    }

}


void TCP_Server::onPhotoReceived(QString &image){
    emit onPhotoReceivedSignal(image);
}

void TCP_Server::startServer(){
    SOCKADDR_IN sin;

    this->sock_ = socket(AF_INET, SOCK_STREAM, 0);
    /* Si la socket est valide */
    if(this->sock_ != INVALID_SOCKET)
    {
        std::cout << "La socket %d est maintenant ouverte en mode TCP/IP" + this->sock_ << std::endl;
        //printf("La socket %d est maintenant ouverte en mode TCP/IP\n", sock);

        /* Configuration */
        sin.sin_addr.s_addr    = htonl(INADDR_ANY);   /* Adresse IP automatique */
        sin.sin_family         = AF_INET;             /* Protocole familial (IP) */
        sin.sin_port           = htons(this->port_);         /* Listage du port */
        sock_err = bind(this->sock_, (SOCKADDR*)&sin, sizeof(sin));


        std::cout << "SOCKET ERROR : " << sock_err << std::endl;
        /* Si la socket fonctionne */
        if(sock_err != SOCKET_ERROR)
        {
            /* Démarrage du listage (mode server) */
            sock_err = listen(this->sock_, 5);

            std::cout << "Listage du port "+this->port_ << std::endl;
        }
    }
}

void TCP_Server::stopServer(){
    //Fermeture socket client
    shutdown(this->clientSocket_, 2);
    /* Fermeture de la socket server*/
    printf("Fermeture de la socket...\n");
    closesocket(sock_);
    printf("Fermeture du serveur terminee\n");
}

void TCP_Server::accessCodeReceivedSlot(const QString &data){
    emit accessCodeReceived(data);
}

void TCP_Server::sendDataToClient(){
    std::cout << "SEND ACCESS CLIENT" << std::endl;
    emit sendDataToClientSignal();
}

void TCP_Server::sendDinieAccessToClient(){
    std::cout << "SEND DENIE CLIENT" << std::endl;
    emit sendDinieAccessToClientSignal();
}
