#include "generate.h"
#include "ImageRenderer.h"
#include "RenderType.h"
#include "OpenFileException.h"
#include <memory>

using namespace std;

void generate(const char* filename, int renderType)
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
	
	renderer->render_image();
}