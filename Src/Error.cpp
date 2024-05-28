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



