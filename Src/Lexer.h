#pragma once
#include <iostream>
#include <vector>
#include "Tokens.h"



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
	std::vector<Token> EvalSource();
	void Step();
	void SetSource(string Src);
};

