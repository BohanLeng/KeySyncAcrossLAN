#include "KeySyncServer.h"
#include <iostream>
#include "ErrorHandler.h"

using namespace std;

KeySyncServer::KeySyncServer(char* port)
{
    // Create socket
    serv_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serv_sock == -1)
        error_handling("socket() error");
    

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_port = atoi(port);
    serv_addr.sin_port = htons(server_port);

    // assign ip and port
    if (::bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind() error");

    cout << "server bind port successful!" << '\n';

    //call listen() to become listen-able
    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    cout << "start listening successful!" << '\n';

    socklen_t clnt_addr_size = sizeof(clnt_addr[0]);
    //call accept() to handle connect request. if there is not, it will not return until one appears
    clnt_sock[0] = accept(serv_sock, (struct sockaddr *)&clnt_addr[0], &clnt_addr_size);
    if (clnt_sock[0] == -1)
        error_handling("accept() error");

    char message[] = "received!";
    write(clnt_sock[0], message, sizeof(message));

    char send_buff[10];
    
    while(true)
    {
        cout << "Please input message to be sent:\n";
        cin >> send_buff;
        send(clnt_sock[0], send_buff, 9, 0);
    }
}

KeySyncServer::~KeySyncServer()
{
    close(serv_sock);
    for (int i = 0; i < clnt_count;i++)
        try{
            close(clnt_sock[i]);
        }
        catch(exception e){

        }
            
}
