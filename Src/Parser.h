#pragma once
#include "Tokens.h"
#include "Error.h"

#define BinFuncPtr(A) Node* *(Parser::A)()

enum NodeType {
    UNKNOWN,
    NUMBER,
    BIN_OP,
};

struct Node {
    NodeType Type;
    Token* NodeToken = nullptr;
    Node* Left = nullptr;
    Node* Right = nullptr;
};


using GenaratedNodes = std::vector<Node>;

class Parser {
public:
    void SetTarget(GenaratedTokens &TokenArray);
    void Parse();
    void PrintNodes(Node* N);
private:
    void Advance();

    Node* CreateNode(NodeType Type, Token *Tok);
    Node* CreateNode();

    //Node* BinOp(Node* (Parser::*Func)(), T_Type T1,T_Type T2);

    Node* factor();
    Node* term();
    Node* expr();


    GenaratedNodes NodesMade;
    GenaratedTokens Tokens;
    Token* currentTokenObj;
    int totalTokens = 0;
    int currentToken = -1;
    int NodeIndex = 0;
};