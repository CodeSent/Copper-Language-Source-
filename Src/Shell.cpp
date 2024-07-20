#include "Lexer.h"
#include <iostream>



int main() {
	//std::cout << "Hello World!" << "\n";
	Error ErrorHandler;
	Lexer Lex;
	Lex.ErrorHandle = &ErrorHandler;
	Lex.SetSource("4 + (5 * 10);");
	GenaratedTokens lexOutput = Lex.EvalSource();
	//int i = 0;
	for (auto& CurrentToken : lexOutput) {
		
		//std::cout << (&(lexOutput[i])== &CurrentToken) << "\n";
		CurrentToken.PrintToken();
		//i++;
	}
	std::cin.get();
	return 0;
}
