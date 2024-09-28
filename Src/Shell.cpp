#include "Lexer.h"
#include "Parser.h"
#include <iostream>



int main() {
	//std::cout << "Hello World!" << "\n";

	std::string Source;
	Error ErrorHandler;
	Lexer Lex;
	Parser Par;
	Lex.ErrorHandle = &ErrorHandler;
	Lex.SetSource("10 /10 + 80 * 40 + 9 + 0 + 675");
	GenaratedTokens lexOutput = Lex.EvalSource();

	if (!ErrorHandler.getErrorState()) {return 0;}
	Token EOFToken;
	EOFToken.TokenType = EOF_T;
	EOFToken.Data = ' ';
	lexOutput.push_back(EOFToken);

	for (auto& CurrentToken : lexOutput) {
		
		//std::cout << (&(lexOutput[i])== &CurrentToken) << "\n";
		//CurrentToken.PrintToken();
		//std::cout << " \n";
		//i++;
	}
	std::cout << lexOutput.size() << "\n";
	Par.SetTarget(lexOutput);
	Par.Parse();

	std::cin.get();
	return 0;
}
