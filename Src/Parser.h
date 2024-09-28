#pragma once
#include "Tokens.h"
#include "Error.h"
#include <map>


enum NodeType {
    UNKNOWN,
    NUMBER,
    BIN_OP,
};

struct Node {
    NodeType Type;
    Token* NodeToken = 0;
    Node* Left = 0;
    Node* Right = 0;
    int Nodeindex = 0;
    void PrintData();
    ~Node();
};


using GenaratedNodes = std::map<int,Node>;


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