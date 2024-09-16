#include "Lexer.h"
#include "Parser.h"
#include <iostream>



int main() {
	//std::cout << "Hello World!" << "\n";

	std::string Source;
	std::cout << ">>>";
	std::cin >> Source;
	Error ErrorHandler;
	Lexer Lex;
	Parser Par;
	Lex.ErrorHandle = &ErrorHandler;
	Lex.SetSource("4 + 5 + 10 + 10000 + 9");
	GenaratedTokens lexOutput = Lex.EvalSource();

	if (!ErrorHandler.getErrorState()) {return 0;}
	for (auto& CurrentToken : lexOutput) {
		
		//std::cout << (&(lexOutput[i])== &CurrentToken) << "\n";
		CurrentToken.PrintToken();
		std::cout << " \n";
		//i++;
	}
	std::cout << lexOutput.size() << "\n";
	Par.SetTarget(lexOutput);
	Par.Parse();

	std::cin.get();
	return 0;
}
