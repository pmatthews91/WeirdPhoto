#include "generate.h"
#include "ImageRenderer.h"
#include "VideoRenderer.h"
#include "RenderType.h"
#include "OpenFileException.h"
#include "OpenWebCamException.h"
#include <memory>

using namespace std;

void generate_image(const char* filename, int renderType)
{
	RenderType renderTypeEnum = static_cast<RenderType>(renderType);
	unique_ptr<ImageRenderer> renderer;

	try
	{
		renderer = make_unique<ImageRenderer>( filename, renderTypeEnum );
	}
	catch ([[maybe_unused]] OpenFileException& ex)
	{
		return;
	}
	
	renderer->render();
}

void generate_video(int renderType)
{
	RenderType renderTypeEnum = static_cast<RenderType>(renderType);
	std::unique_ptr<VideoRenderer> renderer;

	try
	{
		renderer = make_unique<VideoRenderer>(renderTypeEnum);
	}
	catch ([[maybe_unused]] OpenWebCamException& ex)
	{
		return;
	}

	renderer->render();
}