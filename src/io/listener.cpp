//
// Created by nooni on 2024-02-08.
//

#include <nukamsgd/listener.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>


Listener::Listener() {

}

Listener::~Listener() {

}

int Listener::run() {
    int serv_sock = 0;
    int client_sock = 0;
    char message[256];
    int strlen = 0;

    struct sockaddr_in serv_addr;
    struct sockaddr_in client_addr;


    serv_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (serv_sock < 0) {
        printf("socket error");
        return -1;
    }

    printf("socket created successfully. (fd: %d)\n", serv_sock);

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(34568);

    if (bind(serv_sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("bind error");
        return -1;
    }

    if(listen(serv_sock, 10) < 0) {
        printf("listen error");
        return -1;
    }

    socklen_t client_addr_size = sizeof(client_addr);

    client_sock = accept(serv_sock, (struct sockaddr *) &client_addr, &client_addr_size);
    if(client_sock < 0) {
        printf("accept error");
        return -1;
    }

    while( (strlen = read(client_sock, message, 256) != 0)) {
        write(client_sock, message, strlen);
    }

    close(client_sock);

    return 0;
}