#include "Lexer.h"
#include "Parser.h"
#include <iostream>

void Token::PrintToken()
{
	std::cout << "{ Val: '" << Data << "' Type: " << TokenType << " }";
}


void Node::PrintData()
{
    std::cout << "( ";
    if (Left != nullptr) {
        Left->PrintData();
    }
    std::cout << " , ";
    if (NodeToken != nullptr) {
        NodeToken->PrintToken();
    }
    std::cout << " , ";
    if (Right != nullptr) {
        Right->PrintData();
    }
    std::cout << " )";
}


void Error::getArrowString(int Length, int at)
{
    std::string Str = "";
    for (size_t i = 0; i <(Length-1); i++)
    {
        if (i == at) {
            Str += '^';
        } else {
            Str += '~';
        }
    }
    std::cout << Str << "\n";
     

}



void Error::printError(const char *Error, int at, const char *SourceLine, int Size)
{
    setErrorSwitch(true);
    std::cout << "\n:: Error at column: " << at << ". \n \n";
    std::cout << ">  " << SourceLine << "\n ";
    std::cout << "  ";
    getArrowString(Size,at);
    std::cout << "~  " << Error << "\n";
}
