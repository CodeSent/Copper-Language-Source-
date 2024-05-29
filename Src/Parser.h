#pragma once
#include <vector>
#include "Tokens.h"
#include "Error.h"

using  GenaratedTokens = std::vector<Token>;




struct Node {
    Node* Left ;
    Node* Right;
    Token CurrentToken;
};



class Parser {
    Token CurrentToken;
    int CurrentToken = 0;
    void Step();
    void expr();
    void term();
    void factor();
public:
    void SetParseTarget(GenaratedTokens &Tokens);
    void EvalTarget();

};