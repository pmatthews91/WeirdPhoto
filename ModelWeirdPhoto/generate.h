#pragma once

#include <string>
#include "opencv2/photo.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;

extern "C" _declspec(dllexport) void generate(const char* filename) // unsigned char* dst, int dimension, char* filename
{
	int num = 1;
	int type = 1;
	Mat src = imread(filename, IMREAD_COLOR);

	if (src.empty())
	{
		//cout << "Could not open or find the image!\n" << endl;
		//cout << "Usage: " << argv[0] << " <Input image>" << endl;
		return;
	}

	/*cout << endl;
	cout << " Edge Preserve Filter" << endl;
	cout << "----------------------" << endl;

	cout << "Options: " << endl;
	cout << endl;

	cout << "1) Edge Preserve Smoothing" << endl;
	cout << "   -> Using Normalized convolution Filter" << endl;
	cout << "   -> Using Recursive Filter" << endl;
	cout << "2) Detail Enhancement" << endl;
	cout << "3) Pencil sketch/Color Pencil Drawing" << endl;
	cout << "4) Stylization" << endl;
	cout << endl;*/

	Mat img;

	if (num == 1)
	{
		//cout << "Press 1 for Normalized Convolution Filter and 2 for Recursive Filter: ";

		edgePreservingFilter(src, img, type);
		imshow("Edge Preserve Smoothing", img);

	}
	else if (num == 2)
	{
		detailEnhance(src, img);
		imshow("Detail Enhanced", img);
	}
	else if (num == 3)
	{
		Mat img1;
		pencilSketch(src, img1, img, 10, 0.1f, 0.03f);
		imshow("Pencil Sketch", img1);
		imshow("Color Pencil Sketch", img);
	}
	else if (num == 4)
	{
		stylization(src, img);
		imshow("Stylization", img);
	}
}