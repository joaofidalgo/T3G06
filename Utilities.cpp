#include "Utilities.h"

#include <ctype.h>

std::string ToLower(std::string str)
{
	for (unsigned int i = 0; i < str.length(); ++i)
		str[i] = tolower(str[i]);

	return str;
}

int FormatName(std::string& str)
{
	str[0] = toupper(str[0]);
	for (unsigned int i = 1; i < str.length(); ++i)
		str[i] = tolower(str[i]);

	return 0;
}

std::string getProgramTypeString(ProgramType type) {
	switch (type)
	{
	case MOVIE:
		return "Movie";
	case NEWS:
		return "News";
	case SPORTS:
		return "Sports";
	case ENTERTAINMENT:
		return "Entertainment";
	case LIFE_STYLE:
		return "Life Style";
	default:
		return "NULL";
	}
}
