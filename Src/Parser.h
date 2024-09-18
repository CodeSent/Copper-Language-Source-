#pragma once
#include "Tokens.h"
#include "Error.h"


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
    void PrintData();
};


using GenaratedNodes = std::vector<Node>;


template <class mClass, typename rType> using ClassMethodPtr = rType (mClass::*)();

class Parser {
public:
    void SetTarget(GenaratedTokens &TokenArray);
    void Parse();
    void PrintNodes(Node* N);
private:
    void Advance();

    Node* CreateNode(NodeType Type, Token *Tok);
    Node* CreateNode();
    bool  isTokenType(Token* node, std::vector<T_Type> TypeTest);
    Node* BinOp(ClassMethodPtr<Parser,Node*> Func , std::vector<T_Type> TypeTest);

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