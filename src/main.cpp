#include <iostream>
#include <KeySyncServer.h>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }
    KeySyncServer server = KeySyncServer(atoi(argv[1]));

    char* cmd;

    sprintf(cmd, "osascript -e 'tell app \"Finder\" to open startup disk");
    system(cmd);

    return(0);

}