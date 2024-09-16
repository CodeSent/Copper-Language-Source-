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
    if (currentToken < totalTokens) {
        Token &Tok = Tokens[currentToken];
        Tok.PrintToken();
        currentTokenObj = &(Tok);
        return;
    }
}

Node* Parser::CreateNode(NodeType Type, Token *Tok)
{
    Node N;
    N.Type = Type;
    N.NodeToken = (Tok);
    NodesMade.push_back(N);
    NodeIndex++;
    return &NodesMade[NodeIndex-1];
}

Node* Parser::CreateNode()
{
    Node N;
    NodesMade.push_back(N);
    NodeIndex++;
    return &NodesMade[NodeIndex-1];
}

bool Parser::isTokenType(Token *node, std::vector<T_Type> TypeTest)
{
    for (auto Test : TypeTest){
        if (node->TokenType == Test) {
            return true;
        }
    }
    return false;
}

Node* Parser::factor()
{
    Token Tok = *(currentTokenObj);
    bool Check  = (isTokenType(currentTokenObj,{INT,FLOAT}));
    Node* CNode = CreateNode();
    if (Check) {
        Advance();
        CNode->Type = NUMBER;
        CNode->NodeToken = &(Tok);
    }
    return CNode;
}

Node *Parser::BinOp(ClassMethodPtr<Parser> Func, std::vector<T_Type> TypeTest)
{
    Node * Left = (this->*Func)();
    while (isTokenType(currentTokenObj,TypeTest))
    {
        Token Tok = *(currentTokenObj);
        Advance();
        Node* BinNode = CreateNode(BIN_OP,currentTokenObj);
        Node* Right = (this->*Func)();
        BinNode->Left = Left;
        BinNode->Right = Right;
        Left = BinNode;
        
    }
    return Left;
}
Node *Parser::term()
{
    Node *Ptr = BinOp(factor,{DIV,MUL});
    return Ptr;
}

Node *Parser::expr()
{
    return BinOp(term,{MINUS,PLUS});
}

void Parser::Parse()
{
    Node* Main = expr();
    Main->PrintData();
    
    
}

