#ifndef KEYSYNCSERVER_H
#define KEYSYNCSERVER_H

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "SocketApp.h"
#include "KeyboardListener.h"

class KeySyncServer : public SocketApp
{
    
private:
    int server_port;
    int serv_sock;
    int clnt_sock[5];
    int clnt_count = 5;

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr[5];


public:
    KeySyncServer(char* port, char* ip);
    ~KeySyncServer();

private:
    void TriggerAction() override;
};


#endif