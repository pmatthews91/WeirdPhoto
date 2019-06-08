#pragma once

#include <exception>

class OpenWebCamException : std::exception
{
public:
	OpenWebCamException()
		: std::exception{ "Webcam could not be opened" } {}
};