#pragma once

#include <string>
#include "opencv2/photo.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

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

extern "C" _declspec(dllexport) void generate(const char* filename)
{
	render_type renderType = render_type::Stylization;
	Mat src = imread(filename, IMREAD_COLOR);

	if (src.empty())
	{
		// Could not find image
		return;
	}

	resize(src, src, Size(src.cols / 2, src.rows / 2));
	namedWindow("Display frame", WINDOW_NORMAL);
	Mat img;

	if (renderType == render_type::Edge_Preserve_Smoothing_Normalized_Convolution_Filter)
	{
		edgePreservingFilter(src, img, 1);
		imshow("Edge Preserve Smoothing Convolution Filter", img);
	}

	if (renderType == render_type::Edge_Preserve_Smoothing_Recursive_Filter)
	{
		edgePreservingFilter(src, img, 2);
		imshow("Edge Preserve Smoothing Recursive Filter", img);
	}

	if (renderType == render_type::Detail_Enhancement)
	{
		detailEnhance(src, img);
		imshow("Detail Enhanced", img);
	}

	if (renderType == render_type::Pencil_Sketch_Grey)
	{
		Mat img1;
		pencilSketch(src, img1, img, 10, 0.1f, 0.03f);
		imshow("Pencil Sketch", img1);
	}

	if (renderType == render_type::Pencil_Sketch_Colour)
	{
		Mat img1;
		pencilSketch(src, img1, img, 10, 0.1f, 0.03f);
		imshow("Color Pencil Sketch", img);
	}

	if(renderType == render_type::Stylization)
	{
		stylization(src, img);
		imshow("Stylization", img);
	}
}