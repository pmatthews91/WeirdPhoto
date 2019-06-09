#include "VideoRenderer.h"
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include "OpenWebCamException.h"
#include "ViewFunctionFactory.h"

using namespace cv;

VideoRenderer::VideoRenderer(RenderType renderType)
	: m_video()
{
	// open the default camera using default API
	m_video.open(0);

	if (!m_video.isOpened())
	{
		throw OpenWebCamException{};
	}

	m_viewFunc = ViewFunctionFactory::make_view_func(renderType);
}

void VideoRenderer::render()
{
	Mat frame;
	
	for (;;)
	{
		// Wait for a new frame from camera and store it in 'frame'
		m_video.read(frame);

		// Check if we succeeded
		if (frame.empty()) {
			// Error - blank frame grabbed
			break;
		}
		// Show live
		m_viewFunc(frame);

		// Wait for a key with timeout long enough to show images
		if (waitKey(1000) >= 0)
			break;
	}
}