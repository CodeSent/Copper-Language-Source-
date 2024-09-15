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
    (Tok)->PrintToken();
    std::cout << "Node made " << NodeIndex << "\n";
    return &NodesMade[NodeIndex-1];
}

Node* Parser::CreateNode()
{
    Node N;
    NodesMade.push_back(N);
    NodeIndex++;
    std::cout << "Node made " << NodeIndex << "\n";
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
    bool Check  = (Tok.TokenType == INT or Tok.TokenType == FLOAT);
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
        Node* BinNode = CreateNode(BIN_OP,&Tok);
        Node* Right = (this->*Func)();
        BinNode->Left = Left;
        BinNode->Right = Right;
        Left = BinNode;
        
    }
    return Left;
}
Node *Parser::term()
{
    std::cout << "Testing terms" << "\n";
    Node *Ptr = BinOp(factor,{DIV,MUL});
    std::cout << "Exiting terms" << "\n \n";
    return Ptr;
}

Node *Parser::expr()
{
    std::cout << "Testing expressions" << "\n";
    return BinOp(term,{MINUS,PLUS});
}

void Parser::Parse()
{
    expr();
    for (auto I : NodesMade)
    {
        std::cout << "{ " << I.Type << ":" << I.Left << "," <<  I.Right << "," << &I << "}" << "\n";
    }
    
}

