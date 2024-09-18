#pragma once
#include <vector>
#include <string>
using std::string;





enum TokenType {
	// Misc
	NULL_T,          //1
	EOF_T,           //2
	IDENTIFIER,      //3

	//Punchuator
	SEMI_COLON,      //4
	PAREN_L,         //5
	PAREN_R,         //6

	// Arithmatic Oparators
	PLUS,            //7
	MINUS,           //8
	MUL,             //9
	DIV,             //10
	POW,             //11

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
	VAR_DEC,

};

using T_Type = TokenType;
struct Token {
	string Data = "";
	TokenType TokenType = NULL_T;
	void PrintToken();
};

using  GenaratedTokens = std::vector<Token>;