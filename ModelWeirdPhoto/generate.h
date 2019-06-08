#pragma once

#include <string>
#include "opencv2/photo.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <windows.h>

using namespace cv;

enum class render_type
{
	Edge_Preserve_Smoothing_Normalized_Convolution_Filter,
	Edge_Preserve_Smoothing_Recursive_Filter,
	Detail_Enhancement,
	Pencil_Sketch_Grey,
	Pencil_Sketch_Colour,
	Stylization
};

void resize_image(Mat& src);

extern "C" _declspec(dllexport) void generate(const char* filename, int renderType)
{
	render_type renderTypeEnum = static_cast<render_type>(renderType);
	Mat src = imread(filename, IMREAD_COLOR);

	if (src.empty())
	{
		// Could not find image
		return;
	}

	resize_image(src);

	namedWindow("Display frame", WINDOW_NORMAL);
	Mat img;

	if (renderTypeEnum == render_type::Edge_Preserve_Smoothing_Normalized_Convolution_Filter)
	{
		edgePreservingFilter(src, img, 1);
		imshow("Edge Preserve Smoothing Convolution Filter", img);
	}

	if (renderTypeEnum == render_type::Edge_Preserve_Smoothing_Recursive_Filter)
	{
		edgePreservingFilter(src, img, 2);
		imshow("Edge Preserve Smoothing Recursive Filter", img);
	}

	if (renderTypeEnum == render_type::Detail_Enhancement)
	{
		detailEnhance(src, img);
		imshow("Detail Enhanced", img);
	}

	if (renderTypeEnum == render_type::Pencil_Sketch_Grey)
	{
		Mat img1;
		pencilSketch(src, img1, img, 10, 0.1f, 0.03f);
		imshow("Pencil Sketch", img1);
	}

	if (renderTypeEnum == render_type::Pencil_Sketch_Colour)
	{
		Mat img1;
		pencilSketch(src, img1, img, 10, 0.1f, 0.03f);
		imshow("Color Pencil Sketch", img);
	}

	if(renderTypeEnum == render_type::Stylization)
	{
		stylization(src, img);
		imshow("Stylization", img);
	}
}