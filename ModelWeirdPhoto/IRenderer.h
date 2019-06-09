#pragma once

#include "opencv2/imgproc.hpp"

class IRenderer
{
public:
	using ViewImageFunc = std::function<void(cv::Mat& source)>;
	virtual void render() = 0;
};