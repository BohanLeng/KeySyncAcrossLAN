#include "KeySyncClient.h"
#include "ErrorHandler.h"

KeySyncClient::KeySyncClient(char* ip, char* port)
{

    char message[30];
    int msg_len;

    m_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (m_socket == -1)
        error_handling("socket() error");
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(atoi(port));

    if (connect(m_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error!");

    msg_len = read(m_socket, message, sizeof(message) - 1);
    if (msg_len == -1)
        error_handling("read() error!");
    printf("Message from server : %s \n", message);
    close(m_socket);

}

KeySyncClient::~KeySyncClient()
{
    close(m_socket);
}