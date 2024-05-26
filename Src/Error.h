#pragma once

class Error {
    bool Stop = false;
    void setErrorSwitch(bool set);
    void getArrowString(int Legth, int at);
public:
    bool getErrorState();
    void printError(const char* Error,int at, const char* SourceLine, int Size);
    
    
};