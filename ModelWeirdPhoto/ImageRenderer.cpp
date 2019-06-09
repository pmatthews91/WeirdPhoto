#include "ImageRenderer.h"
#include "opencv2/highgui.hpp"
#include "opencv2/photo.hpp"
#include "OpenFileException.h"
#include "ViewFunctionFactory.h"
#include <windows.h>

using namespace cv;

ImageRenderer::ImageRenderer(const char* filename, RenderType renderType)
	: m_sourceImage(imread(filename, IMREAD_COLOR))
{
	if (m_sourceImage.empty())
	{
		throw OpenFileException{};
	}

	m_viewFunc = ViewFunctionFactory::make_view_func(renderType);

	resize_image();
}

void ImageRenderer::render()
{
	m_viewFunc(m_sourceImage);
}

void ImageRenderer::resize_image()
{
	auto screenWidth = (int)GetSystemMetrics(SM_CXSCREEN);
	auto screenHeight = (int)GetSystemMetrics(SM_CYSCREEN);

	int newWidth = m_sourceImage.cols;
	int newHeight = m_sourceImage.rows;

	if (m_sourceImage.cols > screenWidth)
	{
		newHeight = newHeight * screenWidth / newWidth;
		newWidth = screenWidth;
	}

	if (newHeight > screenHeight)
	{
		newWidth = newWidth * screenHeight / newHeight;
		newHeight = screenHeight;
	}

	resize(m_sourceImage, m_sourceImage, Size(newWidth, newHeight));
}