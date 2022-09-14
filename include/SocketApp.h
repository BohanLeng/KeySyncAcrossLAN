#ifndef SOCKETAPP_H
#define SOCKETAPP_H

#pragma once

class SocketApp
{
public:
    SocketApp(char* port, char *ip, int keyCode);
    ~SocketApp();

    virtual void TriggerAction() = 0;

private:

};

#endif