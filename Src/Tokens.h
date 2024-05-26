#pragma once
#include <string>

using std::string;

enum Type {
	// Misc
	NULL_T,
	EOF_T,
	IDENTIFIER,
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

	// Logical Oparators
	EQUALS,
	LESS,
	MORE,
	NOT,
	LESS_EQ,
	MORE_EQ,
	NOT_EQ,
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
	void set(Type TT);
	void set(Type TT, string D);
	void PrintToken();
};
