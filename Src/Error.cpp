#include <iostream>
#include "Error.h"

bool Error::getErrorState()
{
    return !Stop;
}

void Error::setErrorSwitch(bool set)
{
    Stop = set;
}

void Error::getArrowString(int Length, int at)
{
    std::string Str = "";
    for (size_t i = 0; i <(Length-1); i++)
    {
        if (i == at) {
            Str += '^';
        } else {
            Str += '~';
        }
    }
    std::cout << Str << "\n";
     

}

void Error::printError(const char *Error, int at, const char *SourceLine, int Size)
{
    setErrorSwitch(true);
    std::cout << "\n:: Error at column: " << at << ". \n \n";
    std::cout << ">  " << SourceLine << "\n ";
    std::cout << "  ";
    getArrowString(Size,at);
    std::cout << "~  " << Error << "\n";
}
