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

    //call listen() to become listen-able
    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    std::cout << "start listening successful!" << '\n';

    clnt_addr_size = sizeof(clnt_addr);
    //call accept() to handle connect request. if there is not, it will not return until one appears
    clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
    if (clnt_sock == -1)
        error_handling("accept() error");

    char message[] = "received!";
    write(clnt_sock, message, sizeof(message));
    close(clnt_sock);
    close(serv_sock);
    return;
}

KeySyncServer::~KeySyncServer()
{

}
