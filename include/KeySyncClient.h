#ifndef KEYSYNCCLIENT_H
#define KEYSYNCCLIENT_H

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

class KeySyncClient
{
public:
    KeySyncClient(char* ip, char* port);
    ~KeySyncClient();

private:
    int m_socket;
    struct sockaddr_in serv_addr;
};

#endif