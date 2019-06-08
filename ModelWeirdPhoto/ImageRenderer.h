#pragma once

#include "IRenderer.h"
#include "RenderType.h"
#include "opencv2/imgproc.hpp"

class ImageRenderer : public IRenderer
{
public:
	ImageRenderer(const char* filename, RenderType renderType);
	void render() override;

private:
	void resize_image();

	RenderType m_renderType;
	cv::Mat m_sourceImage;
};