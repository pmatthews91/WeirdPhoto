#include "VideoRenderer.h"
#include <opencv2/core.hpp>

#include <opencv2/videoio.hpp>
#include "OpenWebCamException.h"

using namespace cv;

VideoRenderer::VideoRenderer(RenderType renderType)
	: m_renderType(renderType), m_video()
{
	// open the default camera using default API
	m_video.open(0);

	if (!m_video.isOpened())
	{
		throw OpenWebCamException{};
	}
}

void VideoRenderer::render()
{
	Mat frame;
	
	for (;;)
	{
		// wait for a new frame from camera and store it into 'frame'
		m_video.read(frame);

		// check if we succeeded
		if (frame.empty()) {
			// Error - blank frame grabbed
			break;
		}
		// show live and wait for a key with timeout long enough to show images
		imshow("Live", frame);
		if (waitKey(1000) >= 0)
			break;
	}
}