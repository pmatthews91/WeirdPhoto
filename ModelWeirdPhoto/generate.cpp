#include "generate.h"

void resize_image(Mat& src)
{
	auto screenWidth = (int)GetSystemMetrics(SM_CXSCREEN);
	auto screenHeight = (int)GetSystemMetrics(SM_CYSCREEN);

	int newWidth = src.cols;
	int newHeight = src.rows;

	if (src.cols > screenWidth)
	{
		newHeight = newHeight * screenWidth / newWidth;
		newWidth = screenWidth;
	}

	if (newHeight > screenHeight)
	{
		newWidth = newWidth * screenHeight / newHeight;
		newHeight = screenHeight;
	}

	resize(src, src, Size(newWidth, newHeight));
}