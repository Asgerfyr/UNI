#include "Util.h"
#include <cctype>

char toLower(char c)
{
	return static_cast<char>(tolower(c));
}

char toUpper(char c)
{
	return static_cast<char>(toupper(c));
}
