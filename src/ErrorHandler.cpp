#include "ErrorHandler.h"

ErrorHandler::ErrorHandler()
{

}

ErrorHandler::~ErrorHandler()
{

}

void error_handling(std::string message)
{
    std::cout << message << '\n';
    exit(1);
}