#pragma once

#include "RenderType.h"
#include "opencv2/imgproc.hpp"

class ImageRenderer
{
public:
	ImageRenderer(const char* filename, RenderType renderType);
	void render_image();

private:
	void resize_image();

	RenderType m_renderType;
	cv::Mat m_sourceImage;
};