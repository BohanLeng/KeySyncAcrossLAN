#ifndef KEYBOARDLISTENER_H
#define KEYBOARDLISTENER_H

#pragma once

#include <ApplicationServices/ApplicationServices.h>
#include <iostream>
#include "SocketApp.h"
using namespace std;


CGEventRef myCGEventCallback(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon);

class KeyboardListener
{
public:
    KeyboardListener(SocketApp *socketAppRef, CGKeyCode *keys_to_listen);
    ~KeyboardListener();

    void StartKeyDetection();
    void StopKeyDetection();

    CGKeyCode* GetListeningKeys();
    void KeyStrokeDetected(CGKeyCode keycode);

private:
    SocketApp* m_app;
    CGKeyCode* keys_listening;

    CFMachPortRef      eventTap;
    CGEventMask        eventMask;
    CFRunLoopSourceRef runLoopSource;
    CFRunLoopRef       runLoopRef;

};


#endif