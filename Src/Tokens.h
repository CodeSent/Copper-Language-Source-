#pragma once
#include <vector>
#include <string>
using std::string;





enum Type {
	// Misc
	NULL_T,
	EOF_T,
	IDENTIFIER,

	//Punchuator
	SEMI_COLON,
	PAREN_L,
	PAREN_R,

	// Arithmatic Oparators
	PLUS,
	MINUS,
	MUL,
	DIV,
	POW,

	// Assignment Oparators
	EQUAL, 
	EQUAL_ADD,
	EQUAL_SUB,
	EQUAL_MUL,
	EQUAL_DIV,

	// Relational Oparators
	EQUALS,
	LESS,
	MORE,
	LESS_EQ,
	MORE_EQ,
	NOT_EQ,

	// Logical Oparators
	NOT,
	OR,
	AND,
	

	//Types
	INT,
	FLOAT,
	BOOL,
	
	//Keywords
	IF,
	ELSE,
	WHILE,
	FOR,
	VAR_DEC
	
};


struct Token {
	string Data = "";
	Type TokenType = NULL_T;
	void PrintToken();
};

using  GenaratedTokens = std::vector<Token>;