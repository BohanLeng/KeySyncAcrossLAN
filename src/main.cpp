#include <iostream>
#include "KeySyncServer.h"
#include "KeySyncClient.h"
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "argument required!\n";
        exit(1);
    }

    if (strcmp(argv[1], "-s") == 0)
    {
        if (argc != 3)
        {
            std::cout << "Server usage : " << argv[0] << "< port >\n ";
            exit(1);
        }
        KeySyncServer server = KeySyncServer(argv[2]);
    }
    else if (strcmp(argv[1], "-c") == 0)
    {
        if (argc != 4)
        {
            std::cout << "Client usage : " << argv[0] << "< IP > < port >\n ";
            exit(1);
        }
        KeySyncClient client = KeySyncClient(argv[2], argv[3]);
    }
    else 
    {
        std::cout << "Usage: " << "[c for clinet, s for server]\n";
        exit(1);
    }

    char *cmd;

    sprintf(cmd, "osascript -e 'tell app \"Finder\" to open startup disk");
    system(cmd);

    return(0);

}