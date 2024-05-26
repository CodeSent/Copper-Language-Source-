#pragma once

class Error {
    bool Stop = false;
public:
    bool getErrorState();
    void printError(const char* Error,int at, const char* SourceLine);
    
};