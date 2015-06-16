#include "mainwindow.h"
#include <QApplication>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PORT 1234

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
int main(void)
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();*/
    std::cout << "YOYOYOYOYOYOYO" << std::endl;
    SOCKET sock;
    SOCKADDR_IN sin;
    SOCKET csock;
    SOCKADDR_IN csin;
    char buffer[32] = "Bonjour !";
    char lineReceived[256];

    socklen_t recsize = sizeof(csin);
    int sock_err;
    sock = socket(AF_INET, SOCK_STREAM, 0);

    /* Si la socket est valide */
    if(sock != INVALID_SOCKET)
    {
        std::cout << "La socket %d est maintenant ouverte en mode TCP/IP" + sock << std::endl;
        //printf("La socket %d est maintenant ouverte en mode TCP/IP\n", sock);

        /* Configuration */
        sin.sin_addr.s_addr    = htonl(INADDR_ANY);   /* Adresse IP automatique */
        sin.sin_family         = AF_INET;             /* Protocole familial (IP) */
        sin.sin_port           = htons(PORT);         /* Listage du port */
        sock_err = bind(sock, (SOCKADDR*)&sin, sizeof(sin));
        std::cout << "SOCKET ERROR : " << sock_err << std::endl;
        /* Si la socket fonctionne */
        if(sock_err != SOCKET_ERROR)
        {
            /* Démarrage du listage (mode server) */
            sock_err = listen(sock, 5);
            //printf("Listage du port %d...\n", PORT);
            std::cout << "Listage du port "+PORT << std::endl;
            /* Si la socket fonctionne */
            if(sock_err != SOCKET_ERROR)
            {
                /* Attente pendant laquelle le client se connecte */
                //printf("Patientez pendant que le client se connecte sur le port %d...\n", PORT);
                std::cout << "Patientez pendant que le client se connecte sur le port "+PORT << std::endl;
                csock = accept(sock, (SOCKADDR*)&csin, &recsize);
                //printf("Un client se connecte avec la socket %d de %s:%d\n", csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port));
                std::cout << "Un client se connecte avec la socket "<<csock <<" "<< inet_ntoa(csin.sin_addr) <<" " << htons(csin.sin_port) << std::endl;
                sock_err = send(csock, buffer, 32, 0);

                if(sock_err != SOCKET_ERROR)
                    std::cout << "Chaine envoyée : "<<buffer << std::endl;
                    //printf("Chaine envoyée : %s\n", buffer);
                else
                    std::cout << "Erreur de transmission\n" << std::endl;
                    //printf("Erreur de transmission\n");

                /* Il ne faut pas oublier de fermer la connexion (fermée dans les deux sens) */
                shutdown(csock, 2);
            }
        }

        /* Fermeture de la socket */
        printf("Fermeture de la socket...\n");
        closesocket(sock);
        printf("Fermeture du serveur terminee\n");
    }
    /* On attend que l'utilisateur tape sur une touche, puis on ferme */
    getchar();

    return EXIT_SUCCESS;

}

