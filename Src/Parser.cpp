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
        currentTokenObj = &(Tok);
        return;
    }
}

Node* Parser::CreateNode(NodeType Type, Token *Tok)
{
    NodeIndex++;
    Node &N = NodesMade[NodeIndex];
    N.Type = Type;
    N.NodeToken = (Tok);
    N.Nodeindex = NodeIndex;
    return &N;
}

Node* Parser::CreateNode()
{
    NodeIndex++;
    Node &N = NodesMade[NodeIndex];
    N.Nodeindex = NodeIndex;
    return &N;
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
    Token &Tok = *(currentTokenObj);
    bool Check  = (isTokenType(currentTokenObj,{INT,FLOAT}));
    Node* CNode = CreateNode();
    if (Check) {
        Advance();
        CNode->Type = NUMBER;
        CNode->NodeToken = &(Tok);
    }
    return CNode;
}

Node *Parser::BinOp(ClassMethodPtr<Parser,Node*> Func, std::vector<T_Type> TypeTest)
{
    Node * Left = (this->*Func)();
    while (isTokenType(currentTokenObj,TypeTest))
    {
        Token &Tok = *(currentTokenObj);
        Advance();
        Node* BinNode = CreateNode(BIN_OP,&Tok);
        Node* Right = (this->*Func)();
        BinNode->Left = Left;
        BinNode->Right = Right;
        Left = nullptr;
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
    std::cout << "Printing Tree \n";
    Main->PrintData();
    
    
}

