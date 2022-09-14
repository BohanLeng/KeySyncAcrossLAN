#include "KeySyncServer.h"
#include <iostream>
#include "ErrorHandler.h"

using namespace std;

KeySyncServer::KeySyncServer(char* port, char *ip= nullptr, int keyCode=-1) : SocketApp(port, ip, keyCode)
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

    cout << "start waiting for client connection successful!" << '\n';

    socklen_t clnt_addr_size = sizeof(clnt_addr[0]);
    //call accept() to handle connect request. if there is not, it will not return until one appears
    clnt_sock[0] = accept(serv_sock, (struct sockaddr *)&clnt_addr[0], &clnt_addr_size);
    if (clnt_sock[0] == -1)
        error_handling("accept() error");

    cout << "Connection to client established." << '\n';

    char message[] = "Server responded to connection request!";
    write(clnt_sock[0], message, sizeof(message));

    // Create KeyboardListener
    m_listener = new KeyboardListener(this, keyCode);
    cout << "Keyboard Listener initialised. Waiting to Keyboard input.\n";
    m_listener->StartKeyDetection();
}

KeySyncServer::~KeySyncServer()
{
    if(m_listener != nullptr)
        delete(m_listener);

    close(serv_sock);
    for (int i = 0; i < clnt_count;i++)
        try{
            close(clnt_sock[i]);
        }
        catch(exception e){

        }
            
}

void KeySyncServer::TriggerAction()
{
    cout << "Key wanted pressed.\n";
    char send_buff[] = "`KeyPressed";
    send(clnt_sock[0], send_buff, 15, 0);
}