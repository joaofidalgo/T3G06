#pragma once

#include <string>

enum ProgramType {
	ENTERTAINMENT,
	LIFE_STYLE,
	MOVIE,
	NEWS,
	SPORTS
};

std::string ToLower(std::string str);
int FormatName(std::string& str);
std::string getProgramTypeString(ProgramType type);
