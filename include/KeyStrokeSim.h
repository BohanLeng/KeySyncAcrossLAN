#ifndef KEYSTROKESIM_H
#define KEYSTROKESIM_H

#pragma once

#include <ApplicationServices/ApplicationServices.h>

class KeyStrokeSim
{
public:
    KeyStrokeSim();
    ~KeyStrokeSim();

    void Press(int key);
    void Release(int key);
    void Click(int key);

private:
    int key_to_stroke;
};

#endif