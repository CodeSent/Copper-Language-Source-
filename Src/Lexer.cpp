#include "Lexer.h"
#include "TextUlit.h"
#include "Keywords.h"

#include <iostream>




#define CM(C,T) int(C) == int(T)



void Lexer::SetSource(string Src)
{
	Source = Src; 
	Length = Source.size();
	PositionalIndex = 0;
	CurrentChar = Source[PositionalIndex];
}

void Lexer::Step()
{
	PositionalIndex++;
	CurrentChar = (Length >= PositionalIndex ? Source[PositionalIndex] : ' ');
}





// Everything is hard coded here...

GenaratedTokens Lexer::EvalSource()
{
	
	GenaratedTokens TokensGenarated;
	
	while (Length > PositionalIndex and (*ErrorHandle).getErrorState())
	{
		Token CurrentToken;
		CurrentToken.Data = ' ';
		if (TextUtilities::isWhitespace(CurrentChar)) {
			Step();
			continue;
		}

		CurrentToken.Data = CurrentChar;

		// Number Evaluator
		if (TextUtilities::isNumber(CurrentChar)) {
			EvalNumber(CurrentToken);
			TokensGenarated.push_back(CurrentToken);
			continue;
		}
		// Text Evaluator
		else if (TextUtilities::isAlphabet(CurrentChar)) {
			EvalSentence(CurrentToken);
			TokensGenarated.push_back(CurrentToken);
			continue;
		}

		// Symbol Evaluator

		// + , +=
		else if(CM(CurrentChar,'+')) {
			CurrentToken.TokenType = PLUS;
			// +=
			if (CM(GetCharacterByoffset(1), '=')) {
				Step();
				CurrentToken.TokenType = EQUAL_ADD;
				CurrentToken.Data += CurrentChar;
			}
		}
		// - , -=
		else if (CM(CurrentChar, '-')) {
			CurrentToken.TokenType = MINUS;

			// -=
			if ( CM(GetCharacterByoffset(1), '=')) {
				Step();
				CurrentToken.TokenType = EQUAL_SUB;
				CurrentToken.Data += CurrentChar;
			}
		}
		// / , /=
		else if (CM(CurrentChar, '/')) {
			CurrentToken.TokenType = DIV;

			// /=
			if (CM(GetCharacterByoffset(1), '=')) {
				Step();
				CurrentToken.TokenType = EQUAL_DIV;
				CurrentToken.Data += CurrentChar;
			}
		}
		// * , *=
		else if (CM(CurrentChar, '*')) {
			CurrentToken.TokenType = MUL;

			// *=
			if (CM(GetCharacterByoffset(1), '=')) {
				Step();
				CurrentToken.TokenType = EQUAL_MUL;
				CurrentToken.Data += CurrentChar;
			}
		}
		// ^
		else if (CM(CurrentChar, '^')) {
			CurrentToken.TokenType = POW;
		}
		// = , ==
		else if (CM(CurrentChar, '=')) {
			CurrentToken.TokenType = EQUAL;
			
			// ==
			if (CM(GetCharacterByoffset(1), '=')) {
				Step();
				CurrentToken.TokenType = EQUALS;
				CurrentToken.Data += CurrentChar;
			}
			
		}
		// < , <=
		else if (CM(CurrentChar, '<')) {
			CurrentToken.TokenType = LESS;

			// <=
			if (CM(GetCharacterByoffset(1), '=')) {
				Step();
				CurrentToken.TokenType = LESS_EQ;
				CurrentToken.Data += CurrentChar;
			}

		}
		// > , >=
		else if (CM(CurrentChar, '>')) {
			CurrentToken.TokenType = MORE;

			// <=
			if (CM(GetCharacterByoffset(1), '=')) {
				Step();
				CurrentToken.TokenType = MORE_EQ;
				CurrentToken.Data += CurrentChar;
			}

		}
		// ! , !=
		else if (CM(CurrentChar, '!')) {
			CurrentToken.TokenType = NOT;

			// !=
			if (CM(GetCharacterByoffset(1), '=')) {
				Step();
				CurrentToken.TokenType = NOT_EQ;
				CurrentToken.Data += CurrentChar;
			}
		}
		// (
		else if (CM(CurrentChar, '(')) {
			CurrentToken.TokenType = PAREN_L;
		}
		// )
		else if (CM(CurrentChar, ')')) {
			CurrentToken.TokenType = PAREN_R;
		}
		// ;
		else if (CM(CurrentChar, ';')) {
			CurrentToken.TokenType = SEMI_COLON;
		}
		// OR (||)
		else if (CM(CurrentChar, '|')) {
			if (CM(GetCharacterByoffset(1), '|')) {
				Step();
				CurrentToken.TokenType = OR;
				CurrentToken.Data += CurrentChar;
			} else {
				Step();
				continue;
			}
		}
		// AND (&&)
		else if (CM(CurrentChar, '&')) {
			if (CM(GetCharacterByoffset(1), '&')) {
				Step();
				CurrentToken.TokenType = AND;
				CurrentToken.Data += CurrentChar;
			} else {
				Step();
				continue;
			}

		} else {
			TokensGenarated.clear();
			(*ErrorHandle).printError("Unrecognised (Illegal) Character." ,PositionalIndex,Source.c_str(),Length);
			continue;
		}
		
		if (CurrentToken.TokenType != NULL_T) TokensGenarated.push_back(CurrentToken);
		Step();
	}
	
	return TokensGenarated;
}



void Lexer::EvalSentence(Token & Target)
{
	Target.TokenType = IDENTIFIER;
	Target.Data = "";
	while (TextUtilities::isAcceptableIdentiferSymbol(CurrentChar))
	{
		Target.Data +=  CurrentChar;
		Step();
	}

	ResolveKeyword(Target);
}

void Lexer::ResolveKeyword(Token & Target)
{
	if (Target.Data == ReservedKeywords.IF) {
		Target.TokenType = IF;
	}
	else if (Target.Data == ReservedKeywords.ELSE) {
		Target.TokenType = ELSE;
	}
	else if (Target.Data == ReservedKeywords.WHILE) {
		Target.TokenType = WHILE;
	}
	else if (Target.Data == ReservedKeywords.FOR) {
		Target.TokenType = FOR;
	}
	else if (Target.Data == ReservedKeywords.SET) {
		Target.TokenType = VAR_DEC;
	}
}

void Lexer::EvalNumber(Token &Eval)
{
	//Token TokenMade;
	Eval.TokenType = INT;
	int DC = 0;

	Eval.Data = "";
	while ( TextUtilities::isNumber(CurrentChar) or TextUtilities::isPeriod(CurrentChar))
	{
		Eval.Data +=  CurrentChar;
		
		if (TextUtilities::isPeriod(CurrentChar)) {
			Eval.TokenType = FLOAT;
			DC++;
			if (DC > 1) {
				break;
			}
		}
		Step();
		
	}
	//return TokenMade;
}

char Lexer::GetCharacterByoffset(int Offset)
{
		if ((PositionalIndex + Offset) > 0 and Length > (PositionalIndex + Offset))
		{
			return Source[PositionalIndex + Offset];
		}
		else 
		{
			return ' ';
		}
	
}
