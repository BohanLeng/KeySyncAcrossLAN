#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

class ErrorHandler
{
public:
    ErrorHandler();
    ~ErrorHandler();

private:

};

void error_handling(std::string message);

#endif