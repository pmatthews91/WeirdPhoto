#include "generate.h"
#include "ImageRenderer.h"
#include "RenderType.h"

void generate(const char* filename, int renderType)
{
	RenderType renderTypeEnum = static_cast<RenderType>(renderType);

	ImageRenderer renderer{ filename, renderTypeEnum };
	renderer.render_image();
}