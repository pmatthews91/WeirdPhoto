#include "ViewFunctionFactory.h"
#include "opencv2/highgui.hpp"
#include "opencv2/photo.hpp"

using namespace cv;

IRenderer::ViewImageFunc ViewFunctionFactory::make_view_func(RenderType renderType)
{
	IRenderer::ViewImageFunc view_func;

	if (renderType == RenderType::Edge_Preserve_Smoothing_Normalized_Convolution_Filter)
	{
		view_func = [](Mat& _sourceImage)
		{
			Mat img;
			edgePreservingFilter(_sourceImage, img, 1);
			imshow("Edge Preserve Smoothing Convolution Filter", img);
		};
	}

	if (renderType == RenderType::Edge_Preserve_Smoothing_Recursive_Filter)
	{
		view_func = [](Mat& _sourceImage)
		{
			Mat img;
			edgePreservingFilter(_sourceImage, img, 2);
			imshow("Edge Preserve Smoothing Recursive Filter", img);
		};
	}

	if (renderType == RenderType::Detail_Enhancement)
	{
		view_func = [](Mat& _sourceImage)
		{
			Mat img;
			detailEnhance(_sourceImage, img);
			imshow("Detail Enhanced", img);
		};
	}

	if (renderType == RenderType::Pencil_Sketch_Grey)
	{
		view_func = [](Mat& _sourceImage)
		{
			Mat img, img1;
			pencilSketch(_sourceImage, img1, img, 10, 0.1f, 0.03f);
			imshow("Pencil Sketch", img1);
		};
	}

	if (renderType == RenderType::Pencil_Sketch_Colour)
	{
		view_func = [](Mat& _sourceImage)
		{
			Mat img, img1;
			pencilSketch(_sourceImage, img1, img, 10, 0.1f, 0.03f);
			imshow("Color Pencil Sketch", img);
		};
	}

	if (renderType == RenderType::Stylization)
	{
		view_func = [](Mat& _sourceImage)
		{
			Mat img;
			stylization(_sourceImage, img);
			imshow("Stylization", img);
		};
	}

	return view_func;
}