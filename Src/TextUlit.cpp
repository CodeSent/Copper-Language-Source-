#include "TextUlit.h"


constexpr char ALPHAB[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr char NUMBER[] = "0123456789";
constexpr char APTSYM[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_@$";


bool TextUtilities::isWhitespace(char C)
{
	return (int(C) == int(' ') or int(C)== int('\t'));
}

bool TextUtilities::isAlphabet(char C)
{
	bool T = false;
	for (auto& I : ALPHAB) {
		T = (int(C) == int(I));
		if (T) break;
	}
	return T;
}

bool TextUtilities::isNumber(char C)
{
	bool T = false;
	for (auto& I : NUMBER) {
		T = (int(C) == int(I));
		if (T) break;
	}
	return T;
}

bool TextUtilities::isPeriod(char C)
{
	return (int(C) == int('.'));
}

bool TextUtilities::isAcceptableIdentiferSymbol(char C)
{
    bool T = false;
	for (auto& I : APTSYM) {
		T = (int(C) == int(I));
		if (T) break;
	}
	return T;
}
