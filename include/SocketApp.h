#ifndef SOCKETAPP_H
#define SOCKETAPP_H

#pragma once

class SocketApp
{
public:
    SocketApp(char* port, char *ip);
    ~SocketApp();

private:
    virtual void TriggerAction() = 0;

};

#endif