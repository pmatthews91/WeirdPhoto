#pragma once

#include "IRenderer.h"
#include "RenderType.h"
#include <opencv2/highgui.hpp>

class VideoRenderer : public IRenderer
{
public:
	VideoRenderer(RenderType renderType);
	void render() override;

private:
	ViewImageFunc m_viewFunc;
	cv::VideoCapture m_video;
	int m_waitTime = 100;
};