#include "ImageRenderer.h"
#include "opencv2/highgui.hpp"
#include "opencv2/photo.hpp"
#include "OpenFileException.h"
#include <windows.h>

using namespace cv;

ImageRenderer::ImageRenderer(const char* filename, RenderType renderType)
	: m_renderType(renderType), m_sourceImage(imread(filename, IMREAD_COLOR))
{
	if (m_sourceImage.empty())
	{
		throw OpenFileException{};
	}

	resize_image();
}

void ImageRenderer::render_image()
{
	Mat img;

	if (m_renderType == RenderType::Edge_Preserve_Smoothing_Normalized_Convolution_Filter)
	{
		edgePreservingFilter(m_sourceImage, img, 1);
		imshow("Edge Preserve Smoothing Convolution Filter", img);
	}

	if (m_renderType == RenderType::Edge_Preserve_Smoothing_Recursive_Filter)
	{
		edgePreservingFilter(m_sourceImage, img, 2);
		imshow("Edge Preserve Smoothing Recursive Filter", img);
	}

	if (m_renderType == RenderType::Detail_Enhancement)
	{
		detailEnhance(m_sourceImage, img);
		imshow("Detail Enhanced", img);
	}

	if (m_renderType == RenderType::Pencil_Sketch_Grey)
	{
		Mat img1;
		pencilSketch(m_sourceImage, img1, img, 10, 0.1f, 0.03f);
		imshow("Pencil Sketch", img1);
	}

	if (m_renderType == RenderType::Pencil_Sketch_Colour)
	{
		Mat img1;
		pencilSketch(m_sourceImage, img1, img, 10, 0.1f, 0.03f);
		imshow("Color Pencil Sketch", img);
	}

	if (m_renderType == RenderType::Stylization)
	{
		stylization(m_sourceImage, img);
		imshow("Stylization", img);
	}
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