#pragma once

#include "IRenderer.h"
#include "RenderType.h"

class ImageRenderer : public IRenderer
{
public:
	ImageRenderer(const char* filename, RenderType renderType);
	void render() override;

private:
	void resize_image();

	ViewImageFunc m_viewFunc;
	cv::Mat m_sourceImage;
};