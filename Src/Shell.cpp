#include "Lexer.h"


int main() {
	//std::cout << "Hello World!" << "\n";
	Lexer Lex;
	Lex.SetSource(" = == + += - -= / /= * *= ^ ! < > <= >= != && || abcdef_ if else while for set if");
	Lex.EvalSource();

	std::cin.get();
	return 0;
}
