#pragma once
#include <iostream>
#include <vector>
#include "Tokens.h"
#include "Error.h"



class Lexer
{
	string Source;
	int Length;
	int PositionalIndex;
	char CurrentChar;
	void EvalSentence(Token &Target);
	void ResolveKeyword(Token &Target);
	void EvalNumber(Token &Target);
	char GetCharacterByoffset(int Offset);
public:
	Error* ErrorHandle;
	std::vector<Token> EvalSource();
	void Step();
	void SetSource(string Src);
};

