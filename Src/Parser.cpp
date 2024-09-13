#include <iostream>
#include "Parser.h"

void Parser::SetTarget(GenaratedTokens &TokenArray)
{
    Tokens = TokenArray;
    currentToken = -1;
    totalTokens = Tokens.size();
    Advance();
}

void Parser::Advance()
{
    currentToken++;
    if ((currentToken+1) < totalTokens) {
        currentTokenObj = &(Tokens[currentToken]);
    }
}

Node* Parser::CreateNode(NodeType Type, Token *Tok)
{
    Node N;
    N.Type = Type;
    N.NodeToken = (Tok);
    NodesMade.push_back(N);
    NodeIndex++;
    std::cout << "Token Made " << Type << "\n";
    return &NodesMade[NodeIndex-1];
}

Node* Parser::CreateNode()
{
    Node N;
    NodesMade.push_back(N);
    NodeIndex++;
    std::cout << "Token Made " << 0 << "\n";
    return &NodesMade[NodeIndex-1];
}
/*
Node *Parser::BinOp(Node* (Parser::*Func)(), T_Type T1,T_Type T2)
{
    Node * Left = (this->*Func)();
    while (currentTokenObj->TokenType == T1 or currentTokenObj->TokenType == T2)
    {
        Node* BinNode = CreateNode(BIN_OP,currentTokenObj);
        Advance();
        Node* Right = (this->*Func)();
        BinNode->Left = Left;
        BinNode->Right = Right;
    }
    return Left;
}
*/
Node* Parser::factor()
{
    Token Tok = *(currentTokenObj);
    bool Check  = (Tok.TokenType == INT or Tok.TokenType == FLOAT);
    Node* CNode = CreateNode();
    if (Check) {
        CNode->Type = NUMBER;
        CNode->NodeToken = &(Tok);
        Advance();
    }
    return CNode;
}

Node *Parser::term()
{
    Node * Left = factor();

    while (currentTokenObj->TokenType == MUL or currentTokenObj->TokenType == DIV)
    {
        std::cout << "Inside Term \n";
        Node* BinNode = CreateNode(BIN_OP,currentTokenObj);
        Advance();
        Node* Right = factor();
        BinNode->Left = Left;
        BinNode->Right = Right;
        

    }
    return Left;
}

Node *Parser::expr()
{
    Node * Left = term();

    while (currentTokenObj->TokenType == PLUS or currentTokenObj->TokenType == MINUS)
    {
        std::cout << "Inside Expr \n";
        Node* BinNode = CreateNode(BIN_OP,currentTokenObj);
        Advance();
        Node* Right = term();
        BinNode->Left = Left;
        BinNode->Right = Right;
    }
    return Left;
}

void Parser::Parse()
{
    expr();
    for (auto I : NodesMade)
    {
        std::cout << "{ " << I.Type << ":" << I.Left << "," <<  I.Right << "," << &I << "}" << "\n";
    }
    
}

