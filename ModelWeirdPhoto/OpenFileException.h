#pragma once

#include <exception>

class OpenFileException : std::exception
{
public:
	OpenFileException()
		: std::exception{ "File could not be opened" } {}
};