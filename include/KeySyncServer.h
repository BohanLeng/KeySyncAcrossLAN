#ifndef KEYSYNCSERVER_H
#define KEYSYNCSERVER_H

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

class KeySyncServer
{
    
private:
    int server_port;

    int serv_sock;
    int clnt_sock;

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;


public:
    KeySyncServer(char* port);
    ~KeySyncServer();

private:
};


#endif