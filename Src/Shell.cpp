#include "Lexer.h"
#include "Parser.h"
#include <iostream>



int main() {
	//std::cout << "Hello World!" << "\n";
	Error ErrorHandler;
	Lexer Lex;
	Parser Par;
	Lex.ErrorHandle = &ErrorHandler;
	Lex.SetSource("4 + 5 + 10");
	GenaratedTokens lexOutput = Lex.EvalSource();

	if (!ErrorHandler.getErrorState()) {return 0;}

	Par.SetTarget(lexOutput);
	

	for (auto& CurrentToken : lexOutput) {
		
		//std::cout << (&(lexOutput[i])== &CurrentToken) << "\n";
		CurrentToken.PrintToken();
		//i++;
	}
	Par.Parse();
	std::cin.get();
	return 0;
}
