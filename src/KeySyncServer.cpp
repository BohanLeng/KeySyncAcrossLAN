#include "KeySyncServer.h"
#include <iostream>
#include "ErrorHandler.h"

KeySyncServer::KeySyncServer(int port)
{
    // Create socket
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1)
        error_handling("socket() error");
    

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_port = port;
    serv_addr.sin_port = htons(server_port);

    // assign ip and port
    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind() error");

    std::cout << "server bind port successful!" << '\n';
}

KeySyncServer::~KeySyncServer()
{

}
