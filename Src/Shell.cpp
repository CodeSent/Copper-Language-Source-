#include "Lexer.h"


int main() {
	//std::cout << "Hello World!" << "\n";
	Error ErrorHandler;
	Lexer Lex;
	Lex.ErrorHandle = &ErrorHandler;
	Lex.SetSource(" = == + += - -= / /= * *= ^ ! < > <= >= != && || abcdef_ if else while for set i");
	Lex.EvalSource();

	std::cin.get();
	return 0;
}
